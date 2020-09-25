#include "Mymath.hpp"
#include "CSV_Handler.hpp"
#include "Neural_network.hpp"

using namespace std;

int main() {
	// nn( ���ԑw�̃j���[������, �w�K�� )
	Neural_Network nn(50, 0.1);

	// Run( �X�e�b�v��, �w�K���̕ω�{true, false[default]} )
	nn.Run(1000, true);

	//
	nn.Test();
	return 0;
}