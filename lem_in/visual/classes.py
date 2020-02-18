#!/usr/bin/python
# -*- coding: utf-8 -*- 
# Задание класса комната, где атрибутами являютс: имя комнаты,
# и ее координаты на карте x и y.

# Что такое аргумент self?
# Классам нужен способ, что ссылаться на самих себя.
# Это способ сообщения между экземплярами. Слово self это способ
# описания любого объекта, буквально


class Room(object):
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y


# Pass - оператор-заглушка, равноценный отсутствию операции.
# В ходе исполнения данного оператора ничего не происходит,
# поэтому он может использоваться в качестве заглушки в тех
# местах, где это синтаксически необходимо, например:
# в инструкциях, где тело является обязательным, таких
# как def, except и пр.
#
# Зачастую pass используется там, где код пока ещё не появился,
# но планируется. Кроме этого, иногда, его используют при
# отладке, разместив на строчке с ним точку остановки.



class Ant(Room):
    pass


# Создание класса фермы. В квадратных скобках (списки - в
# Python отсутствуют массивы в традиционном понимании этого
# термина. Вместо них для хранения однородных (и не только)
# объектов используются списки)
# В фигурных скобках (Словарь – изменяемая структура данных,
# предназначенная для хранения пары -> ключ: значение)
# a = {'cat': 'кошка', 'dog': 'собака'}
# a['cat'] -> 'кошка'

class Farm:
    def __init__(self):
        #количество муравьев с карты
        self.ant_num = 0
        self.ants = []
        self.ants_copy = []
        self.rooms = []
        self.start_room = None
        self.end_room = None
        self.i = 0
        self.room_index = {}
        self.links = []

# Метод добавления комнаты
#
# Метод Python split() разбивает строку на части, используя
# специальный разделитель, и возвращает эти части в виде списка
#
# В методе split() используется не более двух параметров:
# разделитель (необязательный параметр) – строка разбивается
# на части с помощью указанного символа. Если разделитель не
# задан, то любая пробельная строка (пробел, новая строка и
# т.д.) считается разделителем;
# maxsplit (необязательный параметр) определяет максимальное
# количество частей.

    def add_room(self, line, status):
        name, x, y = line.split(' ')

# Добавление элемента в список осуществляется с помощью
# метода append().
        self.rooms.append(Room(name, int(x), int(y)))

# Задаем ключи для имён комнаты (соответстиве name <-> i)
        self.room_index[name] = self.i
# Если start записано в status, то записываем в start_room
# текущий индекс
        if (status == "start"):
            self.start_room = self.i
# Если end записано в status, то записываем в end_room
# текущий индекс
        if (status == "end"):
            self.end_room = self.i
        self.i += 1

# Добавление связей между комнатами. Делим линию с помощью
# метода split с разделителем '-' и добавляем полученные
# элементы в список c помощью метода append()

    def add_link(self, line):
        temp = line.split('-')
        self.links.append((temp[0], temp[1]))

# Получаем значения координат х и у комнат, по их именам

    def get_xy_by_name(self, name):
        index = self.room_index[name]
        x = self.rooms[index].x
        y = self.rooms[index].y
        return (x, y)

# Создаем муравьев с помощью функции range(начало, конец, шаг)
# Различные типы могут быть приведены к строке при
# помощи конструктора str(): str(10) -> '10'
# Добавляем в списовк муравьев с помощью метода append()

    def create_ants(self):
        for i in range(1, self.ant_num + 1):
            ant = Ant(str(i), self.rooms[self.start_room].x,
                      self.rooms[self.start_room].y)
            self.ants.append(ant)

# Движение муравьев

    def move_ants(self, steps):
        for step in steps:
            i = step[0]
            x = step[1]
            y = step[2]
            self.ants[i].x = x
            self.ants[i].y = y


    def __get_substeps(self, move):
        move = move.strip('L')
        move = move.split('-')
        i = int(move[0]) - 1
        curr_room = (self.ants_copy[i].x, self.ants_copy[i].y)
        next_room = self.get_xy_by_name(move[1])
        temp = []
        s = 10
        dx = (next_room[0] - curr_room[0]) / float(s)
        dy = (next_room[1] - curr_room[1]) / float(s)
        for x in range(s + 1):
            step = []
            step.append(i)
            step.append(curr_room[0] + dx * x)
            step.append(curr_room[1] + dy * x)
            temp.append(step)
        self.ants_copy[i].x, self.ants_copy[i].y = next_room
        return (temp)

# Вычисление шагов. Создается пустой список steps. Движения
# записываются из с помощью метода split() с пробелом в
# качестве разделдителя. Шаги

    def compute_steps(self, moves):
        steps = []
        moves = moves.split(' ')
        steps = [self.__get_substeps(move) for move in moves]
        res = []
        for i in range(len(steps[0])):
            temp = []
            for step in steps:
                temp.append(step[i])
            res.append(tuple(temp))
        return (res)