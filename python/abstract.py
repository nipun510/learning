
from abc import ABCMeta, abstractmethod


class A(metaclass=ABCMeta):
	def __init__(self):
		pass

	@abstractmethod
	def method(self):
		self.action()


class B(A):
	def __init__(self):
		pass
		
	def action(self):
		print("action taken")


if __name__ == '__main__':
	b = B()
	b.method()

	#a = A()  #Can't instantiate abstract class B with abstract methods method
	