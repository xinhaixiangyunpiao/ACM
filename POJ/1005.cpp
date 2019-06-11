#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.1415926

int main() {
	int N;
	cin >> N;
	double x, y;
	int res;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		res = ceil(double(pi * (pow(x, 2) + pow(y, 2))) / 100);
		cout << "Property " << i + 1 << ": This property will begin eroding in year " << res << "." << endl;
 	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
