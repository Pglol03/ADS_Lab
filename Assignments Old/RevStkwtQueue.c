// C++ code to reverse a stack using queue
#include <stdio.h>

void reverse(stack[int]& stk)
{
	queue[int] qu;

	// Enqueue all into queue
	while (!stk.empty()) {
		qu.push(stk.top());
		stk.pop();
	}

	// Now stack is empty thus push all
	// elements back into the
	// stack - FIFO order
	while (!qu.empty()) {
		stk.push(qu.front());
		qu.pop();
	}
}

// Driver Code
int main()
{
	stack<int> stk;
	stk.push(40);
	stk.push(30);
	stk.push(20);
	stk.push(10);

	// Function Call
	reverse(stk);

	// 40 30 20 10 (top to bottom)
	cout << "After Reverse : (Top to Bottom)"
		<< "\n";
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << "\n";

	return 0;
}
