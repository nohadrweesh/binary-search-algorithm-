#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
	int left = 0, right = (int)a.size()-1;
	
	int mid;
	while (left <= right){
		mid = left + (right - left) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x)
			left = mid + 1;
		else// if (a[mid] > x)
			right = mid - 1;

	}
	return -1;
}

int linear_search(const vector<int> &a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}
void test_solution(){
	int n = rand() % 20 + 2;
	std::cout << n << "\n";
	vector<int>a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		a[i] = rand() % 100;
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	std::cout << "linear ----- binary" << "\n";
	for (size_t i = 0; i < a.size(); ++i) {
		int l = linear_search(a, a[i]);
		int b = binary_search(a, a[i]);
		if (l == b){
			std::cout << l << " " << b << '\n ';
			std::cout << "OK\n";
		}
		else{
			std::cout << l << " " << b << '\n ';
			std::cout << "wrong\n";
			break;
		}
	}



}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		std::cout << binary_search(a, b[i]) << ' ';
		//std::cout << linear_search(a, b[i]) << ' ';
	}
	//test_solution();
	//system("pause");
}
