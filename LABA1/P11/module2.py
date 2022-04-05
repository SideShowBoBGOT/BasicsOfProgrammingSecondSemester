def create_file(name):
    a_or_w = input("Append or write?a\w: ")
    if a_or_w == 'a':
        with open(name, 'a') as file:
            s = input()
            while ord(s[0]) != 5:
                file.write(s + '\n')
                s = input()
    else:
        with open(name, 'w') as file:
            s = input()
            while ord(s[0]) != 5:
                file.write(s + '\n')
                s = input()


def fill_common(name1, name2, name3):
    with open(name1, 'r') as f1:
        with open(name3, 'w') as f3:
            for l1 in f1:
                if l1 != '':
                    with open(name2, 'r') as f2:
                        for l2 in f2:
                            if l1 == l2:
                                f3.write(l1)


def count_rows(name):
    count = 0
    with open(name, 'r') as file:
        for _ in file:
            count += 1
    return count


def show_file(name):
    with open(name, 'r') as file:
        for line in file:
            print(line, end='')

