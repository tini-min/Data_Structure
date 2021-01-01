# Data Structure Assignments
* [Assignment1](#assignment1)
* [Assignment2](#assignment2)
* [Assignment3](#assignment3)

## Assignment1
Change the LinkedStack implemented in class to a generic LinkedStack using a template.   
Compress the project folder excluding git and executable files and submit.
Please refer to the attached main.cpp and use the class name. (Do not modify it!)

Given Code (main.cpp)
```c++
#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
	cout << "201511118 SeongHun Min" << endl << endl;

	LinkedStack<char> stack1;
	stack1.push('A');
	stack1.push('C');
	stack1.push('D');
	stack1.push('E');
	stack1.push('F');
	stack1.push('G');


	cout <<"Stack1 Test" << endl;
	cout <<"size: " << stack1.size() << endl;
	cout <<"top entry: " << stack1.top() << endl;
	stack1.pop();
	cout << "top entry: " << stack1.top() << endl;

	LinkedStack<int> stack2;
	stack2.push(1);
	stack2.push(2);
	stack2.push(3);
	stack2.push(4);
	stack2.push(5);

	cout << endl << "Stack2 Test" << endl;
	while (!stack2.empty()) {
		cout << "top entry: " << stack2.top() << endl;
		stack2.pop();
	}
}
```
Desired Result

![Example](/Assignment1/Assignment1.JPG)

Print your name and student number on the first line of the print screen (see attached photo).

![Result](/Assignment1/Result.jpg)

If you want to see the code what I made, just check the attached file.

[LinkedStack.h](/Assignment1/LinkedStack.h)

## Assignment2
Complete a program by referring to the file.   
<object data="/Assignment2/Assignment2.pdf" type="application/pdf">
       <embed src="/Assignment2/Assignment2.pdf">
           This browser does not support PDFs. Please download the PDF to view it: <a href=""/Assignment2/Assignment2.pdf"">Download PDF</a>.</p>
       </embed>
</object>
i.e. implement an appropriate binary tree
## Assignment3
Complete a program by referring to the file.   
i.e. make a sorting program with O(n log n)