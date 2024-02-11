
def generate_virus_codes(k):
    if k == 1:
        return ["01"]
    else:
        previous_codes = generate_virus_codes(k - 1)
        new_codes = set()  # Using a set to avoid duplicates
        for code in previous_codes:
            # Original and its reverse for each code
            original = code
            reverse = code[::-1]

            # Concatenating with both original and reverse
            new_codes.add(original + original)
            new_codes.add(original + reverse)
            new_codes.add(reverse + original)
            new_codes.add(reverse + reverse)

        return list(new_codes)  # Convert back to list for consistent output

# Test the function again for k = 3
codes_for_3_squared = generate_virus_codes(4)
print(len(codes_for_3_squared), codes_for_3_squared)

