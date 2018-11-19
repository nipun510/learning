class C:
	def __init__(self, val):
		self.data = val

	def __call__(self):
		print('object called')

	def __add__(self, other):
		return self.data + other

	def __radd__(self, other):
		return self.__add__(other)

	def __eq__(self, other):
		return self.data == other

	def __gt__(self, other): # 3.X and 2.X version
		return self.data > other

	def __lt__(self, other):
		return self.data < other

	def __len__(self): return 1

	def __bool__(self): return True

	def __del__(self):
		print('del')

if __name__ == '__main__':
	c = C(3)
	a = C(1)
	
	if(a < 5):
		print("a less that 5")

	if(c == 3):
		print('c is equal to 3')

	if(c != 23):
		print('c is not equal to 23')

