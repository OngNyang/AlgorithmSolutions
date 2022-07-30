#factorial with recursive function
def factorial_recursive(n):
    if n<=1:
        return 1
    return n*factorial_recursive(n-1)

print('반복적으로 구현:', factorial_recursive(5))