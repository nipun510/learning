from abc import ABC, abstractmethod
from datetime import datetime
from datetime import timedelta
import random

class CircuitBreaker:
  def __init__(self, fn, err_msg, failure_threshold, retry_timeperiod):
    
    self.open = Open(self)
    self.closed = Closed(self)
    self.half_open = HalfOpen(self)
    self.fn = fn
    self.err_msg = err_msg
    self.failure_threshold = failure_threshold
    self.retry_timeperiod = retry_timeperiod
    self.failure_count = 0
    self.last_failure_time = None

  def execute(self):
    self.set()
    self.state.execute()

  def record_failure(self):
    self.failure_count += 1
    self.last_failure_time = datetime.now()

  def retry_timeperiod_elapsed(self):
    return datetime.now() - self.last_failure_time >= self.retry_timeperiod
    

  def failure_threshold_breached(self):
    return self.failure_count > self.failure_threshold

  def set(self):
    if self.failure_threshold_breached():
      if self.retry_timeperiod_elapsed():
        self.state = self.half_open
      else:
        self.state = self.open
    else:
      self.state = self.closed
    
  def reset(self):
    self.failure_count = 0
    self.last_failure_time = None

class CircuitState(ABC):
  @abstractmethod
  def execute():
    pass

class Open(CircuitState):
  def __init__(self, circuit_breaker):
    self.circuit_breaker = circuit_breaker
  def execute(self):
    print("OPEN:", self.circuit_breaker.err_msg)

class Closed(CircuitState):
  def __init__(self, circuit_breaker):
    self.circuit_breaker = circuit_breaker
  def execute(self):
    if self.circuit_breaker.fn():
      print("CLOSED::SUCCESS")
      self.circuit_breaker.reset()
    else:
      print("CLOSED::FAILURE")
      self.circuit_breaker.record_failure()
      if self.circuit_breaker.failure_threshold_breached():
        self.circuit_breaker.state = self.circuit_breaker.open


class HalfOpen(CircuitState):
  def __init__(self, circuit_breaker):
    self.circuit_breaker = circuit_breaker
  def execute(self):
    if self.circuit_breaker.fn():
      print("HALFOPEN:SUCCESS")
      self.circuit_breaker.reset()
    else:
      print("HALFOPEN:FAILURE")
      self.circuit_breaker.record_failure()


def fun():
  val = random.randint(0,10)
  if val < 8:
    return False
  else:
    return True

if __name__ == '__main__':
  print("___START_______")
  cb = CircuitBreaker(fun, "network not responsive", 2, timedelta(milliseconds=2))
  for _ in range(0, 100):
    cb.execute()

  print("____END_________")

