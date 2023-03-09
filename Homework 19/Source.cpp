#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
//Task 1
int divisor(int num1, int num2) {
	if (num1 > num2) {
		for (int i = num1 / 2 + 1; i > 1; i--)
			if (num1 % i == 0 && num2 % i == 0)
				return i;

	}
	else
		if (num2 > num1)
			for (int i = num2 / 2 + 1; i > 1; i--)
				if (num1 % i == 0 && num2 % i == 0)
					return i;
}
//Task 2
int mirror_number(int num) {
	int mirr = 0;
	int tmp;
	int clone = num;
	if (num <= 0)
		return -1;
	else
		for (int i = 1; num > 0; i *= 10) {
			num /= 10;
			tmp = i;
		}
	while (tmp != 0) {
		mirr += (clone % 10) * tmp;
		clone /= 10;
		tmp /= 10;
	}

	return mirr;


}
//Task 3
int arr_first_num(int arr[], const int length, int num) {
	int tmp = -1;
	for (int i = 0; i < length; i++) {
		if (arr[i] == num) {
			tmp = i;
			break;

		}

	}std::sort(arr + tmp + 1, arr + length);
	return tmp;



}
//Task 4
void fill_arr_AB(int arr[], const int length, int A, int B) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (B - A + 1) + A;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//Task 1

	std::cout << "Task 1.\nEnter two numbers ->";
	std::cin >> n >> m;
	std::cout << "common divisor of " << n << " and " << m << " is " << divisor(n, m) << "\n\n";

	//Task 2

	std::cout << "Enter any number ->";
	int num1;
	std::cin >> num1;
	if (mirror_number(num1) == -1)
		std::cout << "Cant mirror this number!\n\n";
	else
		std::cout << "Your mirrored number: " << mirror_number(num1) << "\n\n";

	//Task 3

	std::cout << "Array:\n\n";
	int const length1 = 10;
	int arr1[length1]{ 2,5,10,3,6,10,7,8,9,10 };

	std::cout << "[";
	for (int i = 0; i < length1; i++)
		std::cout << arr1[i] << " ,";
	std::cout << "\b\b]\nFirst position for sorting: " << arr_first_num(arr1, length1, 10) << "\n\nResult:\n";
	std::cout << "[";
	for (int i = 0; i < length1; i++)
		std::cout << arr1[i] << " ,";
	std::cout << "\b\b]\n";

	//Task 4
	int A, B;
	int const length2 = 10;
	int arr2[length2]{};
	std::cout << "Enter two numbers to fill the array, first number must be lower than second ->";
	std::cin >> A >> B;
	fill_arr_AB(arr2, length2, A, B);
	std::cout << "[";
	for (int i = 0; i < length2; i++)
		std::cout << arr2[i] << " ,";
	std::cout << "\b\b]\n";

	return 0;
}