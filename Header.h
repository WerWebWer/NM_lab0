#pragma once
#include<math.h>
#include<vector>
#include <tuple>

class Pos {
public:
	double x;
	double u;
	double v;
	double e;
	double u2;
	double a;

	Pos() {
		x = 0;
		u = 0;
		v = 0;
		e = 0;
		u2 = 0;
	}
	Pos(double _x, double _u) {
		x = _x;
		u = _u;
		v = _u;
		e = 0;
		u2 = 0;
	}
	Pos(Pos& pos) {
		x = pos.x;
		u = pos.u;
		v = pos.v;
		e = pos.e;
		u2 = pos.u2;
	}
	~Pos() {};
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
	//res = (u * u) / (1 + x * x * x * x) + u - u * u * u * sin(10 * x);
	res = ((u * u) * (x * x * x + 1)) / (1 + x * x * x * x * x) + u - u * u * u * sin(10 * x);
	return res;
}
double func_main2_1(double u_2) {
	return u_2;
}
double func_main2_2(double u_1, double a) {
	double res;
	res = -a * sin(u_1);
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

Pos rk4_main2_1(double (*f)(double), Pos pos, double h) {
	double k1, k2, k3, k4;
	Pos newPos = pos;
	newPos.x = pos.x + h;
	k1 = f(pos.u2);
	k2 = f(pos.u2 + (h / 2) * k1);
	k3 = f(pos.u2 + (h / 2) * k2);
	k4 = f(pos.u2 + h * k3);
	newPos.u = pos.u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
	return newPos;
}

Pos rk4_main2_2(double (*f)(double, double), Pos pos, double a, double h) {
	double k1, k2, k3, k4;
	Pos newPos = pos;
	newPos.x = pos.x + h;
	k1 = f(pos.u, a);
	k2 = f(pos.u + (h / 2) * k1, a);
	k3 = f(pos.u + (h / 2) * k2, a);
	k4 = f(pos.u + h * k3, a);
	newPos.u2 = pos.u2 + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
	return newPos;
}

Pos next_Pos(Pos pos, double a, int num_func, double h) {
	Pos res;
	if (num_func == 2) {
		Pos res1 = rk4_main2_1(func_main2_1, pos, h);   //pos1 это начальное значение для f(1) => u(2)_нулевое
		Pos res2 = rk4_main2_2(func_main2_2, pos, a, h);  //pos2 - начальная для f(2) => u(1)_нулевое
		res.u = res1.u;
		res.u2 = res2.u2;
		res.x = res1.x;

	}
	else {
		res = rk4((num_func == 0) ? func_test : func_main1, pos, h);
	}

	return res;
}

// pos - точка от которой считаем слудеющую; h - шаг подсчета следующей
// func - какой из 3ех задач решаем (0 - test, 1 - main_1, 2 - main_2)  
// e - предел погрешности; epsilon - с учетом локальной погрешности или же нет
std::pair<Pos, int> start(Pos pos, double h, double a, int func, bool epsilon = false, double e = 1) {
	if (h <= 0 || func > 2 || func < 0 || e <= 0) 
		return std::pair<Pos, int>(pos,0);

	if (!epsilon) {
		Pos res = next_Pos(pos, a, func, h); //rk4((func == 0) ? func_test : ((func == 1) ? func_main1 : func_main2), pos, h);
		return std::pair<Pos, int>(res, 0);
	} else {
		double uslovie;
		Pos nextPos, nextPos_h2 = pos;
		double h2 = h;
		nextPos_h2 = next_Pos(nextPos_h2, a, func, h2);  //rk4((func == 0) ? func_test : ((func == 1) ? func_main1 : func_main2), nextPos_h2, h2);
		int countDev = -1;
		int i = 1;
		// Умная-оптимизированная магия вычисления точки
		do {
			nextPos = nextPos_h2;
			nextPos_h2 = pos;
			h2 /= 2;
			i *= 2;

			for (int j = 0; j < i; j++) {
				nextPos_h2 = next_Pos(nextPos_h2, a, func, h2); //rk4((func == 0) ? func_test : ((func == 1) ? func_main1 : func_main2), nextPos_h2, h2);
			}
			// подсчет погрешности для h */ 2
			countDev++;

			uslovie = abs(nextPos.u - nextPos_h2.u) *10;
			nextPos.e = uslovie/10;
		} while (uslovie >= e);

		nextPos.v = nextPos_h2.u;

		if ((uslovie < e / 32) && countDev == 0) countDev = -1;
		if ((uslovie < e) && countDev == 0) countDev = 0;
		return std::pair<Pos, int>(nextPos, -countDev);
	}
}