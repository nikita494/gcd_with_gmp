import random
import timeit
import gcd
import math

RANGES = [(10 ** (i + 1), 10 ** (i + 3)) for i in range(8)]
STATE = random.getstate()

def math_test(range):
    random.setstate(STATE)
    math.gcd(random.randrange(range[0]), random.randrange(range[1]))

def gmp_test(range):
    random.setstate(STATE)
    gcd.gcd(random.randrange(range[0]), random.randrange(range[1]))


def main():
    for curr_range in RANGES:
        math_t = timeit.timeit(lambda: math_test(curr_range), number=10000)
        gmp_t = timeit.timeit(lambda: gmp_test(curr_range), number=10000)
        print(f'Range: {" ".join(map(str, curr_range))}. Python gcd: {math_t}. C/Python gcd with gmp: {gmp_t}. GMP/math: {gmp_t/math_t}')


if __name__ == "__main__":
    main()
