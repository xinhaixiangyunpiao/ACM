#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;       //按字典序从小到大排列 
}

int hashFunc(string x) {
	int res = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '-') {

		}
		else {
			res *= 10;
			res += x[i] - '0';
		}
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	map <string, int> Map;
	vector<pair<string, int>> V;
	for (int i = 0; i < N; i++){
		string s;
		cin >> s;
		string res = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '-')
				continue;
			else if (s[j] >= 'A' && s[j] <= 'Z') {
				if (s[j] >= 'A' && s[j] <= 'C') {
					res += '2';
				}
				else if (s[j] >= 'D' && s[j] <= 'F') {
					res += '3';
				}
				else if (s[j] >= 'G' && s[j] <= 'I') {
					res += '4';
				}
				else if (s[j] >= 'J' && s[j] <= 'L') {
					res += '5';
				}
				else if (s[j] >= 'M' && s[j] <= 'O') {
					res += '6';
				}
				else if (s[j] >= 'P' && s[j] <= 'S') {
					res += '7';
				}
				else if (s[j] >= 'T' && s[j] <= 'V') {
					res += '8';
				}
				else if (s[j] >= 'W' && s[j] <= 'Y') {
					res += '9';
				}
			}
			else if (s[j] >= '0' && s[j] <= '9') {
				res += s[j];
			}
			if (res.length() == 3)
				res += '-';
		}
		Map[res]++;
	}	
	int count = 0;
	for (map<string,int>::iterator i = Map.begin(); i != Map.end(); i++)
		V.push_back(*i);
	sort(V.begin(), V.end(), cmp);
	for (vector<pair<string, int>>::iterator i = V.begin(); i != V.end(); i++) {
		if (i->second > 1) {
			cout << i->first << " " << i->second << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "No duplicates." << endl;
	return 0;
}