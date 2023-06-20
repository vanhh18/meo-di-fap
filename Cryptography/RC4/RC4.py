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

    for i in range (len(plaintext)):
        x = ord(plaintext[i])
        cipher += chr(x^key[i])
    
    for i in range (len(plaintext)):
        y = ord(cipher[i])
        decryption += chr(key[i]^y)

   
plaintext = input('message: ')
Initialization (plaintext)


