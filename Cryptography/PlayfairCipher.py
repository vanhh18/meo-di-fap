import string

def generate_keyphrase(keyword):
    """Generate keyphrase based on the given keyword."""
    keyword = keyword.lower().replace("j", "i")
    keyphrase = ""
    for letter in keyword:
        if letter not in keyphrase:
            keyphrase += letter
    for letter in string.ascii_lowercase:
        if letter not in keyphrase:
            keyphrase += letter
    return keyphrase

def generate_matrix(keyphrase):
    """Generate a 5x5 matrix based on the given keyphrase."""
    matrix = []
    for i in range(5):
        row = []
        for j in range(5):
            row.append(keyphrase[5*i+j])
        matrix.append(row)
    return matrix

def find_position(matrix, letter):
    """Find the position of the given letter in the matrix."""
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == letter:
                return i, j
    return None

def encrypt(message, keyphrase):
    """Encrypt the message using Playfair Cipher."""
    keyphrase = generate_keyphrase(keyphrase)
    matrix = generate_matrix(keyphrase)
    message = message.lower().replace("j", "i").replace(" ", "")
    if len(message) % 2 != 0:
        message += "x"
    ciphertext = ""
    i = 0
    while i < len(message):
        letter1 = message[i]
        letter2 = message[i+1]
        row1, col1 = find_position(matrix, letter1)
        row2, col2 = find_position(matrix, letter2)
        if row1 == row2:
            col1 = (col1 + 1) % 5
            col2 = (col2 + 1) % 5
        elif col1 == col2:
            row1 = (row1 + 1) % 5
            row2 = (row2 + 1) % 5
        else:
            col1, col2 = col2, col1
        ciphertext += matrix[row1][col1] + matrix[row2][col2]
        i += 2
    return ciphertext

def decrypt(ciphertext, keyphrase):
    """Decrypt the ciphertext using Playfair Cipher."""
    keyphrase = generate_keyphrase(keyphrase)
    matrix = generate_matrix(keyphrase)
    plaintext = ""
    i = 0
    while i < len(ciphertext):
        letter1 = ciphertext[i]
        letter2 = ciphertext[i+1]
        row1, col1 = find_position(matrix, letter1)
        row2, col2 = find_position(matrix, letter2)
        if row1 == row2:
            col1 = (col1 - 1) % 5
            col2 = (col2 - 1) % 5
        elif col1 == col2:
            row1 = (row1 - 1) % 5
            row2 = (row2 - 1) % 5
        else:
            col1, col2 = col2, col1
        plaintext += matrix[row1][col1] + matrix[row2][col2]
        i += 2
    return plaintext

# Example usage
message = input("message: ")
keyphrase = input("keyphrase: ")
ciphertext = encrypt(message, keyphrase)
print("Ciphertext:", ciphertext)
plaintext = decrypt(ciphertext, keyphrase)
print("Plaintext:", plaintext)
