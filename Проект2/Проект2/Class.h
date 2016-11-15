#pragma once
#include <memory>
#include <iostream>
using namespace std;
class VectorXY final {
private:
	double X;
	double Y;
	double length;
	static unsigned short int i;
public:
	VectorXY(double, double);
	VectorXY();
	~VectorXY(){};

	void setX(double);
	void setY(double);
	void show();



	friend ostream& operator<<(ostream &os, const unique_ptr<VectorXY> &s) {
		os << "X=" << s->X << ' ' << "Y=" << s->Y << endl;
		return os;
	}

	friend ostream& operator<<(ostream &os, const shared_ptr<VectorXY> &s) {
		os << "X=" << s->X << ' ' << "Y=" << s->Y << endl;
		return os;
	}

	friend ostream& operator<<(ostream &os, const pair<unique_ptr<VectorXY>, unique_ptr<VectorXY> > &s) {
		os << "X1=" << s.first->X << ' ' << "Y1=" << s.first->Y << endl;
		os << "X1=" << s.second->X << ' ' << "Y2=" << s.second->Y << endl;
		return os;
	}
	
};


