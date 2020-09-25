#include "Mymath.hpp"

#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

vector<vector<double>> Mt::MatX(const vector<vector<double>>& a, const vector<vector<double>>& b) {
	if (a[0].size() != b.size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i, j, k;
	vector<vector<double>> ans(a.size());
	rep(i, ans.size()) {
		ans[i].resize(b[0].size());
		rep(j, ans[i].size()) {
			rep(k, a[i].size())
				ans[i][j] += a[i][k] * b[k][j];
		}
	}
	return ans;
}

vector<double> Mt::MatX(const vector<double>& a, const vector<vector<double>>& b) {
	if (a.size() != b.size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i, k;
	vector<double> ans(a.size());
	ans.resize(b[0].size());
	rep(i, ans.size()) {
		rep(k, a.size())
			ans[i] += a[k] * b[k][i];
	}
	return ans;
}

vector<double> Mt::Matdot(const vector<double>& a, const vector<double>& b) {
	if (a.size() != b.size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i;
	vector<double> ans(a.size());
	rep(i, ans.size()) {
		ans[i] = a[i] * b[i];
	}
	return ans;
}

vector<vector<double>> Mt::Matdot(const vector<vector<double>>& a, const vector<vector<double>>& b) {
	if (a.size() != b.size() || a[0].size() != b[0].size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i, j;
	vector<vector<double>> ans(a.size());
	rep(i, ans.size())
		ans[i] = Matdot(a[i], b[i]);
	return ans;
}

vector<double> Mt::Sum(const vector<double>& a, const vector<double>& b) {
	if (a.size() != b.size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i;
	vector<double> ans(a.size());
	rep(i, a.size())
		ans[i] = a[i] + b[i];
	return ans;
}

vector<vector<double>> Mt::Sum(const vector<vector<double>>& a, const vector<vector<double>>& b) {
	if (a.size() != b.size() || a[0].size() != b[0].size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i;
	vector<vector<double>> ans(a.size(), vector<double>(a[0].size()));
	rep(i, a.size())
		ans[i] = Sum(a[i], b[i]);
	return ans;
}

vector<double> Mt::Sub(const vector<double>& a, const vector<double>& b) {
	if (a.size() != b.size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i;
	vector<double> ans(a.size());
	rep(i, a.size())
		ans[i] = a[i] - b[i];
	return ans;
}

vector<vector<double>> Mt::Sub(const vector<vector<double>>& a, const vector<vector<double>>& b) {
	if (a.size() != b.size() || a[0].size() != b[0].size()) {
		printf("Incorrect size.\n");
		exit(0);
	}
	int i;
	vector<vector<double>> ans(a.size(), vector<double>(a[0].size()));
	rep(i, a.size())
		ans[i] = Sub(a[i], b[i]);
	return ans;
}

vector<vector<double>> Mt::Trans(const vector<vector<double>>& a) {
	int i, j;
	vector<vector<double>> ans(a[0].size(), vector<double>(a.size()));
	rep(i, a.size()) {
		rep(j, a[i].size()) {
			ans[j][i] = a[i][j];
		}
	}
	return ans;
}

vector<vector<double>> Mt::Trans(const vector<double>& a) {
	return Trans(vector<vector<double>>(1, a));
}

double Mt::Sigmoid(const double d) {
	return  1.0 / (1.0 + exp(-d));
}

vector<double> Mt::Sigmoid(const vector<double>& d) {
	int i;
	vector<double> ans(d.size());
	rep(i, d.size())
		ans[i] = Mt::Sigmoid(d[i]);
	return ans;
}

double Mt::Random(mt19937& mt, ll Min, ll Max) {
	if (Max - Min > INF) {
		printf("Too wide a range\n");
		exit(0);
	}
	ll x = mt(), k = 1000000;
	x %= (Max - Min) * k;
	return (double)x / (double)k + Min;
}
