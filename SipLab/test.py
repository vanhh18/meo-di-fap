def byte2bin(self, int): # Bien doi 32 bit word (int) thanh string 32 binary
        string = ""
        for i in range(32):
            x = 0b00000001 << (31 - i)
            x = x & int
            x = x >> (31 - i)
            string += str(x)
        return string