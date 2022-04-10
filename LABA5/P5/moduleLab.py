class TDate:
    class __Month:
        def __init__(self, number, days, name):
            self.number = number
            self.days = days
            self.name = name

    __months = [
        __Month("January", 1, 31),
        __Month("February", 2, 28),
        __Month("March", 3, 31),
        __Month("April", 4, 30),
        __Month("May", 5, 31),
        __Month("June", 6, 30),
        __Month("July", 7, 31),
        __Month("August", 8, 31),
        __Month("September", 9, 30),
        __Month("October", 10, 31),
        __Month("November", 11, 30),
        __Month("December", 12, 31),
    ]

    def __init__(self, day, month, year):
        self.day = day
        self.month = month
        self.year = year

    @staticmethod
    def __IsFourth(year):
        return year % 4 == 0 or (year % 100 == 0 and year % 400 == 0)

    def __GetDays(self, year, month):
        daysmonth = self.__months[month - 1].days
        if self.__months[month - 1].number == 2 and self.__IsFourth(year):
            daysmonth = 29
        return daysmonth

    def __iadd__(self, other):
        self.day += other
        while self.day > self.__GetDays(self.year, self.month):
            self.day -= self.__GetDays(self.year, self.month)
            self.day += 1
            if self.month > 12:
                self.year += 1
                self.month = self.month[0].number
        return self

    def __isub__(self, other):
        self.day -= other
        while self.day < 0:
            self.month -= 1
            if self.month == 0:
                self.year -= 1
                self.month = self.month[11].number
            self.day += self.__GetDays(self.year, self.month)
        return self

    def __gt__(self, other):
        res = False
        if self.year > other.year:
            res = True
        elif self.year == other.year:
            if self.month > other.month:
                res = True
            elif self.month == other.month:
                if self.day > other.day:
                    res = True
        return res

    def __eq__(self, other):
        return self.day == other.day \
               and self.month == other.month \
               and self.year == other.year

    def __lt__(self, other):
        return (not (self > other)) and (not (self == other))

    def __ge__(self, other):
        return self == other or self > other

    def __le__(self, other):
        return self == other or self < other

    def __str__(self):
        date_str = ''
        if self.day < 10:
            date_str += "0"
        date_str += str(self.day)
        if self.month < 10:
            date_str += "0"
        date_str += str(self.month)
        if self.year < 1000:
            temp = self.year
            while temp < 1000:
                temp *= 10
                date_str += "0"
        date_str += str(self.year)
        return date_str


class TDate1(TDate):
    def __init__(self, day, month, year):
        TDate.__init__(self, day, month, year)

    def __str__(self):
        date_str = ''
        if self.day < 10:
            date_str += "0"
        date_str += str(self.day) + '.'
        if self.month < 10:
            date_str += "0"
        date_str += str(self.month) + '.'
        if self.year < 1000:
            temp = self.year
            while temp < 1000:
                temp *= 10
                date_str += "0"
        date_str += str(self.year)
        return date_str


class TDate2(TDate):
    def __init__(self, day, month, year):
        TDate.__init__(self, day, month, year)

    def __str__(self):
        date_str = ''
        if self.month < 10:
            date_str += "0"
        date_str += str(self.month) + '-'
        if self.day < 10:
            date_str += "0"
        date_str += str(self.day) + '-'
        if self.year < 1000:
            temp = self.year
            while temp < 1000:
                temp *= 10
                date_str += "0"
        date_str += str(self.year)
        return date_str
