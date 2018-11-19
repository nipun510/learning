

def fun():
	print("Independent fun functions")

class A (type):
	def __new__(meta, classname, supers, classdict):
		return type.__new__(meta, classname, supers, classdict)
	def __init__(meta, classname, supers, classdict):
		print("meta init")
		fun()
		classdict['fun'] = fun #overriding class fun attribute


class C(metaclass=A):
	def fun(self):
		print("C fun")


if __name__ == '__main__':
	b = C()
	b.fun()
	