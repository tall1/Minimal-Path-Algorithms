// Name: Tal Lev
// Id: 312495955
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "myString.h"
using namespace std;
using namespace myStr;
int main(int argc, char** argv) {
	DynamicArray<LinkedList<int>> arr(3);
	
	int j, count = 0;
	for (auto& i : arr) {
		cout << "B4: ";
		i.print();
		for (j = 0; j < 4; j++) {
			i.insertEnd(count++);
		}
		cout << "After: ";
		i.print();
	}

}