
class classdecorator:
	def __init__(self, func):
		self.fun = func
		pass
	def __call__(self):
		self.fun() #able to call this because fun  is not a bounded method


def decorator(fun):
	def wrapper(param1, param2):#here param1 is for passing self to fun
		print(param2)
		fun(param1) #param1 is self for method
	return wrapper



class base:
	def __init__(self):
		pass
	@classdecorator    # fun = classdecorator(fun) fun becomes an object of classdecorator then
	def fun():
		print("fun called")

	def fun1():
		print("fun1 called")
	@decorator          #fun2 = decorator(fun2)
	def fun2(self):
		print("fun2 called")

if __name__ == '__main__':
	b = base()
	b.fun2('param2')

	b.fun();
	 