# def lcg(x0, a, c, m, n):
#     # tao ra n gia tri ngau nhien bang thuat toan LCGs
#     random_numbers = [x0]
#     # gia tri khoi tao X0 (seed)
#     for i in range(n-1):
#         x = (a * random_numbers[i] + c) % m
#         random_numbers.append(x)
#         # them gia tri vao cuoi sequence   
    
#     for i in range (n-1):
#         random_numbers[i] = bin(random_numbers[i])[2:]
#         print (random_numbers[i], end = ' \n')
#     return random_numbers

# lcg(1,5,0,31,4)

def lcg_new(x0, a, n):
    m = 2**31-1
    # tao ra n gia tri ngau nhien bang thuat toan LCGs (c = 0; m = 2^31 - 1)
    random_numbers = [x0]
    # gia tri khoi tao X0 (seed)
    for i in range(n-1):
        x = (a * random_numbers[i]) % (m)
        random_numbers.append(x)
        # them gia tri vao cuoi day
    for i in range(n-1):
        # print(bin(random_numbers[i]).replace('0b', '') , end = '\n')
        random_numbers[i] = bin(random_numbers[i])[10:]
        print (random_numbers[i], end = ' \n')

lcg_new(1,7**5,10**6)


# import math
# def prime_number(a):
#     for i in range(2, int(math.sqrt(a))):
#         if a % i == 0:
#             print ("a is not prime number ")
#             break;
#         else:
#             print ("a is a prime number")

# prime_number(11)

# def BBSs(x0, s, p, q, n):
    
