
class A:
	def __init__(self):
		self.data = [12,3434,45,45,67]
		print("init")

	def __getitem__(self, index):
		if isinstance(index, int):
			#print("type=>" , type(index))
			return self.data[index]
		else:
			#rint("type=>" , type(index))
			return self.data[index.start:index.end] #for slicing

	def __setitem__(self, index, value):
		self.data[index] = value

	def __contains__(self, x): # Preferred for 'in'
		print('contains: ', end='')
		return x in self.data


if __name__ == '__main__':
	a = A()
	print(a[1])
	a[1] = 10
	print(a[1])
#the for statement works by repeatedly indexing a sequence from zero to higher indexes,
#until an out-of-bounds IndexError exception is detected
#though __iter__ is preffered for iteration.

# Any class that supports for loops automatically supports all iteration contexts in Python,
	for val in a:
		print(val)

	#print(a)