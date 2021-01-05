# You have two numbers x, y. Both numbers have a random value between 0 and 1. Estimate PI.

import math
import random

def estimate_pi(n):
    """
        Estimates PI.

        n (int): Number of iterations
    """

    number_in_circle = 0 # Number of points inside the unit circle
    number_outside_circle = 0

    for _ in range(n):
        x = random.random()
        y = random.random()

        if is_inside(x, y):
            number_in_circle += 1

        number_outside_circle += 1

    return 4 * number_in_circle/number_outside_circle

def is_inside(x, y):    
    x_2 = x**2
    y_2 = y**2
    return math.sqrt(x_2 + y_2) <= 1

if __name__ == "__main__":
    iterations = int(input("Number iterations: "))
    print("Estimated Pi:", estimate_pi(iterations))
