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
	// 行列aと行列bの積を求める
	vector<vector<double>> MatX(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// 行列aと行列bの積を求める
	vector<double> MatX(const vector<double>& a, const vector<vector<double>>& b);

	// 行列aと行列bのdot積を求める
	vector<double> Matdot(const vector<double>& a, const vector<double>& b);

	// 行列aと行列bのdot積を求める
	vector<vector<double>> Matdot(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// 行列aと行列bの和を求める
	vector<double> Sum(const vector<double>& a, const vector<double>& b);

	// 行列aと行列bの和を求める
	vector<vector<double>> Sum(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// 行列aと行列bの差を求める
	vector<double> Sub(const vector<double>& a, const vector<double>& b);

	// 行列aと行列bの差を求める
	vector<vector<double>> Sub(const vector<vector<double>>& a, const vector<vector<double>>& b);

	// 転置行列を返す
	vector<vector<double>> Trans(const vector<vector<double>>& a);

	// 転置行列を返す
	vector<vector<double>> Trans(const vector<double>& a);

	// 活性関数であるシグモイド関数値を返す
	double Sigmoid(const double d);

	// 活性関数であるシグモイド関数値を返す
	vector<double> Sigmoid(const vector<double>& d);

	// [Min, Max] の値をランダムに出力する、小数精度10^-6
	double Random(mt19937& mt, ll Min, ll Max);
}
