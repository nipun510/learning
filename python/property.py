
class Celsius:
    def __init__(self, temperature = 0):
        self._temperature = temperature

    def to_fahrenheit(self):
        return (self.temperature * 1.8) + 32

    def __get_temperature(self):
        print("Getting value")
        return self._temperature

    def __set_temperature(self, value):
        if value < -273:
            raise ValueError("Temperature below -273 is not possible")
        print("Setting value")
        self._temperature = value

    temperature = property(__get_temperature,__set_temperature)


# property(fget=None, fset=None, fdel=None, doc=None)

# make empty property
# temperature = property()
# # assign fget
# temperature = temperature.getter(get_temperature)
# # assign fset
# temperature = temperature.setter(set_temperature)


#define a private atrribute and getters and setters are implementations to wrap it
class base:
	def __init__(self, l, b, area = 20):
		self.__l = l
		self.b = b
		self.__a = area
		

	@property
	def area(self):
		return self.__a

	@area.setter
	def area(self, val):
		self.__a = area
		pass

	@area.deleter
	def area(self):
		pass

def main():
	obj = base(12,23)
	print(obj.area)
	
	


if __name__ == '__main__':
	main()


