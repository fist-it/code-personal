import hashlib
from termcolor import colored, cprint


def main():
    a = int(input('choose sha type:\n 1: ' + colored('sha512', 'light_red') + '\n 2: ' + colored('sha256', 'light_red') + '\n 3: ' + colored('sha224', 'light_red') + '\n 4: ' + colored('sha384', 'light_red') + '\n' + colored('type: ', 'light_blue')))
    target = input('What do you want to encode?: ')
    result = ''
    if a == 1:
        result = hashlib.sha512(target.encode()).hexdigest()
        cprint(result, 'green')
    elif a == 2:
        result = hashlib.sha256(target.encode()).hexdigest()
        cprint(result, 'green')
    elif a == 3:
        result = hashlib.sha224(target.encode()).hexdigest()
        cprint(result, 'green')
    elif a == 4:
        result = hashlib.sha384(target.encode()).hexdigest()
        cprint(result, 'green')
    archetype = input('what do you want to compare your result to?: ')
    check_hash(result, archetype)
    input()
    
def check_hash(s1, s2):
    if s1 == s2:
        cprint('True', 'light_green')
    else:
        cprint('False', 'light_red')


main()