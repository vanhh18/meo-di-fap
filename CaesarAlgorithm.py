def caesar_cipher(plaintext, shift):
    
    ciphertext = ""
    for char in plaintext:
        if char.isupper():
            ciphertext += chr((ord(char) + shift - 65) % 26 + 65)
        elif char.islower():
            ciphertext += chr((ord(char) + shift - 97) % 26 + 97)
        else:
            ciphertext += char

    
    return ciphertext

plaintext = input("message: ")
shift = int(input("shift: "))
ciphertext = caesar_cipher(plaintext, shift)
print(ciphertext)
