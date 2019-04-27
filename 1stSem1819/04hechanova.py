def factorial(x):
	final = 1
	for i in range(1,x+1):
		final = final * i
	return final

def table(n):
	for i in range(1,n+1):
		for j in range(1,n+1):
			print(i*j,end='\t')
		print()

while True:
	print('MENU---------------------')
	print('[1] Factorial')
	print('[2] Print N x N Multiplication Table')
	print('[0] Exit')
	choice = input('Choice: ')

	if choice == '1':
		print('\nFACTORIAL----------------')
		x = int(input("Enter a number: "))
		print(x,'! = ', factorial(x), sep='')
		print()

	elif choice == '2':
		print('\nMULTIPLICATION TABLE-----')
		n = int(input('Enter size: '))
		table(n)
		print()

	elif choice == '0':
	    print('\nProgram exits..\nGood bye!\n')
		break
	else:
		print('\nInvalid choice!\n')
