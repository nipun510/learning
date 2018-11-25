def fun():
	for x in range(0,5):
		yield x

if __name__ == '__main__':
	for val in fun():
		print(val)

	x = fun()
	print(type(x))
	print(x.__next__())
	print(x.__next__())
	print(x.__next__())
	print(x.__next__())
	print(x.__next__())
	print(x.__next__())