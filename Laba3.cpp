#include <iostream>
int main() {
	int n, s = 1, cnt = 0, min, sum = 0, min_index, temp;
	std::cout << "Enter length of array\n";
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "Enter array\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		if (arr[i] > 0) {
			s *= arr[i];
			cnt++;
		}
	}
	min = arr[0];
	if (cnt == 0) {
		s = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (min > arr[i]) {
			min = arr[i];
			min_index = i;
		}
	} 
	for (int i = 0; i < min_index; ++i) {
		sum += arr[i];
	}
	for (int i = 0; i < n; ++i) {//buble sort
		for (int j = 0; j < n - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}


		}
	}

	int qunt_of_even = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2 == 0) {
			qunt_of_even++;
		}
	}
	int* new_arr = new int[n];
	int uneven = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2 == 0) {
			new_arr[uneven] = arr[i];
			uneven++;
		}
	}
	for (int i = 0; i < n;  ++ i) {
		if (arr[i] % 2 != 0) {
			new_arr[qunt_of_even] = arr[i];
			qunt_of_even++;
		}
	}
	delete[] arr;

	std::cout << "Multiplication = " << s << '\n';
	std::cout << "Sum = " << sum << '\n';

	for (int i = 0; i < n; ++i) {
		std::cout << new_arr[i] << ' ';
	}
	delete[] new_arr;
	return 0;
}
