

def lcg(x0, a,  n):
    m = 2**31-1
    # tao ra n gia tri ngau nhien bang thuat toan LCGs
    random_numbers = [x0]
    # gia tri khoi tao X0 (seed)
    for i in range(n-1):
        x = (a * random_numbers[i] ) % m
        random_numbers.append(x)
    
    for i in range(n-1):
        random_numbers[i] = bin(random_numbers[i])[2:]

    with open('data.file', 'w') as file:
         for number in random_numbers:
                file.write(str(number) + '')    
    return random_numbers
    
def test( K ) :
        S = [0] * 256
        T = [0] * 256
        # Tinh do dai của keylen
        keylen = len(K)

        for i in range (256):
                S[i] = i
                T[i] = int(K[i % keylen])
                
        # Khoi tao hoan vi S
        j = 0
        for i in range (256):
                j = (j + S[i] + T[i]) % 256
                S[i], S[j] = S[j], S[i]
                # print (S[i])
        i = 0
        j = 0  
        key = []
        for i in range (len(K)):
                i = (i + 1) % 256
                j = (j +S[i]) % 256
                S[i], S[j] = S[j], S[i]
                t = (S[i] + S[j]) % 256
                key.append(S[t])

        for i in range (len(K)):        
                key[i] = bin(key[i])[2:]
        
        with open('datatest.txt', 'w') as file:
            for number in key:
                file.write(str(number) + '')
                file.write("")
        return key

        

lcg(317,7**5,1000)
test(lcg(1806,7**5,1000))       
        

