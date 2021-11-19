#!/usr/bin/python3

"""
Module rain
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    """


    n = len(walls)
    t_water = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        t_water = t_water + (min(left, right) - walls[i])
    return t_water
