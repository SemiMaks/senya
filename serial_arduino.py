# https://amperkot.ru/blog/serial-py/
import sys

import serial.tools.list_ports
import serial

ser = serial.Serial('COM3', 115200)

# Получаем список доступных Serial портов
ports = list(serial.tools.list_ports.comports())
# Выводим информацию о каждом порте
for port in ports:
    print(f"Порт: {port.device}")
    print(f"Описание: {port.description}")
    print(f"Производитель: {port.manufacturer}\n")


def manual():
    print('Выбран ручной режим\nl - влево\nr - вправо\nu - вверх\nd - вниз\n')

    while (True):
        print('Для выхода из программы нажмите \n"q"')
        userInput = input('Направление: ')
        if userInput == 'l':
            ser.write(b'l')
        if userInput == 'r':
            ser.write(b'r')
        if userInput == 'u':
            ser.write(b'u')
        if userInput == 'd':
            ser.write(b'd')
        if userInput == 'q':
            ser.close()
            print('Завершение работы программы...')
            sys.exit()


def auto():
    print('Работа в автоматическом режиме!')


ans = input('Выберите режим работы программы \n(ручной - "m" или авто - "a"):\n')

if ans == 'm':
    manual()

if ans == 'a':
    auto()
