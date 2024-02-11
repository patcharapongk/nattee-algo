
def generate_virus_codes(k):
    if k == 1:
        return ["01"]
    else:
        previous_codes = generate_virus_codes(k - 1)
        new_codes = []
        for code in previous_codes:
            # Original and its reverse for each code
            original = code
            reverse = code[::-1]

            # Concatenating with both original and reverse
            new_codes.append(original + original)
            new_codes.append(original + reverse)
            new_codes.append(reverse + original)

        return new_codes

# Example usage:
print(generate_virus_codes(2))
print(generate_virus_codes(3))
