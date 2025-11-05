text = input().split()
word1 = text[0].lower()  # first word in lowercase
other_words = [word.capitalize() for word in text[1:]]  # capitalize the rest
result = word1 + ''.join(other_words)  # join without spaces
print(result)
