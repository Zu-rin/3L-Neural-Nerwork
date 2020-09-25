#include "CSV_Handler.hpp"

#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void csv::Split(string & s, vector<double> & d) {
	while (true) {
		auto pos = s.rfind(",");
		if (pos < 0 || s.size() <= pos)
			break;
		d.push_back(stod(s.substr(pos + 1)));
		s.erase(pos);
	}
	d.push_back(stod(s));
	reverse(d.begin(), d.end());
	return;
}

void csv::Pull(const string & file, vector<vector<double>> & sample) {
	string s;
	ifstream fin(file);
	while (!fin.eof()) {
		vector<double> a;
		fin >> s;
		Split(s, a);
		if (a.size() == 0)
			break;
		sample.push_back(a);
	}
	return;
}

void csv::Put(const string & file, const vector<vector<double>> & d) {
	ofstream fout(file);
	int i, j;
	rep(i, d.size()) {
		rep(j, d[i].size() - 1)
			fout << setprecision(13) << d[i][j] << ",";
		fout << setprecision(13) << d[i][j] << "\n";
	}
	return;
}

void csv::Put(const string& file, const vector<double>& d) {
	vector<vector<double>> a(1);
	a[0] = d;
	csv::Put(file, a);
	return;
}