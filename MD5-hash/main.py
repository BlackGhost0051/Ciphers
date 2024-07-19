import hashlib

def encode_to_md5(plain_texts):
    md5_hashes = [hashlib.md5(text.encode()).hexdigest() for text in plain_texts]
    return md5_hashes

def decode_md5(hashes, possible_plain_texts):
    results = {}
    for md5_hash in hashes:
        found = False
        for plain_text in possible_plain_texts:
            if hashlib.md5(plain_text.encode()).hexdigest() == md5_hash:
                results[md5_hash] = plain_text
                found = True
                break
        if not found:
            results[md5_hash] = None
    return results

hashes = [
    "dfcf28d0734569a6a693bc8194de62bf",
    "c1d9f50f86825a1a2302ec2449c17196",
    "f186217753c37b9b9f958d906208506e",
    "5dbc98dcc983a70728bd082d1a47546e",
    "b9ece18c950afbfa6b0fdbfa4ff731d3"
]

possible_plain_texts = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ{}_*-+/=!@#$%^&*()_+[]/.,?';"

decoded_results = decode_md5(hashes, possible_plain_texts)

for index, md5_hash in enumerate(hashes):
    if decoded_results[md5_hash] is not None:
        print(f"{index}: {decoded_results[md5_hash]}", end="\n")
    else:
        print(f"{index}: NULL", end=" ")

plain_texts = ["G", "H", "O", "S", "T"]

encoded_hashes = encode_to_md5(plain_texts)
print("Hash:", encoded_hashes)
