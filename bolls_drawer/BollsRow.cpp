#include "pch.h"
#include "BollsRow.h"

//проверяет, есть ли нужный адишник в массиве
bool BollsRow::CheckId(int* mas, int id) {
	for (int i = 0; i < size; i++) 
		if (id == mas[i])
			return false;
	return true;
};

//функция, которая двигает шарик
void BollsRow::MoveBoll(int id, int sign) {
	//проверяем отдельные ситуации для крайних шариков
	if ((id == 0 && sign < 0) || (id == size - 1 && sign > 0))
		return;

	float stepWidth = 0;	//расстояние, на которое можно двигать

	if (sign > 0)		//двигаем вправо
		stepWidth = x_bolls[id + 1] - x_bolls[id] - 2 * r;
	else
		stepWidth = x_bolls[id] - x_bolls[id - 1] - 2 * r;
		
	if (stepWidth <= 0)		//если не хватает места
		return;
	else {
		float koef = (float)rand() / RAND_MAX;
		x_bolls[id] += (float)sign * koef * stepWidth;
	}	
};

//функция, которая генерирует новые координаты
void BollsRow::GenCoords() {
	//изначально равномерно распределяем шары по пространству

	float actLenght = length - 2 * r;	//переменная отвечающая за доступную длинну линии
	float stepX = actLenght / (size - 1);
	float x = r;

	for (int i = 0; i < size; i++) {
		x_bolls[i] = x;
		x += stepX;
	}

	//рандомно двигаем шарики
	int id = 0;
	int *idMas = new int[size];

	for (int i = 0; i < size; i++)
		idMas[i] = -1;

	for (int i = 0; i < size; i++) {
		id = rand() % size;
		while (!CheckId(idMas, id))
			id = rand() % size;
		idMas[i] = id;
		
		//получили айди двигаемого обьекта, теперь получем сторону, в которую будем двигать
		int sign = -1 + rand() % 3;
		MoveBoll(id, sign);
	}
};

//геттер параметров
unsigned int BollsRow::GetSize() {
	return size;
};

float BollsRow::GetR() {
	return r;
};

float BollsRow::GetLenght() {
	return length;
};

float* BollsRow::GetMas() {
	return x_bolls;
};