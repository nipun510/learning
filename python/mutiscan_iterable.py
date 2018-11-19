#Running our class instance through iter obtains the result of calling
#__iter__ as usual, but in this case the result is a generator object with an automatically
#created __next__ of the same sort we always get when calling a generator function that
#contains a yield.

class Squares: # __iter__ + yield generator
	def __init__(self, start, stop): # __next__ is automatic/implied
		self.start = start
		self.stop = stop
		self.data = [ 3,43,43,34]

	def __iter__(self):
		for value in range(self.start, self.stop + 1):
			yield value ** 2

class Squares2:
	def __init__(self, start, stop): # Non-yield generator
		self.start = start # Multiscans: extra object
		self.stop = stop
		def __iter__(self):
		return SquaresIter(self.start, self.stop)

class SquaresIter:
	def __init__(self, start, stop):
		self.value = start - 1
		self.stop = stop
	def __next__(self):
		if self.value == self.stop:
		raise StopIteration
		self.value += 1
		return self.value ** 2

def fun():
	for x in range(0,4):
		yield x

if __name__ == '__main__':
	# __iter__/yield combination has an important added bonus—it also supports
#multiple active iterators automaticall
	s = Squares(1,3)
	for val in s:
		print(val)

	for val in s:
		print(val)

