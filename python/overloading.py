def fun():
	print("No arguments")


def fun(a):
	print("1 argument")

#No overloading as there is concept of name and object binding in python.

if __name__ == '__main__':
	fun()
	#fun(12)