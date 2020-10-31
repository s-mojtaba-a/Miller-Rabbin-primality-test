def power(x, y, n):
    x %= n
    ans = 1
    while y:
        if y & 1:
            ans = ans*x % n
        x = x*x % n
        y >>= 1
    return ans


def check_composite(n, a, d, s):
    x = power(a, d, n)
    if x == 1 or x == n-1:
        return 0
    for i in range(s-1):
        x = x*x % n
        if x == n-1:
            return 0
    return 1


def is_prime(n):
    if n == 2 or n == 3:
        return 1
    s = 0
    d = n-1
    while d & 1 == 0:
        d >>= 1
        s += 1
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a:
            return 1
        if check_composite(n, a, d, s):
            return 0
    return 1
