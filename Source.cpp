#include <iostream>
void del(int* arr0, int* arr1) {
	delete arr0;
	delete arr1;
}

int get_size() {
	int size = 0;
	std::cout << "Number of elements:\n";
	while (size <= 0) {
		std::cin >> size;
		if (size <= 0) {
			std::cout << "Incorrect input";
			continue;
		}
		return size;
	}
}
int input_from_keyboard(int* arr, const int& n) {
	int s = 1;
	int cnt = 0;
	std::cout << "Enter array\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		if (arr[i] > 0) {
			s *= arr[i];
			cnt++;
		}
	}
	if (cnt == 0) {
		s = 0;
	}
	return s;
}
void swap(int& a, int& b) {
	int help = b;
	b = a;
	a = help;
}


int input_random(int * arr, const int& n) {
		int a = 0, b = 0;
		int cnt = 0;
		int s = 1;
		while (a == b) {
			std::cout << "Enter board valuse = ";
			std::cin >> a >> b;
			if (a > b) {
				swap(a, b);
			}
		}


		for (int i = 0; i < n; ++i) {
			arr[i] = a + ((rand() % b) + 1);
			if (arr[i] > 0) {
				s *= arr[i];
				cnt++;
			}
		}
		if (cnt == 0) {
			s = 0;
		}
		return s;
	}

void out_arr(int* arr, const int& n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}


int filling_arr(int* arr0, const int& n0) {
	int s = 1;
	int condition = 0;
	while (condition != 1 && condition != 2) {
		std::cout << "Enter codition 1 - input keyboard, 2 - random values = ";
		std::cin >> condition;
	}

	switch (condition) {
	case 1:
		s = input_from_keyboard(arr0, n0);
	case 2:
		s = input_random(arr0, n0);
		std::cout << "Array generared " << '\n';
		out_arr(arr0, n0);
	}
	return s;
}








int main() {
	int n = get_size(), s = 1, min, sum = 0, min_index, temp;
	

	int* arr = new int[n];

	s = filling_arr(arr, n);
	
	min = arr[0];
	
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
	del(arr, new_arr);
	return 0;
}