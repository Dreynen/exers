#this program looks for largest odd by testing variables first if odd then only after deciding which is the largest
def odd(x):
	if x%2!=0:
		return True
	return False

def maxodd(x,y,z):
	if odd(x) and odd(x) and odd(z):
		return max(x,y,z)
	elif odd(x) and odd(y):
		return max(x,y)
	elif odd(x) and odd(z):
		return max(x,z)
	elif odd(y) and odd(z):
		return max(y,z)
	elif odd(x):
		return x
	elif odd(y):
		return y
	elif odd(z):
		return z
	else:
		return("None of them are odd.")

print(maxodd(int(input('Enter x: ')), int(input('Enter y: ')), int(input('Enter z: '))))