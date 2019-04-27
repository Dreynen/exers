# this program asks user for n number of strings and checks if they are palindromes or nah
stuff, n = [], int(input('Enter n: '))

for i in range(n):
	stuff.append(input('Enter a string: '))

print()

for word in stuff:
	new = [c for c in word]
	for i in range(len(new)):
	    if new[i]==' ':
	        new.remove(' ')
	new.reverse()
	if list(word) == new:
	    print(word,'is a palindrome.')
	else:
	    print(word,'is not a palindrome.')
