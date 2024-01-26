#pragma once
#include <time.h>

//�����, ������� ������ � ���������� ���������� ����� �� �����
class BollsRow {
private:
	//������ ��������� ����� �����
	float* x_bolls = nullptr;

	//���������� �����
	unsigned int size = 0;

	//������ �����
	float r = 0;

	//������ �����
	float length = 0;

	//���������, ���� �� ������ ������� � �������
	bool CheckId(int* mas, int id);

	//�������, ������� ������� �����
	void MoveBoll(int id, int sign);

public:
	//�����������
	BollsRow() {
		srand(time(0));
	}

	//����������
	~BollsRow() {
		if (x_bolls != nullptr) {
			delete[] x_bolls;
		}
	};

	//������ ���������� ������
	void SetValues(unsigned int size, float r, float lenght) {
		this->size = size;
		this->r = r;
		this->length = lenght;

		if (x_bolls != nullptr)
			delete[] x_bolls;

		x_bolls = new float[size];
	};

	//�������, ������� ���������� ����� ����������
	void GenCoords();

	//������ ����������
	unsigned int GetSize();

	float GetR();

	float GetLenght();

	float* GetMas();
};