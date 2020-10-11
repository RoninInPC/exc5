#include<iostream>
#define SIZE 21
int Arr1[SIZE] = { 0,12,4,13,2,14,7,15,11,5,9,8,20,16,3,10,17,6,1,18,19 };
int Arr2[SIZE] = { 0,18,13,6,19,14,1,8,11,17,20,4,15,3,9,2,12,7,5,16,10 };
int Arr3[SIZE] = { 0,16,2,7,13,1,4,18,9,11,20,5,3,10,6,14,19,8,12,17,15 };
int Arr4[SIZE] = { 0,3,10,19,5,11,14,8,2,17,4,16,1,20,6,13,7,18,9,15,12 };
int a = 7;
int b = 7;
int c = 9;
int d = 27;
int e = 6;
bool IsE(int* Arr) {
	for (int i = 0; i < SIZE; i++) {
		if (Arr[i] != i) {
			return false;
		}
	}
	return true;
}
int* PrS(int* Arr1, int* Arr2) {
	int* Arr = new int [SIZE];
	Arr[0] = 0;
	for (int i = 1; i < SIZE; i++) {
		Arr[i] = Arr2[Arr1[i]];
	}
	return Arr;
}
int* PowS(int* Arr, int Pow) {
	int* Arr1=Arr;
	for (int  i= 0; i < Pow; i++) {
		Arr1 = PrS(Arr1, Arr);
	}
	return Arr1;
}
int InversionNumber(int* Arr) {
	int Ans = 0;
	for (int i = 1; i < SIZE-1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (Arr[i] > Arr[j]) {
				Ans++;
			}
		}
	}
	return 0;
}
void Print(int* Arr) {
	for (int i = 1; i < SIZE; i++) {
		std::cout << Arr[i]<<" ";
	}
	std::cout << "\n";
}
int main() {
	int* Arr11 = PowS(Arr1, a);
	int* Arr22 = PowS(Arr2, b);
	int* Arr33 = PowS(Arr3, c);
	int* Arr44 = PowS(Arr4, e);
	Print(Arr11);
	Print(Arr22);
	Print(Arr33);
	Print(Arr44);
	int* Ans = PrS(PrS(PrS(Arr11, Arr22), Arr33), Arr44);
	Print(Ans);
	if (InversionNumber(Ans) % 2 == 1) {
		std::cout << "Nechetno\n";
	}
	else {
		std::cout << "Chetno\n";
	}
	int* Arr5 = Ans;
	int i = 1;
	while (IsE(Arr5)!=true) {
		Arr5=PrS(Arr5, Ans);
		i++;
	}
	std::cout << "Poriadok=" << i << "\n";
	return 0;
}