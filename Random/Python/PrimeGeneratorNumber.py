# Inspired by: "2.920050977316 - Numberphile" (https://youtu.be/_gCKX6VMvmU)

import math

def generate_num(n):
    prime_numbers = [2, 3]
    sequence = [2, 3]

    if n > 1:
        for i in range(2, n):
            for x in prime_numbers:
                if i % x != 0:
                    sequence.append(x)
                    break                

            if is_prime(i):
                prime_numbers.append(i)

    return sum(sequence)/len(sequence)

def is_prime(num):
    if num <= 1:
        return False

    for i in range(2, num):
        if num % i == 0:
            return False

    return True

if __name__ == "__main__":
    n = int(input("N (The higher, the preciser): "))
    print("Prime Generator Number:", generate_num(n))