def multiply(multiplicand, multiplier):
	if multiplier == 1:
		return multiplicand
	return multiplicand + multiply(multiplicand, multiplier - 1)

def divide(dividend, divisor):
	if divisor == 0:
		return 'undefined'
	elif dividend < divisor:
		return 0
	return divide(dividend - divisor, divisor) + 1

def menu():
	print('MENU------------')
	print('[1] Multiplication using repeated addition')
	print('[2] Division using repeated subtraction')
	print('[0] Exit')
	return input('Choice: ')

choice = None
while choice!='0':
	choice = menu()

	if choice=='1':
		print('Multiply:')
		print(multiply(int(input('Enter n: ')), int(input('Enter m: '))))

	if choice=='2':
		print('Divide:')
		print(divide(int(input('Enter n: ')), int(input('Enter m: '))))