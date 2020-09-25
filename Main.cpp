#include "Mymath.hpp"
#include "CSV_Handler.hpp"
#include "Neural_network.hpp"

using namespace std;

int main() {
	// nn( 中間層のニューロン数, 学習率 )
	Neural_Network nn(50, 0.1);

	// Run( ステップ数, 学習率の変化{true, false[default]} )
	nn.Run(1000, true);

	//
	nn.Test();
	return 0;
}