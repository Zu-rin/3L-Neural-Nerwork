#include "Mymath.hpp"
#include "CSV_Handler.hpp"
#include "Neural_network.hpp"

#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Neural_Network::FillRand(vector<vector<double>>& d) {
	mt19937 mt(time(0));
	int i, j;
	rep(i, d.size()) {
		rep(j, d[i].size()) {
			d[i][j] = Mt::Random(mt, -5, 5);
		}
	}
}

Neural_Network::Neural_Network(int hidden, double rate, int input, int output) {
	layerNum = 2;
	inputNum = input + 1; // 変数数 + バイアス
	outputNum = output;
	hiddenNum = hidden;
	step = 0;
	LRate = rate;

	int i;
	vector<vector<double>> b(hiddenNum, vector<double>(outputNum));
	weight.resize(layerNum);
	weight[0] = vector<vector<double>>(inputNum, vector<double>(hiddenNum));
	weight[1] = vector<vector<double>>(hiddenNum, vector<double>(outputNum));
	rep(i, 2)
		FillRand(weight[i]);

	cell.resize(layerNum + 1);
}

vector<double> Neural_Network::Put_Sample(int dep) {
	if (dep == layerNum) {
		return cell[dep];
	}
	cell[dep + 1] = Mt::MatX(cell[dep], weight[dep]);
	cell[dep + 1] = Mt::Sigmoid(cell[dep + 1]);
	return Put_Sample(dep + 1);
}

void Neural_Network::BP_Learn(const vector<double>& ans) {
	int i, j, dep = 0;
	vector<double> error, dsig;

	error = Mt::Sub(ans, cell[2]);
	dsig = Mt::Matdot(cell[2], Mt::Sub(vector<double>(outputNum, 1.0), cell[2]));

	rep(i, inputNum) {
		vector<double> d(hiddenNum, LRate * cell[dep][i]), ones(hiddenNum, 1.0), ds;
			
		ds = Mt::Matdot(cell[dep + 1], Mt::Sub(ones, cell[dep + 1]));
		d = Mt::Matdot(d, ds);
		vector<vector<double>> a(outputNum);
		rep(j, outputNum) {
			a[j] = vector<double>(hiddenNum, error[j] * dsig[j]);
		}
		vector<vector<double>> miderror = Mt::Matdot(Mt::Trans(weight[dep + 1]), a);
		d = Mt::Matdot(d, miderror[0]);
		weight[dep][i] = Mt::Sum(weight[dep][i], d);
	}
	dep++;
	rep(i, hiddenNum) {
		vector<double> d(outputNum, LRate * cell[dep][i]);
		d = Mt::Matdot(d, Mt::Matdot(error, dsig));
		weight[dep][i] = Mt::Sum(weight[dep][i], d);
	}
}

double Neural_Network::SError(const vector<double>& ans) {
	int i;
	auto def = Mt::Sub(cell[2], ans);
	auto error = Mt::MatX(def, Mt::Trans(def));
	return error[0];
}

double Neural_Network::Learning(const vector<double>& sample) {
	int i;
	cell[0] = vector<double>(sample.begin(), sample.begin() + inputNum - 1);
	cell[0].push_back(1.0);
	vector<double> ans(sample.begin() + inputNum - 1, sample.end());

	auto d = sample;
	auto out = Put_Sample();
	d.insert(d.end(), out.begin(), out.end());

	BP_Learn(ans);
	return SError(ans);
}

void Neural_Network::Run(const int Maxstep, const int reduceRate) {
	const int Bat = 1000, Min = 0, Max = 2;
	int i, k;
	mt19937 mt(time(0));
	vector<double> errorRec(Maxstep);
	rep(k, Maxstep) {
		step++;
		double error = 0.0;
		rep(i, Bat) {
			vector<double> sample(3);
			sample[0] = Mt::Random(mt, Min, Max);
			sample[1] = Mt::Random(mt, Min, Max);
			sample[2] = MyFunc(sample[0], sample[1]);
			error += Learning(sample);
		}
		errorRec[k] = error / (double)Bat;
		printf(" Step:%7d,   Error:  %.10lf\n", step, errorRec[k]);
		if(reduceRate && step % (Maxstep / 16) == 0)
			LRate *= 0.9;
	}
	csv::Put("Error.csv", errorRec);
	return;
}

void Neural_Network::Test(int Samplenum) {
	const int Min = 0, Max = 2;
	int i;
	mt19937 mt(time(0));
	vector<vector<double>> sample;
	rep(i, Samplenum) {
		vector<double> d(2);
		cell[0][0] = d[0] = Mt::Random(mt, Min, Max);
		cell[0][1] = d[1] = Mt::Random(mt, Min, Max);
		auto ans = Put_Sample();
		d.insert(d.end(), ans.begin(), ans.end());
		sample.push_back(d);
	}
	csv::Put("Graph.csv", sample);
	return;
}

double Neural_Network::MyFunc(double& x, double& y) {
	return (sin(x * x + y * y) / (abs(x * y) + 1.0) + 1.0) / 2.0;
}