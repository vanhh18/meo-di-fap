
# import array as arr
# K = arr.array('i', [1,2,3,6] )
def lcg(x0, a, c, m, n):
    # tao ra n gia tri ngau nhien bang thuat toan LCGs
    random_numbers = [x0]
    # gia tri khoi tao X0 (seed)
    for i in range(n-1):
        x = (a * random_numbers[i] + c) % m
        random_numbers.append(x)
        # them gia tri vao cuoi sequence        
    return random_numbers

def test( K ) :
        plaintext = 'nguyen song nam'
        S = [0] * 10
        T = [0] * 10
        # Tinh do dai của keylen
        keylen = len(K)

        for i in range (10):
                S[i] = i
                T[i] = K[i % keylen]
                
        # Khoi tao hoan vi S
        j = 0
        for i in range (10):
                j = (j + S[i] + T[i]) % 10
                S[i], S[j] = S[j], S[i]
                # print (S[i])
        i = 0
        j = 0  
        cipher = ''
        key = []
        for i in range (len(plaintext)):
                i = (i + 1) % 10
                j = (j +S[i]) % 10
                S[i], S[j] = S[j], S[i]
                t = (S[i] + S[j]) % 10
                key.append(S[t])
        print('key: ', key)

        for i in range(len(plaintext)):
                x = ord(plaintext[i])
                cipher += chr(x^key[i]) 
        print('cipher: ', cipher)
                

test(lcg(1,5,0,31,4))   
    
    

