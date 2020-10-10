#pragma once
#include<math.h>
#include<vector>

class Pos {
public:
	double x;
	double u;
	double v;
	double e;

	Pos() {
		x = 0;
		u = 0;
		v = 0;
		e = 0;
	}
	Pos(double _x, double _u) {
		x = _x;
		u = _u;
		v = _u;
		e = 0;
	}
	Pos(Pos& pos) {
		x = pos.x;
		u = pos.u;
		v = pos.v;
		e = pos.e;
	}
};

double func_test_(double x, double u) {
	double res;
	//res = -x / 2;
	res = exp(-x / 2);
	return res;
}

double func_test(double x, double u) {
	double res;
	res = -u/2;
	//res = exp(-x / 2);
	return res;
}
double func_main1(double x, double u) {
	double res;
	res = (u * u) / (1 + x * x * x * x) + u - u * u * u * sin(10 * x);
	return res;
}
double func_main2(double x, double u) {
	double res;	
	res = 0;
	return res;
}

Pos rk4(double (*f)(double, double), Pos pos, double h) {
	double k1, k2, k3, k4;
	Pos newPos = pos;
	newPos.x = pos.x + h;
	k1 = f(pos.x, pos.u);
	k2 = f(pos.x + (h / 2) * k1, pos.u + (h / 2) * k1);
	k3 = f(pos.x + (h / 2) * k2, pos.u + (h / 2) * k2);
	k4 = f(pos.x + h * k3, pos.u + h * k3);
	newPos.u = pos.u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
	newPos.v = newPos.u;
	return newPos;
}

// pos - точка от которой считаем слудеющую; h - шаг подсчета следующей
// func - какой из 3ех задач решаем (0 - test, 1 - main_1, 2 - main_2)  
// e - предел погрешности; epsilon - с учетом локальной погрешности или же нет
std::pair<Pos, int> start(Pos pos, double h, int func, bool epsilon = false, double e = 1) {
	if (h <= 0 || func > 2 || func < 0 || e <= 0) 
		return std::pair<Pos, int>(pos,0);
	
	if (!epsilon) {
		Pos res = rk4((func == 0) ? func_test : ((func == 1) ? func_main1 : func_main2), pos, h);
		return std::pair<Pos, int>(res,0);
	}
	else {
		double uslovie;
		Pos nextPos, nextPos_h2 = pos;
		double h2 = h;
		nextPos_h2 = rk4((func == 0) ? func_test : ((func == 1) ? func_main1 : func_main2), nextPos_h2, h2);
		int countDev = -1;
		int i = 1;
		// Умная-оптимизированная магия вычисления точки
		do {
			nextPos = nextPos_h2;
			nextPos_h2 = pos;
			h2 /= 2;
			i *= 2;

			for (int j = 0; j < i; j++) {
				nextPos_h2 = rk4((func == 0) ? func_test : ((func == 1) ? func_main1 : func_main2), nextPos_h2, h2);
			}
			// подсчет погрешности для h */ 2
			countDev++;

			uslovie = abs(nextPos.u - nextPos_h2.u)/15;
			nextPos.e = uslovie;
		} while (uslovie >= e);

		nextPos.v = nextPos_h2.u;
		
		if ((uslovie < e / 32) && countDev == 0) countDev = -1;
		if ((uslovie < e) && countDev == 0) countDev = 0;
		return std::pair<Pos, int>(nextPos, -countDev);
	}
}

//Pos rk4_main1(Pos pos, double h, double e = 1) {
//	double k1, k2, k3, k4;
//	Pos newPos_h, newPos_h2;
//	newPos_h.x = pos.x + h;
//
//	k1 = func(1, pos.u);
//	k2 = func(1, pos.u + (h / 2) * k1);
//	k3 = func(1, pos.u + (h / 2) * k2);
//	k4 = func(1, pos.u + h * k3);
//	newPos_h.u = pos.u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
//
//	double h2 = h;
//	do {
//		h2 /= 2;
//
//		k1 = func(pos.u, 1, pos.x);
//		k2 = func(pos.u + (h2 / 2) * k1, 1, pos.x);
//		k3 = func(pos.u + (h2 / 2) * k2, 1, pos.x);
//		k4 = func(pos.u + h2 * k3, 0);
//
//	
//	} while (newPos_h);
//
//	return ;
//}
//
//double** RK4_test2(double** kor_pr, double h, int n, double e)
//{
//	int p = 4, c1 = 0, c2 = 0;
//	double k1, k2, k3, k4, s;
//
//	kor_pr[0][5] = 0;
//
//	for (int i = 1; i < n; i++)
//	{
//		kor_pr[i][0] = kor_pr[i][0] + h;
//		k1 = -kor_pr[i][1] / 2;
//		k2 = -(kor_pr[i][1] + (h / 2) * k1) / 2;
//		k3 = -(kor_pr[i][1] + (h / 2) * k2) / 2;
//		k4 = -(kor_pr[i][1] + h * k3) / 2;
//		kor_pr[i][1] = kor_pr[i][1] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
//
//		double h_pr = h / 2;
//		kor_pr[i][2] = kor_pr[i][0] + h_pr;
//		k1 = -kor_pr[i][1] / 2;
//		k2 = -(kor_pr[i][1] + (h_pr / 2) * k1) / 2;
//		k3 = -(kor_pr[i][1] + (h_pr / 2) * k2) / 2;
//		k4 = -(kor_pr[i][1] + h_pr * k3) / 2;
//		kor_pr[i][3] = kor_pr[i][1] + (h_pr / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
//
//		k1 = -kor_pr[i][3] / 2;
//		k2 = -(kor_pr[i][3] + (h_pr / 2) * k1) / 2;
//		k3 = -(kor_pr[i][3] + (h_pr / 2) * k2) / 2;
//		k4 = -(kor_pr[i][3] + h_pr * k3) / 2;
//		kor_pr[i][4] = kor_pr[i][3] + (h_pr / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
//
//		s = (kor_pr[i][4] - kor_pr[i][1]) / (pow(2, p) - 1);
//
//		if (e / (pow(2, p) - 1) > fabs(s))
//		{
//			h = 2 * h;
//			c2++;
//		}
//		if (fabs(s) > e)
//		{
//			i = i - 1;
//			h = h / 2;
//			c1++;
//		}
//
//		kor_pr[i][5] = s * pow(2, p);
//
//	}
//	kor_pr[0][2] = c1;
//	kor_pr[0][3] = c2;
//	return kor_pr;
//}