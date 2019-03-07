#__iter__ is preferred over __getitem__ for iteration

#jteration contexts work by passing an iterable object to the iter built-in
#function to invoke an __iter__ method, which is expected to return an iterator object.
#If it’s provided, Python then repeatedly calls this iterator object’s __next__ method to
#produce items until a StopIteration exception is raised


class Squares:
	def __init__(self, start, stop): # Save state when created
		self.value = start - 1
		self.stop = stop
	def __iter__(self): # Get iterator object on iter
		return self
	def __next__(self): # Return a square on each iteration
		if self.value == self.stop: # Also called by next built-in
			raise StopIteration
		self.value += 1
		return self.value ** 2
class Value:
	def __init__(self): # Save state when created
		self.data = [23,34,45,4565,56]
	def __iter__(self): # Get iterator object on iter
		self.x = 0
		return self
	def __next__(self): # Return a square on each iteration
		if self.x == len(self.data): # Also called by next built-in
			raise StopIteration
		val = self.data[self.x]
		self.x += 1
		return val
class Iterator:
	def __init__(self):
		self.data = 0

	def __next__(self):
		if(self.data < 10):
			self.data += 1
			return self.data
		else:
			raise StopIteration

class Integer:
	def __iter__(self):
		return Iterator()

#Today, all iteration contexts in Python will try the __iter__ method first,
#before trying __getitem__.
if __name__ == '__main__':
	s = Squares(1,2)
	for val in s:
		print(val)
	#only single scan possible. why?
	for val in s:
		print(val)

	X = Squares(1, 2) # Iterate manually: what loops do
	I = iter(X)
	next(I) # next calls __next__ (in 3.X)
	next(I)
	#next(I) StopIteration

	#Here multiscan possible, But Allows only one active iterator
	v = Value()
	for val in v:
		print(val)
	print("Next iteration of val")
	for val in v:
		print(val, end=' ')
	print('\n')

	s2 = Squares(1,5);
	print(list(iter(s2)))

	#Allows multiple active iterator
	integer = Integer()
	for i in integer:
		for j in integer:
			print(i,j)

