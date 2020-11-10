#pragma once
#include<vector>
#define _USE_MATH_DEFINES
#include<math.h>
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

double func_ist(double x, double a, double s, double u) {
	double res;
	//res = pow((5 / 2 * x*(-0.6)*s*pow(2 * 9.81, 0.5) / (pow(tan(0.5*a), 2)*M_PI)), (2 / 5));
	res = -0.270095*pow(9.81, 0.5)*s*(1 / (tan(0.5*a)*tan(0.5*a)))*pow(u, 1.5);
	return res;
}

double f(double a,double s, double u) {
	double res;
	res = -0.6*s*pow(2 * 9.81, 0.5) /(pow(tan(0.5*a),2)*M_PI*pow(u,3/2));
	return res;
}

Pos rk4(Pos pos, double a, double s, double h) {
	double k1, k2, k3, k4;
	Pos newPos = pos;
	newPos.x = pos.x + h;
	k1 = f(a, s, pos.u);
	k2 = f(a, s, pos.u + (h / 2) * k1);
	k3 = f(a, s, pos.u + (h / 2) * k2);
	k4 = f(a, s, pos.u + h * k3);
	newPos.u = pos.u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
	newPos.v = newPos.u;
	return newPos;
}

Pos next_Pos(Pos pos, double a, double s, double h) {
	Pos res;
		res = rk4(pos, a, s, h);
	return res;
}
// pos- точка от которой считаем слудеющую для f; h - шаг подсчета следующей
// func это f;
// e - предел погрешности; epsilon - с учетом локальной погрешности или же нет

std::pair<Pos, int> start(Pos pos,double s, double a, double h, bool epsilon = false, double e = 1) {
	if (h <= 0 || e <= 0)
		return std::pair<Pos, int>(pos, 0);

	if (!epsilon) {
		Pos res = rk4(pos,a, s, h);
		return std::pair<Pos, int>(res, 0);
	}
	else {
		double uslovie;
		Pos nextPos, nextPos_h2 = pos;
		double h2 = h;
		nextPos_h2 = next_Pos(nextPos_h2, a, s, h2);  
		int countDev = -1;
		// Умная-оптимизированная магия вычисления точки
		do {
			nextPos = nextPos_h2;
			nextPos_h2 = pos;
			h2 /= 2;

			for (int j = 0; j < 2; j++) {
				nextPos_h2 = next_Pos(nextPos_h2, a, s, h2); 
			}
			// подсчет погрешности для h */ 2
			countDev++;

			//uslovie = abs(nextPos.u - nextPos_h2.u) * 10;
			uslovie = (nextPos_h2.u - nextPos.u) / 15;
			nextPos.e = uslovie * 15;
			if (uslovie > e)
			{
				nextPos_h2 = next_Pos(pos, a, s, h2);
			}
		} while (uslovie >= e);

		nextPos.v = nextPos_h2.u;

		if ((uslovie < e / 32) && countDev == 0) countDev = -1;
		if ((uslovie < e) && countDev == 0) countDev = 0;
		return std::pair<Pos, int>(nextPos, -countDev);
	}
}