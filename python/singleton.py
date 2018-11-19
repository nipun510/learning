
instances = {}

def singleton(aclass):
	def onCall(*args, **kwargs):
		if aclass not in instances:
			instances[aclass] = aclass(*args, **kwargs)
		return instances[aclass]
	return onCall

class Singleton:
	def __init__(self, aclass):
		self.aclass = aclass
		self.instance = None
	def __call__(self, *args, **kwargs):
		if self.instance is None:
			self.instance = self.aclass(*args, **kwargs)
		return self.instance




@singleton
class Person:  #Person  = singleton(Person)
	def __init__(self, a):
		self.a = a;
	def printa(self):
		print(self.a)

@Singleton # Spam = Singleton(Spam) Spam is actually an instance of Singleton
class Spam:
	def __init__(self, b):
		self.b = b;
	def printb(self):
		print(self.b)

if __name__ == '__main__':
	p1 = Person(23) #actually onCall getting called and returning Person instance
	p1.printa()
	p2 = Person(10)
	p2.printa()

	s1 = Spam(12) #Singleton instance __call__ method called and returns Spam instance
	s1.printb();
	s2 = Spam(19)
	s2.printb()