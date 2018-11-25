
class A:
	"""Hello this Class A docstring"""
	pass

class B:
	data = 32
	def __init__(self):
		self.a = 10
		self.__b = 12

	def __private(self):
		pass
	def fun(self):
		print(B.data) #class attribue access
		pass

if __name__ == '__main__':
	A.name = 'Nipun'  # 'name' class attribute added
	a = A()
	a.name = 'Bipul'   #just instance 'name' attribute overidden not class attribute
	a.age = 60

	print(A.name)
	print(a.name)


	help(A) #prints docstr

	b = B()
	print(list(b.__dict__.keys())) #prints just  attribues attached to namespace object
	print(list(B.__dict__.keys()))
	print(dir(b))                  # prints instance as well as all the inherited attributes
	
	print(b.__class__)
	print(B.__name__)
	print(B.__bases__)

	for key in b.__dict__:
		print(getattr(b, key))



