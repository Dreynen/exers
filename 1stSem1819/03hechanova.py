c, i, n = 0, 2, int(input("Enter n: "))                 #prime numbers start from 2

print("The first", n, "primes are: ", end="")

while c<n:
    prime = True            #assumes that integer is prime
    for j in range(2,int(i**.5) + 1):    #divisibility of i is checked by every iteration of j
        if i % j == 0:
            prime = False   #if i is divisible by any number j, i is marked as not prime
            break           #breaks for loop
    if prime:
        print(i, end=" ")
        c += 1              #counts prime numbers
    if c == n:
        break               #end while loop
    i += 1

print()
