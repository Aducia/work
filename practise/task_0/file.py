''' task nomber 2:takes a string as input and returns a truple with 3 elements in which the first element has the str type and includes all vowels from the input line(preserving the order). The second element is int - the nomber of consonant letters, and the last 1 is all the consonsnt letters from the intput line.'''
input_str = input("Enter your string: ")

def string_analyzer(input_str):
    vowels = 'aeiouAEIOU'
    vowels_f = ''
    consonants_f = ''
    
    for char in input_str:
        if (char >= 'a' and char <= 'z') or (char >= 'A' and char <= 'Z'):
            if char in vowels:
                vowels_f += char
            else:
                consonants_f += char
    return (vowels_f, len(consonants_f), consonants_f)

result = string_analyzer(input_str)
print(result)

