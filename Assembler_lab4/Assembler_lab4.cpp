#include <iostream>

using namespace std;

int main()
{
	int A[5];
	int sum = 0;
	int b;
	cout << "Enter 5 elements of the array: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
	}
	cout << "Enter b: ";
	cin >> b;


	_asm
	{
		mov ecx, 5;
		lea esi, A;
		mov ebx, b;
		xor eax, eax;

	loop_start:
		mov edx, [esi];
		cmp edx, 0;
		jle skip;

		cmp edx, ebx;
		jg skip;
		add eax, edx;

	skip:
		add esi, 4;
		dec ecx;
		jnz loop_start;
		mov sum, eax;
	}
	cout << sum;
}