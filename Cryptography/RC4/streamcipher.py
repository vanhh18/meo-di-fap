def lcg_new(x0, a, n):
    # tao ra n gia tri ngau nhien bang thuat toan LCGs (c = 0; m = 2^31 - 1)
    random_numbers = [x0]
    # gia tri khoi tao X0 (seed)
    for i in range(n-1):
        x = (a * random_numbers[i]) % (2**31 - 1)
        random_numbers.append(x)
        # them gia tri vao cuoi day
    return random_numbers

# khoi tao S
def Initialization(K, plaintext):
    
# Tao mang S và T
    S = [0] * 256
    T = [0] * 256
# Tinh do dai của keylen
    keylen = len(K)

    for i in range (256):
        S[i] = i
        T[i] = K[i % keylen]
    
# Khoi tao hoan vi S 
    j = 0
    for i in range (256):
        j = (j + S[i] + T[i]) % 256
        S[i], S[j] = S[j], S[i]
        # print (S[i])

# Tao dong
    i = 0
    j = 0  
    key = []
    cipher = ''
    decryption = ''
    for i in range (len(plaintext)):
        i = (i + 1) % 256
        j = (j +S[i]) % 256
        S[i], S[j] = S[j], S[i]
        t = (S[i] + S[j]) % 256
        key.append (S[t])
        print (S[i])
# Ma hoa
    for i in range (len(plaintext)):
        x = ord(plaintext[i])
        cipher += chr(x^key[i])
    print ('cipher: ', cipher)
# Giai ma    
    for i in range (len(plaintext)):
        y = ord(cipher[i])
        decryption += chr(key[i]^y)
    print ('decryption: ', decryption)

plaintext = input('message: ')
print(lcg_new(31, 7**5, 6), plaintext)
   



