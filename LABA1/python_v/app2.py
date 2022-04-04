import pickle


class cl:
    def __init__(self, surname, start_serv, end_serv):
        self.surname = surname
        self.start_serv = start_serv
        self.end_serv = end_serv


def show_res():
    with open('clients30.txt', 'rb') as file:
        bin_data = file.read()
        clients = pickle.loads(bin_data)['clients']
        for client in clients:
            print(f'{client.surname}\t{client.start_serv}\t{client.end_serv}')


def more_half():
    with open('clients.txt', 'rb') as file:
        cls = []
        bin_data = file.read()
        clients = pickle.loads(bin_data)['clients']
        for c in clients:
            h1 = c.start_serv // 100
            h2 = c.end_serv // 100
            m1 = c.start_serv % 100
            m2 = c.end_serv % 100
            h_delay = abs(h2 - h1)
            m_delay = abs(m2 - m1)
            delay = h_delay * 60 + m_delay
            if delay > 30:
                cls.append(c)
        with open('clients30.txt', 'wb') as file2:
            pickle.dump({'clients': cls}, file2)


def create_list():
    clients = list()
    with open('clients.txt', 'wb') as file:
        buf = 'y'
        count = 0
        while buf == 'y':
            is_ok = True
            print(f'Client {count}')
            print('Surname: ', end='')
            surname = input()
            print('Start: ', end='')
            start_serv = int(input())
            print('End: ', end='')
            end_serv = int(input())
            c = cl(surname, start_serv, end_serv)
            for client in clients:
                if client.start_serv <= c.start_serv <= client.end_serv \
                        or client.start_serv <= c.end_serv <= client.end_serv:
                    is_ok = False
                    print('Mismatch in time')
            if is_ok:
                clients.append(c)
            print('Add another client? y/n')
            buf = input()
            count += 1
        pickle.dump({'clients': clients}, file)


def main():

    show_res()


if __name__ == '__main__':
    main()
