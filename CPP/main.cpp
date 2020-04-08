#include <iostream>
#include <stdarg.h>
#include <initializer_list>

using namespace std;

#define numberof(a) (sizeof(a) / sizeof(a[0]))

void Print1(int cnt, ...)
{
	cout << "Print1:";

	va_list argptr;
	va_start(argptr, cnt);

	for (int i = 0; i < cnt; i++)
	{
		cout << " " << va_arg(argptr, int);
	}

	cout << endl;
}

void Print2(initializer_list<int> args)
{
	cout << "Print2:";
	for (auto arg : args)
	{
		cout << " " << arg;
	}

	cout << endl;
}

void Print3a()
{
	cout << endl;
}

template<typename T1, typename... T2>
void Print3a(T1 arg, T2... args)
{
	cout << " " << arg;
	Print3a(args...);
}

template<typename... T>
void Print3(T... args)
{
	cout << "Print3:";
	Print3a(args...);
}

template<typename... T>
void Print4(T... args)
{
	cout << "Print4:";
	int a[] = { args... };
	int len = numberof(a);
	for (int i = 0; i < len; i++)
	{
		cout << " " << a[i];
	}
	cout << endl;
}

int main()
{
	Print1(3, 1, 2, 3);
	Print2({ 1, 2, 3 });
	Print3(1, 2, 3);
	Print4(1, 2, 3);
}