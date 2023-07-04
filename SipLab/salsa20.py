class Salsa20:
    def byte2bin(self, int): # Bien doi 32 bit word (int) thanh string 32 binary
        string = ""
        for i in range(32):
            x = 0b00000001 << (31 - i)
            x = x & int
            x = x >> (31 - i)
            string += str(x)

        return string
    def put4bytes(self, lis): # Bien doi list chua 4 gia tri 1 byte thanh int 32 bit
        ret = 0
        for i in range(4):
            a = 0xff & lis[i]
            ret |= (a << (3-i)*8)
        return ret

    def int32to4(self,input): # Bien doi gia tri int 32 byte thanh list cac gia tri 4 byte
        ret = []
        for i in range(8):
            a = 0xffffffff << (7 - i)*32
            a &= input
            a = a >> (7 - i)*32

            ret.append(a)
        return ret
    def int8to4(self, input): # Bien doi gia tri int 8 byte thanh list cac gia tri 4 byte
        ret = []
        for i in range(2):
            a = 0xffffffff << (1 - i)*32
            a &= input
            a = a >> (1 - i)*32

            ret.append(a)
        return ret
    def __init__(self, key, nonce):
        self.key = key
        self.nonce = nonce
        self.position = 0
    def createMatrix(self):
        # Prepare
        state = []
        const = list("expand-32 byte k".encode()) # List of constant word
        key = int(self.key, 16)
        listOfKey = self.int32to4(key) # List of Key
        nonce = int(self.nonce, 16)
        listOfNonce = self.int8to4(nonce) # List of Nonce
        listOfPosition = self.int8to4(self.position) # List of Position
        # Put value to state matrix
        state.append(self.put4bytes(const[:4]))
        for i in range(4):
            state.append(listOfKey[i])
        state.append(self.put4bytes(const[4:8]))
        for i in range(2):
            state.append(listOfNonce[i])
        for i in range(2):
            state.append(listOfPosition[i])
        state.append(self.put4bytes(const[8:12]))
        for i in range(4,8):
            state.append(listOfKey[i])
        state.append(self.put4bytes(const[12:16]))
        return state

    def rotate(self, value, i):
        a = pow(2, i) - 1
        a = a << (32 - i)
        a &= value
        a = a >> (32-i)
        value = (value << i) & 0xffffffff
        a = a | value
        return a

    def qr(self,a, b, c, d):
        b ^= self.rotate(a + d, 7)
        c ^= self.rotate(b + a, 9)
        d ^= self.rotate(c + b, 13)
        a ^= self.rotate(d + c, 18)
        return a, b, c, d
    def execute(self, lis):
        for i in range(20):
            if ((i+1)%2 == 1):
                lis[0], lis[4], lis[8], lis[12] = self.qr(lis[0], lis[4], lis[8], lis[12])
                lis[5], lis[9], lis[13], lis[1] = self.qr(lis[5], lis[9], lis[13], lis[1])
                lis[10], lis[14], lis[2], lis[6] = self.qr(lis[10], lis[14], lis[2], lis[6])
                lis[15], lis[3], lis[7], lis[11] = self.qr(lis[15], lis[3], lis[7], lis[11])
            else:
                lis[0], lis[1], lis[2], lis[3] = self.qr(lis[0], lis[1], lis[2], lis[3])
                lis[5], lis[6], lis[7], lis[4] = self.qr(lis[5], lis[6], lis[7], lis[4])
                lis[10], lis[11], lis[8], lis[9] = self.qr(lis[10], lis[11], lis[8], lis[9])
                lis[15], lis[12], lis[13], lis[14] = self.qr(lis[15], lis[12], lis[13], lis[14])
        return lis

    def run(self):
        stateMatrix = self.createMatrix()
        randomMatrix = self.execute(stateMatrix)
        self.position += 1
        string = ""
        for i in range(16):
            string += self.byte2bin(randomMatrix[i])
        return string

