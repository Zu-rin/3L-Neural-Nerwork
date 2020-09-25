#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

class Neural_Network {

	vector<vector<vector<double>>> weight;
	vector<vector<double>> cell, hist;

	int inputNum, outputNum, hiddenNum, layerNum, step;
	double LRate;

	// 配列dをランダムな値で初期化する [-10,10]
	void FillRand(vector<vector<double>>& d);

public:
	// hidden: 中間層の個数、rete: 学習率
	Neural_Network(int hidden, double rate = 0.01, int input = 2, int output = 1);

	// 入力順方向伝播メソッド
	vector<double> Put_Sample(int dep = 0);

	// 誤差逆伝播メソッド  ans: 教師データ
	void BP_Learn(const vector<double>& ans);

	// 二乗誤差を返す  ans: 教師データ
	double SError(const vector<double>& ans);

	// 入力を通し、BP法による学習を行う  sample: 入力データ＋教師データ
	double Learning(const vector<double>& sample);

	// Maxstep数 学習を行う  1step = 1000サンプル
	void Run(const int Maxstep = 1000, const int reduceRate = false);

	// 現時点のニューラルネットワークに対しSamplenumの入力を試す
	void Test(int Samplenum = 5000);

	// 学習対象の関数値を返す
	double MyFunc(double& x, double& y);
};