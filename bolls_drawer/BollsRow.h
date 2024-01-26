#pragma once
#include <time.h>

//класс, который хранит и генерирует координаты шаров на линии
class BollsRow {
private:
	//массив координат иксов шаров
	float* x_bolls = nullptr;

	//количество шаров
	unsigned int size = 0;

	//радиус шаров
	float r = 0;

	//длинна линии
	float length = 0;

	//проверяет, есть ли нужный адишник в массиве
	bool CheckId(int* mas, int id);

	//функция, которая двигает шарик
	void MoveBoll(int id, int sign);

public:
	//конструктор
	BollsRow() {
		srand(time(0));
	}

	//деструктор
	~BollsRow() {
		if (x_bolls != nullptr) {
			delete[] x_bolls;
		}
	};

	//сеттер параметров модели
	void SetValues(unsigned int size, float r, float lenght) {
		this->size = size;
		this->r = r;
		this->length = lenght;

		if (x_bolls != nullptr)
			delete[] x_bolls;

		x_bolls = new float[size];
	};

	//функция, которая генерирует новые координаты
	void GenCoords();

	//геттер параметров
	unsigned int GetSize();

	float GetR();

	float GetLenght();

	float* GetMas();
};