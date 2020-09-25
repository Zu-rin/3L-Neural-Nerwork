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

	// �z��d�������_���Ȓl�ŏ��������� [-10,10]
	void FillRand(vector<vector<double>>& d);

public:
	// hidden: ���ԑw�̌��Arete: �w�K��
	Neural_Network(int hidden, double rate = 0.01, int input = 2, int output = 1);

	// ���͏������`�d���\�b�h
	vector<double> Put_Sample(int dep = 0);

	// �덷�t�`�d���\�b�h  ans: ���t�f�[�^
	void BP_Learn(const vector<double>& ans);

	// ���덷��Ԃ�  ans: ���t�f�[�^
	double SError(const vector<double>& ans);

	// ���͂�ʂ��ABP�@�ɂ��w�K���s��  sample: ���̓f�[�^�{���t�f�[�^
	double Learning(const vector<double>& sample);

	// Maxstep�� �w�K���s��  1step = 1000�T���v��
	void Run(const int Maxstep = 1000, const int reduceRate = false);

	// �����_�̃j���[�����l�b�g���[�N�ɑ΂�Samplenum�̓��͂�����
	void Test(int Samplenum = 5000);

	// �w�K�Ώۂ̊֐��l��Ԃ�
	double MyFunc(double& x, double& y);
};