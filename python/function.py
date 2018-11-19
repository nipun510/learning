#if you print the type
#of an instance-less class-level method, it displays “unbound method” in 2.X, and
#“function” in 3.X.

class A:
	def __init__(self):
		self.a = 3

	def fun(self):
		print(self.a)

	def selfless(a, b):
		print(a, b)

#Unbound (class) method objects: no self
#Bound (instance) method objects: self + function pairs
if __name__ == '__main__':
	a = A()
	a.fun()
	fun2 = a.fun#Bound methods
	fun3 = A.fun(a)#Unbound methods
	fun2()
	A.unboundfun2(23,23) # Doesn't take self
