#include "TreeNode.h"
using namespace std;
ostream& operator<<(ostream& out, const Pair& pair) {
	if (pair.character == '\n')
		out << "Character: '\\n', Frequency: " << pair.freq;
	else
		out << "Character: '" << pair.character << "', Frequency: " << pair.freq;
	return out;
}
