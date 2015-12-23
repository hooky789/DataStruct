#include <iostream>
#include <iomanip>
#include "stack_L.h"

using namespace std;

void main()
{
	LinkStack myStack;
	char str[256],*pt;
	char temp;
	cout<<"Input a string!"<<endl;
	cin.getline(str,256); 
	InitStack_L(myStack);
	pt = str;
	while (*pt != '\0')
	{
		switch(*pt)
		{
		case '(':
		case '[':
		case '{':
			Push_L(myStack,*pt);
			break;
		case ')':
			Pop_L(myStack,temp);
			if (temp != '(')
			{
				cout<<"Not match!"<<endl;
				system("pause");
				return;
			};
			break;
		case ']':
			Pop_L(myStack,temp);
			if (temp != '[')
			{
				cout<<"Not match!"<<endl;
				system("pause");
				return;
			};
			break;
		case '}':
			Pop_L(myStack,temp);
			if (temp != '{')
			{
				cout<<"Not match!"<<endl;
				system("pause");
				return;
			};
			break;
		default:
			break;
		}
		pt++;
	}
	DestroyStack_L(myStack);
	cout<<"Match!!"<<endl;
	system("pause");
}