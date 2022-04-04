def create_file(name):
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


def main():
    file_name1 = 'first.txt'
    file_name2 = 'second.txt'
    file_name3 = 'third.txt'
    print('Enter lines for the first file')
    create_file(file_name1)
    print('Enter lines for the second file')
    create_file(file_name2)
    fill_common(file_name1, file_name2, file_name3)
    print(f'Total rows in result: {count_rows(file_name3)}')
    print('Firts file: ')
    show_file(file_name1)
    print('Second file: ')
    show_file(file_name2)
    print('Third file: ')
    show_file(file_name3)


if __name__ == '__main__':
    main()
