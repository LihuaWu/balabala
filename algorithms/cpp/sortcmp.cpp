#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int b[] = {1,3,2};
	vector<int> a (b, b+sizeof(b)/sizeof(int));
	sort(a.begin(), a.end());
	for (auto v: a) {
		cout << v << " ";
	}
	cout << endl;

	sort(a.begin(), a.end(), less<int>());
	for (auto v: a) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}
