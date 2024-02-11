str1 = input()
str2 = input()


def similar_str(str1, str2, n):
    if (n == 1):
        return (str1 == str2)
    half_size = len(str1) // 2
    a1 = str1[:half_size]
    a2 = str1[half_size:]
    b1 = str2[:half_size]
    b2 = str2[half_size:]
    condition1 = similar_str(a1, b1, half_size) and similar_str(a2, b2, half_size)
    condition2 = similar_str(a1, b2, half_size) and similar_str(a2, b1, half_size)
    return (condition1 or condition2)

print(similar_str(str1, str2, len(str1)))
