#!/usr/bin/python
# -*- coding: utf-8 -*- 

from matplotlib import pyplot as plt
from matplotlib import animation
from classes import Room, Farm

def draw_annotation(name, x, y, vpos=66, bcolor='#dffeee', al=0.9, z=5):
	plt.annotate(
		name, (x, y),
		xytext=(0, vpos), textcoords='offset points', ha='center', va='center',
		bbox=dict(boxstyle='square,pad=1.0', fc=bcolor, alpha=al, zorder=z),
		size='large', style='normal'
	)

def draw_rooms(farm):
	for room in farm.rooms:
		plt.scatter(room.x, room.y, s = 11000, zorder=3, c='#89aafa', marker='H',)
		draw_annotation(room.name, room.x, room.y)
		if (farm.rooms.index(room) == farm.start_room):
			draw_annotation("START", room.x, room.y, -66, '#fcc1e4')
		if (farm.rooms.index(room) == farm.end_room):
			draw_annotation("END", room.x, room.y, -66, '#a8fb9b')


def draw_links(farm):
	for link in farm.links:
		start = farm.get_xy_by_name(link[0])
		end = farm.get_xy_by_name(link[1])
		# Выражение zip(start, end) создает объект-итератор, из которого при 
		# каждом обороте цикла извлекается кортеж, состоящий из двух элементов.
		# Первый берется из списка start, второй - из end.
		data = zip(start, end)
		plt.plot(data[0], data[1], zorder=1, c='#beb6fc', lw=10)

def draw_ants(farm):
	colors = ['#5ecc09', '#fcfbb1', '#d7dd09', '#f6ad27', '#f86777', '#0797af', '#e209e0']
	i = 0
	l = len(colors)
	for ant in farm.ants:
    	# Для отображения точечного графика предназначена функция scatter()
		plt.scatter(ant.x, ant.y, s=5000, zorder=3, c=colors[i % l])
		draw_annotation(ant.name, ant.x, ant.y, vpos=0, bcolor='#fee9fe', al=1, z=10)
		i += 1

# прорисовка комнат, связей и муравьев
def init():
	draw_rooms(gfarm)
	draw_links(gfarm)
	draw_ants(gfarm)

def animate(steps):
	gfarm.move_ants(steps)
	plt.clf()
	plt.grid(color = 'blue', linewidth = 1, linestyle = ':')
	# прорисовка комнат, связей и муравьев
	draw_rooms(gfarm)
	draw_links(gfarm)
	draw_ants(gfarm)

def draw_graph(farm, steps, interval):
	global gfarm
	gfarm = farm
	fig, ax = plt.subplots(figsize=(15, 10))
	fig.canvas.set_window_title('Lem_in Umoff')
	# прорисовка сетки
	ax.grid(color = 'blue', linewidth = 1, linestyle = ':') 
	init()
	anim = animation.FuncAnimation(fig, animate, frames=steps, init_func=init,
									blit=False, repeat=False, interval=interval)
	plt.show()
