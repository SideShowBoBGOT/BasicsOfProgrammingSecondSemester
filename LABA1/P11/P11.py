from module2 import *

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
