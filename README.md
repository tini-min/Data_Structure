# Data Structure Assignments
* [Assignment1](#assignment1)
* [Assignment2](#assignment2)
* [Assignment3](#assignment3)

## Assignment1
Change the LinkedStack implemented in class to a generic LinkedStack using a template.   
Compress the project folder excluding git and executable files and submit.
Please refer to the attached main.cpp and use the class name. (Do not modify it!)

__Given Code (main.cpp)__
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
__Desired Result__

![Example](/Assignment1/Assignment1.JPG)

Print your name and student number on the first line of the print screen (see attached photo, "Result").

__Result__
![Result](/Assignment1/Result.jpg)

If you want to see the code what I made, just check the attached file.

[LinkedStack.h](/Assignment1/LinkedStack.h)

## Assignment2
Write a program that performs the following operations on the given input file and outputs it.
1. Print the formula displayed in prefix or postfix format in infix format.
2. Calculate the formula for the given variable (a-z). However, the answer should be expressed as a rounded integer.

You should implement a binary tree for this problem

__Example__
![Example](/Assignment2/Example.jpg)

__Result__
|no|fix.in|fix.out|
|:---|---:|---:|
|number of equation|6||
|1|I + * 2 - a 1 * 3 b E|((2*(a-1))+(3*b))|
||a 7 b 8 E|36|
|2|I * / 2 - 3 b / 9 - 7 3 E|((2/(3-b))*(9/(7-3)))|
||b 7 E|-1|
|3|P 2 a 1 - * 3 b * / E|((2*(a-1))/(3*b))|
||b 2 a -1 E|-1|
|4|P c 3 * 4 - a 5 * * E|(((c*3)-4)*(a*5))|
||c 2 a 4 E |40|
|5|I a E|a|
||a 5 E|5|
|6|P b E|b|
||b 8 E|8|

If you want to see the code what I made, just check the attached file.

[fix_201511118_민성훈.cpp](/Assignment2/fix_201511118_민성훈.cpp)

## Assignment3
Given m sequences sorted in ascending order, write an efficient program that combines these sequences and outputs one sorted sequence.  
> ps. Efficient program implies program with at most O(n log n) at this assignment

__Example__
![Example](/Assignment3/Example.jpg)

Since "heap sort" has time complexity at most O(n log n), I implemented heap sort.  

> If you want to see the code what I made, just check the attached file.
> [O(n log n)](/Assignment3/sortedlists_201511118_민성훈.cpp)

But, since m sequence are sorted, we can implement the sort program with O(m log n).  
I`ll implement it later.