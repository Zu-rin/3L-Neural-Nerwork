#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

namespace Mt {
	// �s��a�ƍs��b�̐ς����߂�
	vector<vector<double>> MatX(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// �s��a�ƍs��b�̐ς����߂�
	vector<double> MatX(const vector<double>& a, const vector<vector<double>>& b);

	// �s��a�ƍs��b��dot�ς����߂�
	vector<double> Matdot(const vector<double>& a, const vector<double>& b);

	// �s��a�ƍs��b��dot�ς����߂�
	vector<vector<double>> Matdot(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// �s��a�ƍs��b�̘a�����߂�
	vector<double> Sum(const vector<double>& a, const vector<double>& b);

	// �s��a�ƍs��b�̘a�����߂�
	vector<vector<double>> Sum(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// �s��a�ƍs��b�̍������߂�
	vector<double> Sub(const vector<double>& a, const vector<double>& b);

	// �s��a�ƍs��b�̍������߂�
	vector<vector<double>> Sub(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// �]�u�s���Ԃ�
	vector<vector<double>> Trans(const vector<vector<double>>& a);

	// �]�u�s���Ԃ�
	vector<vector<double>> Trans(const vector<double>& a);

	// �����֐��ł���V�O���C�h�֐��l��Ԃ�
	double Sigmoid(const double d);

	// �����֐��ł���V�O���C�h�֐��l��Ԃ�
	vector<double> Sigmoid(const vector<double>& d);

	// [Min, Max] �̒l�������_���ɏo�͂���A�������x10^-6
	double Random(mt19937& mt, ll Min, ll Max);
}
