

class decorator:
	def __init__(self, fun1):
		self.fun1 = fun1

	def setter(self, fun2):
		def wrapper(instance_param, fun_param):
			fun2(instance_param, fun_param)
			print("extra things done")
		return wrapper

	def __call__(self):
		print("decorator object called")



class base:
	@decorator
	def method1(self):
		print("method1")

	@method1.setter
	def method2(self, fun_param):
		print("method2")


if __name__ == '__main__':
	b = base()
	b.method1()
	b.method2("hi");