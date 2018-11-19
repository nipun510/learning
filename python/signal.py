

import signal
import os
import sys
import time
import os

pid = os.getpid()
received = False

def receive_signal(param1, param2):
	"callback invoked by signal handler"
	global received
	received = True
	sys.stdout.flush()
	print("child process {0} received signal".format(pid))
	sys.stdout.flush()


def set_signal_handler():
	sys.stdout.flush()
	signal.signal(signal.SIGUSR1, receive_signal)
	signal.signal(signal.SIGUSR1, receive_signal)
	sys.stdout.flush()
	time.sleep(3)
	if not received:
		print("process {0} didn't receive any signal".format(pid))
	sys.stdout.flush()

#print(os.path.abspath())

if __name__ == '__main__':
	set_signal_handler()	
