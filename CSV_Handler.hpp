#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

namespace csv {
	// ',' ��؂�̕������double�^vector�ɕϊ�
	void Split(string& s, vector<double>& d);

	// CSVfile -> 2d�z��
	void Pull(const string& file, vector<vector<double>>& sample);

	// 2d�z�� -> CSVfile
	void Put(const string& file, const vector<vector<double>>& d);
	// 2d�z�� -> CSVfile
	void Put(const string& file, const vector<double>& d);
}