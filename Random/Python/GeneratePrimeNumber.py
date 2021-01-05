# Inspired by: 2.920050977316 - Numberphile (https://youtu.be/_gCKX6VMvmU)

import math

def prime_generator(n):
    constant = 2.920050977316

    if n == 1:
        return constant
    else:
        return math.floor(prime_generator(n-1)) * (prime_generator(n-1) - math.floor(prime_generator(n-1)) + 1)

def mills_constant(n):
    A = 1.3063778838630806904686144926
    return math.floor(A**(3**n))

if __name__ == "__main__":
    n = int(input("N-th prime: "))

    print("Prime Generator:", math.floor(prime_generator(n)))
    print("With Mills Constant:", mills_constant(n))