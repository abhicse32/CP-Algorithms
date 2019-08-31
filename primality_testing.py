# since numbers can be arbitrarily large, using python for this task

from math import ceil, sqrt
from random import randrange
'''trial division which runs in O(sqrt(n)) time'''
def trial_division(n):
    if n==2: return True
    if (n < 2) or not(n & 1): return False
    sq = int(ceil(sqrt(n)))
    for i in range(3, sq+1, 2):
        if n % i == 0: return False
    return True

'''Using Wilson's theorem which states that - a positive integer n is a prime if and only if (n-1)! \equiv -1 (mod n), 
    i.e. ((n-1)!) % n = n-1'''
def wilson_test(n):
    if n == 2: return True
    if n < 2 or not (n & 1): return False
    res = 1
    for i in range(2, n):
        res = (res * i) % n
    if res == n - 1: return True
    return False

"""Fermat's little theorem can be used for primality testing which states that if p is a prime and a is a number not 
  divisible by p, then a^(p-1) \equiv 1 (mod p), i.e. a^(p-1) -1 is always divisible by p. If n is not a prime and for certain a
  a^(n-1) = 1 (mod n), then a is called 'fermat liar' and n is called 'fermat pseudoprime' to base 'a'. To make things worse, there
  are numbers which are fermat pseudoprime to all bases, i.e. for all a, a^(n-1) = 1(mod n). Such numbers are called 
  'Carmichael numbers' and there are infinitely many of them. The good thing is that these numbers are quite rare. 
  Ass Carmichael numbers are too many and can't be stored, this algorithm is rarely used for primality testing, though is 
  fast as compared to previous two algorithms"""

def fermat_test(n, k): 
    if n == 2: return True
    if n < 2 or not (n & 1): return False
    """run this test k times if it fails, and report the result"""
    for i in range(k):
        a = randrange(2, n)
        if pow(a, n-1, n) != 1:    # computes a ^(n-1) mod n
            return False            # definitely composite
    return True                     # probably prime

"""Premise for the Rabin-Miller uses the premise of the equation:  x^2 = 1 (mod p) and using Fermat's little theorem 
    to prove if p could or could not be a prime. The given modular equation can also be written as (x^2-1) = 0 (mod p) => 
    (x-1)*(x+1) = 0 (mod p). If p is a prime, it must divide either (x-1) or (x + 1). If x + 1 = 0 (mod p) => x = -1 (mod p), and 
    if (x -1) = 0 (mod p) => x = 1 (mod p) which concludes that if p is a prime, x = -1, 1 (mod p) for some x.
    
    Fermat's Little Theorem states that an integer p is a prime if for all coprime integers a, a^(p-1) = 1 (mod p). Since p
    is an odd prime, we can write p - 1 = 2^(s)*d, where d is an odd integer. So """
def miller_rabin(n):
   pass 

if __name__ == '__main__':
    while True:
        a = input()
        print fermat_test(a, 10)
