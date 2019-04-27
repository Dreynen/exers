sD = {}

while True:
	print('MENU----------------------')
	print('[1] Add Student')
	print('[2] View Student')
	print('[3] View All Students')
	print('[4] Delete a Student')
	print('[5] Delete all Students')
	print('[6] Edit a Student')
	print('[0] EXIT')
	choice = input('Enter choice: ')

	if choice == '1':
		print('\nADD STUDENT----------------------\n')
		student = input('Enter student number: ')
		name = input('Enter name: ')
		degree = input('Enter degree: ').upper()
		yearLevel = input('Enter year level: ')
		age = input('Enter age: ')

		sD[student] = [student,name,degree,yearLevel,age]
		print('\nSuccessfully added a student!\n')

	elif choice == '2':
		print('\nVIEW A STUDENT----------------------\n')
		if sD:
			student = input('Enter student number: ')
			if student in sD:
				print('\nStudent Number:\t', sD[student][0])
				print('Name:\t\t', sD[student][1])
				print('Degree:\t\t', sD[student][2])
				print('Year Level:\t', sD[student][3])
				print('Age:\t\t', sD[student][4])
				print()
			else:
				print('\nSorry. Student number not found!\n')
		else:
			print('No students in the record yet.\n')

	elif choice == '3':
		print('\nVIEW ALL STUDENTS----------------------')
		if sD:
			for student in sD:
				print('Student Number:\t', sD[student][0])
				print('Name:\t\t', sD[student][1])
				print('Degree:\t\t', sD[student][2])
				print('Year Level:\t', sD[student][3])
				print('Age:\t\t', sD[student][4])
				print()
		else:
			print('\nNo students in the record yet.\n')

	elif choice == '4':
		print('\nDELETE A STUDENT----------------------\n')
		if sD:
			student = input('Enter student number: ')
			if student in sD:
				del sD[student]
				print('\nSuccessfully deleted a student!\n')
			else:
				print('\nSorry. Student number not found!\n')
		else:
			print('No students in the record yet.\n')

	elif choice == '5':
		print('\nDELETE ALL STUDENTS----------------------\n')
		if sD:
			sD.clear()
			print('Successfully deleted all students!\n')
		else:
			print('No students in the record yet.\n')

	elif choice == '6':
		print('\nEDIT A STUDENT----------------------\n')
		if sD:
			student = input('Enter student number: ')
			if student in sD:
				name = input('Enter name: ')
				degree = input('Enter degree: ')
				yearLevel = input('Enter year level: ')
				age = input('Enter age: ')

				sD[student] = [student,name,degree,yearLevel,age]

				print('\nSuccessfully edited a student!\n')
			else:
				print('\nSorry. Student not found!\n')
		else:
			print('\nNo students in the record yet.\n')

    elif choice == '0':
        print('\n\n\nGood bye!\nProgram exits...\n')
        break
	else:
		print('\nInvalid choice!\n')
