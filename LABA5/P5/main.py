import random
from moduleLab import TDate, TDate1, TDate2


def main():
    year1 = int(input('Enter year: '))
    month1 = int(input('Enter month: '))
    day1 = int(input('Enter day: '))

    year2 = int(input('Enter year: '))
    month2 = int(input('Enter month: '))
    day2 = int(input('Enter day: '))

    d1 = TDate(day1, month1, year1)
    d2 = TDate(day2, month2, year2)

    dates = []
    for i in range(10):
        dates.append(TDate1(random.randint(1, 28), random.randint(1, 12), random.randint(year1 - 3, year2 + 3)))
        dates.append(TDate2(random.randint(1, 28), random.randint(1, 12), random.randint(year1 - 3, year2 + 3)))

    print('Dates')

    for i in dates:
        print(i)

    print('Between')

    for i in dates:
        if d1 <= i <= d2:
            print(i)

    print('Latest')
    dates.sort(key=lambda x: x)
    print(dates[0])


if __name__ == '__main__':
    main()
