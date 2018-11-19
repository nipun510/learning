

class meta(type):
	def __new__(meta, classname, supers, classdict):
		print("supermeta __new__", "\n", meta, "\n", classname, "\n", supers, "\n", classdict)
		return type.__new__(meta, classname, supers, classdict)

	def __init__(Class, classname, supers, classdict):
		print("supermeta __init__")
		#type.__init__(classname, supers, )

print("Before base")
 
class base(metaclass=meta):
	def __init__(self):
		print("base __init__")

print("Before main")

if __name__ == '__main__':
	b = base();
	print(base.__dict__)