#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import re
import drawer
import copy
from classes import Ant, Room, Farm

# Считываение данных из файла

def read_data():
	
	farm = Farm()	
	moves = []
	for line in sys.stdin:
		# Возвращает копию указанной строки, с конца которой 
		# удалены указанные символы. Ex: 'abca'.rstrip('ac') -> 'ab'
		line = line.rstrip('\n')
		# Cчитываем количество муравьев
		# Метод re.match ищет по заданному шаблону в начале строки.
		# re.match(pattern, string): pattern — строка регулярного выражения ('^\d+$')
		# string — строка, в которой мы будем искать соответствие с шаблоном в начале строки (line)
		# Специальные символы ^ и $ соответствуют началу и концу каждой строки
		# \d -> цифра, квантификатор + -> одна или более
		if (re.match('^\d+$', line)):
			farm.ant_num = int(line)
		# Получиаем инструкцию ##start / ##end
		elif (line == "##start" or line == "##end"):
    		# Метод strip() возвращает копию строки, в которой все символы были удалены
			# с начала и конца строки (символом по умолчанию является пробел). В нашем случае символы '#'
			temp = line.strip('#')
			# считываем следующую строку без '\n' с помощью метода strip
			line = sys.stdin.next().strip('\n')
			# отправляется строка с названием и кординатами комнаты, а также в качестве temp отправляется
			# status (start или end)
			farm.add_room(line, temp)
			# Оператор continue начинает следующий проход цикла, минуя оставшееся тело цикла (for или while)
			continue
		# Получаем параметры комнат (например: 'В 5 1' или '4 8 6')
		# \w —> любая буква и цифра, + -> одна и более потом пробел может быть '-', а может нет,
		# а после цифра одна и более и по аналогии с вторым
		elif (re.match('\w+ -*\d+ -*\d+', line)):
			farm.add_room(line, "not_end_start")
		# Получаем связи между комнатами (например: 'C-D')
		# ищем букву или цифру неравную L - и аналогично первому
		elif (re.match('^(?!L)(\w|\d)+-(\w|\d)+$', line)):
			farm.add_link(line)
		# Получаем движения муравьев (например: 'L3-B')
		elif (re.match('^L+', line)):
			moves.append(line.strip())
	return(farm, moves)

# Движение с определенной скоростью (интервал в милисекундах) 
# Для обработки исключений используется конструкция try - except
# (пытаться - кроме).
def check_interval(interval):
	try:
		interval = int(interval)
	except:
		print ("Error: invalid interval value")
		exit (1)
	if (interval <= 0):
		print ("Error: invalid interval value")
		exit (1)

def main():
    # считывание данных (см. выше)
	farm, moves = read_data()
	# получение интервала
	interval = sys.argv[1]
	# проверка интервала на валидность
	check_interval(interval)
	# запускаем из файла classes.py
	farm.create_ants()
	# copy.deepcopy(x) - возвращает полную копию x
	farm.ants_copy = copy.deepcopy(farm.ants)
	steps = []
	for move in moves:
    	# расширяет список steps, добавляя в конец все элементы списка 	
		steps.extend(farm.compute_steps(move))
	drawer.draw_graph(farm, steps, interval)
	
if __name__ == "__main__":
	main()