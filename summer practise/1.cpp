#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<locale.h>
#define PI 3.14159265
#define N 20
void crossing(double mas[][N]);
void LengthOfSides(double x1, double x2, double x3, double y1, double y2, double y3);
void corners(double AB, double BC, double AC);
void MedianLengths(double x1, double x2, double x3, double y1, double y2, double y3);
void Height(double AB, double BC, double AC);
int main(void)
{
	setlocale(LC_ALL, "rus");
	double mas[N][N];
	double x[N]; //����� �������
	int otv[N]; //�������� �� ������� ������
	int i, j, k, n;
	//���� ������
	do
	{
		printf("������� ����� ��������� �������: ");
		scanf_s("%d", &n);
		if (N < n)
			printf("������� ������� ����� ���������. ��������� ����\n");
	} while (N < n);
	printf("������� �������:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf_s("%lf", &mas[i][j]);
	printf("������ ��������� (%.2f) x+(%.2f) y+(%.2f)=0\n", mas[0][0], mas[0][1], mas[0][2]);
	printf("������ ��������� (%.2f) x+(%.2f) y+(%.2f)=0\n", mas[1][0], mas[1][1], mas[1][2]);
	printf("������ ��������� (%.2f) x+(%.2f) y+(%.2f)=0\n", mas[2][0], mas[2][1], mas[2][2]);
	crossing(mas);
	return (0);
}
void crossing(double mas[][N])
//���������� ����� ����������� ������ 
{
	double d1 = 0, d2 = 0, d3 = 0, dx1 = 0, dx2 = 0, dx3 = 0, dy1 = 0, dy2 = 0, dy3 = 0, x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
	if ((mas[0][0] / mas[1][0] == mas[0][1] / mas[1][1]) || (mas[0][0] / mas[2][0] == mas[0][1] / mas[2][1]) || (mas[1][0] / mas[2][0] == mas[1][1] / mas[2][1]))
	{
		printf("������ ������ �����������, ����������� �� ����� ������������\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		d1 = mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
		dx1 = -mas[0][2] * mas[1][1] + mas[1][2] * mas[0][1];
		dy1 = -mas[0][0] * mas[1][2] + mas[0][2] * mas[1][0];
		x1 = dx1 / d1;
		y1 = dy1 / d1;

		d2 = mas[1][0] * mas[2][1] - mas[1][1] * mas[2][0];
		dx2 = -mas[1][2] * mas[2][1] + mas[2][2] * mas[1][1];
		dy2 = -mas[2][2] * mas[1][0] + mas[1][2] * mas[2][0];
		x2 = dx2 / d2;
		y2 = dy2 / d2;

		d3 = mas[0][0] * mas[2][1] - mas[2][0] * mas[0][1];
		dx3 = -mas[0][2] * mas[2][1] + mas[0][1] * mas[2][2];
		dy3 = -mas[0][0] * mas[2][2] + mas[0][2] * mas[2][0];
		x3 = dx3 / d3;
		y3 = dy3 / d3;

		printf("����� ����������� ����� ������ � ������ ������� A(%.3f;%.3f)\n", x1, y1);
		printf("����� ����������� ����� ������ � ������� ������� C(%.3f;%.3f)\n", x2, y2);
		printf("����� ����������� ����� ������ � ������� ������� B(%.3f;%.3f)\n", x3, y3);
		LengthOfSides(x1,x2,x3,y1,y2,y3);
	}
}
void LengthOfSides(double x1, double x2, double x3, double y1, double y2, double y3)
{
	double AB = 0, AC = 0, BC = 0;
	//���������� ���� ������ ������������
	printf("������ ��� ������������: ABC \n");
	AB = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
	BC = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	AC = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
	printf("����� ������� ��: %.2f\n", AB);
	printf("����� ������� �C: %.2f\n", BC);
	printf("����� ������� ��: %.2f\n", AC);
	corners(AB, BC, AC);
	MedianLengths(x1, x2, x3, y1, y2, y3);
}
void corners(double AB, double BC,double AC)
{
	double	a = 0, b = 0, c = 0, ua = 0, ub = 0, uc = 0;
	//���������� ����� ������������
	if ((AB*AB == BC*BC + AC*AC) || (BC*BC == AB*AB + AC*AC) || (AC*AC == AB*AB + BC*BC))
		printf("����������� �������� ������,���� �� �����=90 ��������\n");
	a = acos((AB*AB + AC*AC - BC*BC) / (2 * AB*AC));
	b = acos((AB*AB + BC*BC - AC*AC) / (2 * AB*BC));
	c = acos((BC*BC + AC*AC - AB*AB) / (2 * BC*AC));
	ua = a*180.0 / PI;
	ub = b*180.0 / PI;
	uc = c*180.0 / PI;
	printf("���� � ����� %.3f ��������\n", ua);
	printf("���� � ����� %.3f ��������\n", ub);
	printf("���� � ����� %.3f ��������\n", uc);
	Height(AB, BC, AC);
}
void MedianLengths(double x1, double x2, double x3, double y1, double y2, double y3)
{
	//���������� ���� ������ ������������
	printf("����� �� ��������� ������ ������������� ����� ���������� �1, �1 � �1 �������������� \n��������� �������� ��1, ��1, ��1\n");
	double xa1 = 0, xb1 = 0, xc1 = 0, ya1 = 0, yb1 = 0, yc1 = 0, AA1 = 0, BB1 = 0, CC1 = 0;
	xa1 = (x3 + x2) / 2;
	ya1 = (y3 + y2) / 2;
	xb1 = (x1 + x2) / 2;
	yb1 = (y1 + y2) / 2;
	xc1 = (x1 + x3) / 2;
	yc1 = (y1 + y3) / 2;
	AA1 = sqrt(pow(xa1 - x1, 2) + pow(ya1 - y1, 2));
	BB1 = sqrt(pow(xb1 - x3, 2) + pow(yb1 - y3, 2));
	CC1 = sqrt(pow(xc1 - x2, 2) + pow(yc1 - y2, 2));
	printf("������� �� ������� BC, AA1=%.3f\n", AA1);
	printf("������� �� ������� AC, BB1=%.3f\n", BB1);
	printf("������� �� ������� AB, CC1=%.3f\n", CC1);
}
void Height(double AB, double BC, double AC)
{
	//���������� ���� ����� ������������
	double ha = 0, hb = 0, hc = 0, p = 0, S = 0;
	p = (AB + BC + AC) / 2;
	S = sqrt(p*(p - AB)*(p - AC)*(p - BC));
	ha = (2 * sqrt(p*(p - AB)*(p - AC)*(p - BC))) / AB;
	hb = (2 * sqrt(p*(p - AB)*(p - AC)*(p - BC))) / BC;
	hc = (2 * sqrt(p*(p - AB)*(p - AC)*(p - BC))) / AC;
	printf("������ �� ������� ��, ha=%.3f\n", ha);
	printf("������ �� ������� �C, hb=%.3f\n", hb);
	printf("������ �� ������� �C, hC=%.3f\n", hc);
	printf("������������ ������������ �=%.3f\n", p);
	printf("������� ������������ S=%.3f\n", S);
}
