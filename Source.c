#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double a = 0, b = 0, c = 0, p = 0, e = 0;
	int min = 0, max = 0, d = 0, n = 0, i = 0, j = 0;


	// ���� ���-�� ���������, ��������� � ��������
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


	// �������� ������� ����� � ������� ������� �����
	double* mas1 = (double*)malloc(sizeof(double) * n);
	double* mas2 = (double*)malloc(sizeof(double) * n);

	int* mas3 = (int*)malloc(sizeof(int) * n);
	int* mas4 = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		a = rand();
		b = (a / RAND_MAX) * (max - min) + min;
		e = modf(b, &p); // �������� �� ����� � ������� ����� 
		d = pow(10, 6) * modf(b, &p); //��������� �� 10 � 6 ������� 
		d = abs(d);

		mas1[i] = b;
		mas2[i] = e;
		mas3[i] = d;
		mas4[i] = p;
	}


	// ����� ���������
	for (i = 0; i < n; i++)
	{
		if (mas3[i] <= n)
			c -= mas1[mas3[i]]; // ��������� ������
		else
			c += (mas4[i] + mas2[i]); // ����� ���� ���������
	}


	printf("Sum = %lf", c);

	free(mas1);
	free(mas2);
	free(mas3);
	free(mas4);

	return 0;
}