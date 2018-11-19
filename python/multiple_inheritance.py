#In classic classes (the default until Python 3.0), the attribute search in all cases
#proceeds depth-first all the way to the top of the inheritance tree, and then from
#left to right. This order is usually called DFLR, for its depth-first, left-to-right path.

#In new-style classes (optional in 2.X and standard in 3.X), the attribute search is
#usually as before, but in diamond patterns proceeds across by tree levels before
#moving up, in a more breadth-first fashion. This order is usually called the new
# style MRO, for method resolution order, though it’s used for all attributes, not just
# methods. 

# “mix in” generalpurpose methods from superclasses. Such superclasses are usually called mix-in classes

class A:
	def fun(self):
		print('A fun called')


class B(A):
	pass

class C(A):
	def fun(self):
		print('C fun called')

#Diamond pattern
class D(B, C):
	pass

#normal method resolution order dflr
class X:
	def fun():
		print('x fun')

class E(B, X):
	pass
if __name__ == "__main__":
	d = D()
	d.fun()

	e = E()
	e.fun()