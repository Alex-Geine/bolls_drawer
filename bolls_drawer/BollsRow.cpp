#include "pch.h"
#include "BollsRow.h"

//���������, ���� �� ������ ������� � �������
bool BollsRow::CheckId(int* mas, int id) {
	for (int i = 0; i < size; i++) 
		if (id == mas[i])
			return false;
	return true;
};

//�������, ������� ������� �����
void BollsRow::MoveBoll(int id, int sign) {
	//��������� ��������� �������� ��� ������� �������
	if ((id == 0 && sign < 0) || (id == size - 1 && sign > 0))
		return;

	float stepWidth = 0;	//����������, �� ������� ����� �������

	if (sign > 0)		//������� ������
		stepWidth = x_bolls[id + 1] - x_bolls[id] - 2 * r;
	else
		stepWidth = x_bolls[id] - x_bolls[id - 1] - 2 * r;
		
	if (stepWidth <= 0)		//���� �� ������� �����
		return;
	else {
		float koef = (float)rand() / RAND_MAX;
		x_bolls[id] += (float)sign * koef * stepWidth;
	}	
};

//�������, ������� ���������� ����� ����������
void BollsRow::GenCoords() {
	//���������� ���������� ������������ ���� �� ������������

	float actLenght = length - 2 * r;	//���������� ���������� �� ��������� ������ �����
	float stepX = actLenght / (size - 1);
	float x = r;

	for (int i = 0; i < size; i++) {
		x_bolls[i] = x;
		x += stepX;
	}

	//�������� ������� ������
	int id = 0;
	int *idMas = new int[size];

	for (int i = 0; i < size; i++)
		idMas[i] = -1;

	for (int i = 0; i < size; i++) {
		id = rand() % size;
		while (!CheckId(idMas, id))
			id = rand() % size;
		idMas[i] = id;
		
		//�������� ���� ���������� �������, ������ ������� �������, � ������� ����� �������
		int sign = -1 + rand() % 3;
		MoveBoll(id, sign);
	}
};

//������ ����������
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