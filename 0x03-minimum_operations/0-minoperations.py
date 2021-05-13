#!/usr/bin/python3
"""
Checks the minimum operatios needed
"""


def minOperations(n):

    minOps = 0
    maxOps = 2
    if n <= 1:
        return 0
    while maxOps <= n:
        if n % maxOps == 0:
            minOps = minOps + maxOps
            n = n / maxOps
            maxOps = maxOps - 1
        maxOps = maxOps + 1
    return minOps
