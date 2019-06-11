#include <iostream>
using namespace std;

int main() {
	double sum = 0;
	double now = 0;
	for (int i = 0; i < 12; i++) {
		cin >> now;
		sum += now;
	}
	cout <<  "$" << sum / 12  << endl;
	return 0;
}
