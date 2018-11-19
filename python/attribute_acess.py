 #dynamically computed attribute

class Empty:
	def __getattr__(self, attrname): # On self.undefined
		if attrname == 'age':
			return 40
		else:
			raise AttributeError(attrname)

	def __setattr__(self, attr, value):
		if attr == 'age':
			self.__dict__[attr] = value + 10 # Not self.name=val or setattr
		else:
			raise AttributeError(attr + ' not allowed')	


#Assigning to any self attributes within __setattr__ calls __setattr__ again, 
#potentially causing an infinite recursion loop 