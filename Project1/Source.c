#include <locale.h>
#include <stdio.h>
#include <math.h>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	PrintInterface();

}
void PrintInterface()
{
	system("cls");
	printf_s("Выберите пример для решения:\n1.Квадратное уравнение. 2.Система двух линейных уравнений. 3.перестановки(факториал).\n");
	int choise;
	scanf_s("%d", &choise);
	Choise(choise);

}
void Choise(int choise)
{
	switch (choise)
	{
	case 1:
		QuadraticEquation();
		break;
	case 2:
		LinearEquation();
		break;
	case 3:
		Factorial();
		break;
	default:
		PrintInterface();
		break;
	}
}
void QuadraticEquation()
{
	system("cls");
	printf_s("Введите коэффициенты a, b, c\n");
	float a, b, c, discriminant, x1, x2;
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);

	discriminant = powf(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
	{
		PrintRoots(0, 0, 0);
	}
	if (discriminant == 0)
	{
		x1 = (-b) / (2 * a);
		PrintRoots(1, x1,0);
	}
	if(discriminant > 0)
	{
		x1 = ((-b) - sqrt(discriminant)) / (2 * a);
		x2 = ((-b) + sqrt(discriminant)) / (2 * a);
		PrintRoots(2, x1, x2);
	}
}
void PrintRoots(int peremCount, float x1, float x2)
{
	switch (peremCount)
	{
		case 0:
			printf_s("Корней нет");
			break;
		case 1:
			printf("x1 = %f", x1);
			break;
		case 2:
			printf("x1 = %f. x2 = %f", x1, x2);
			break;
	}
}
void LinearEquation()
{
	printf_s("Введите коэффициенты a, b,с уравнений\n");

	float matrix[2][3];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			scanf_s("%f", &matrix[i][j]);
		}
	}
	float tmp = matrix[0][0];
	for (int i = 0; i < 3; i++)
	{
		matrix[0][i] /= tmp;
	}
	tmp = matrix[1][0];
	for (int i = 0; i < 3; i++)
	{
		matrix[1][i] -= matrix[0][i] * tmp;
	}
	tmp = matrix[1][1];
	for (int i = 0; i < 3; i++)
	{
		matrix[1][i] /= tmp;
	}
	tmp = matrix[0][1];
	for (int i = 0; i < 3; i++)
	{
		matrix[0][i] -= matrix[1][i] * tmp;
	}
	float x1 = matrix[0][2], x2 = matrix[1][2];
	PrintRoots(2, x1, x2);
}
void Factorial()
{

}