import random

def encrypt(plaintext, key):
    ciphertext = ""
    for i in range(len(plaintext)):
        # XOR each character with a random key value
        ciphertext += chr(ord(plaintext[i]) ^ key)
    return ciphertext

def decrypt(ciphertext, key):
    plaintext = ""
    for i in range(len(ciphertext)):
        # XOR each character with the same random key value 
        plaintext += chr(ord(ciphertext[i]) ^ key)
    return plaintext

message=input("message is: ")
key = random.randint(0, 255)
print("Original message:", message)
encrypted_message = encrypt(message, key)
print("Encrypted:", encrypted_message) 
decrypted_message = decrypt(encrypted_message, key)
print("Decrypted:", decrypted_message)
