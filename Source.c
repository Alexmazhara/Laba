#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double a = 0, b = 0, c = 0, p = 0, e = 0;
	int min = 0, max = 0, d = 0, n = 0, i = 0, j = 0;


	// ввод кол-ва элементов, максимума и минимума
	printf("n = ");
	scanf_s("%d", &n);

	if (n <= 1)
	{
		printf("ERROR n <= 0 !!!!\n");
		return 0;
	}

	printf("min = ");
	scanf_s("%d", &min);

	printf("max = ");
	scanf_s("%d", &max);

	if (max < min)
	{
		printf("ERROR max < min !!!!\n");
		return 0;
	}


	// создание массива чисел и массива номеров чисел
	double* mas1 = (double*)malloc(sizeof(double) * n);
	int* mas2 = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		a = rand();
		b = (a / RAND_MAX) * (max - min) + min;
		e = modf(b, &p); // разбитие на целую и дробную часть 
		d = pow(10, 6) * modf(b, &p); //домнажвем на 10 в 6 степени 
		d = abs(d);

		mas1[i] = b;
		mas2[i] = d;
		
	}


	// вывод элементов
	for (i = 0; i < n; i++)
	{
		if (mas2[i] <= n)
			c -= mas1[mas2[i]]; 
		else
			c += mas1[i]; 
			mas1[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		c += mas1[i];
	}


	printf("Sum = %lf", c);

	free(mas1);
	free(mas2);

	return 0;
} 
