#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Method that determines if a given data set
    represents a valid UTF-8 encoding.
    """

    bytes = 0

    for num in data:
        b = 1 << 7
        if bytes == 0:
            while b & num:
                bytes += 1
                b >>= 1

            if bytes == 0:
                continue

            if bytes == 1 or bytes > 4:
                return False
        else:
            if not (num >> 6 and not (num & (1 << 6))):
                return False
        bytes = max(bytes - 1, 0)
    return bytes == 0
