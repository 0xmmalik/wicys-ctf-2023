from Crypto import Random
from Crypto.Cipher import AES

secret_key = Random.get_random_bytes(16)
flag = open("flag.txt", "rb").read()


def pkcs7_pad(data: bytes, length: int):
    required = length - len(data)
    return data + chr(required).encode() * required


def function(data):
    try:
        data = data.encode()
    except:
        pass
    data += flag
    block_size = 16
    desired_length = len(data) + (-len(data) % block_size)
    data = pkcs7_pad(data, desired_length)

    return AES.new(secret_key, mode=AES.MODE_ECB).encrypt(data)


if __name__ == "__main__":
    while True:
        print(function(input("Text to encrypt: ")))
