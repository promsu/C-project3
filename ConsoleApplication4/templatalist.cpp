// ConsoleApplication4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Array.h"
using namespace std;


int main()
{
	Array<int> a(10);
	int n, count = 0;
	cout << "Enter a value >= 2 as upper limit for prime numbers: ";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		bool isprime = true;
		for (int j = 0; j < count; j++) {
			if (i % a[j]==0) {
				isprime = false;
				break;
			}
		}
		if (isprime) {
			if (count == a.getsize())
				a.resize(count * 2);
			a[count++] = i;
		}
	}
	for (int i = 0; i < count; i++)
		cout << setw(8) << a[i];
	cout << endl;
	return 0;
}