

def decorator(arg1, arg2):
	def wrapper1(fun):
		print("wrapper 1")
		def wrapper2():
			print("wrapper 2")
			fun()
		return wrapper2
	return wrapper1


print("Before decorator")


#fun = wrapper(fun)
@decorator(12,23) 
def fun():
	print("fun")

print("Before main")

if __name__ == '__main__':
	fun()
	print("completed")