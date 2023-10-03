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


def solve():
    b_size = 16
    flag_len = 144  # random large multiple of 16
    flag = b''
    for byte_i in range(flag_len):
        test_str = b'x' * (flag_len - byte_i - 1)
        lookup_dict = {
            function(test_str + flag + bytes([i]))[128:144]: i
            for i in range(256)
        }
        actual = function(test_str)
        block_i = flag_len - byte_i - 1
        block_i += (-block_i) % b_size

        try:
            flag += bytes([lookup_dict[actual[128:144]]])
        except KeyError:  # no more flag to lookup
            return flag


if __name__ == "__main__":
    print(solve())
