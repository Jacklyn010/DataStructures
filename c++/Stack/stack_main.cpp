#include "stack.h"
#include <iostream>

using namespace std;

int main(void) {
	Stack stack;
	
	stack.push(5);
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);
	stack.push(0);
	
	cout << "Peek: " << stack.peek() << endl;
	
	while (stack.hasNext()) {
		cout << stack.pop() << endl;
	}
	
	return 0;
}
