#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string mul(string a, string b) {
	string res = "";
	vector <int> v(a.length() + b.length() - 1);
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			v[i + j] += (a[i] - '0') * (b[j] - '0');
		}
	}
	int carry = 0;
	for (int i = a.length() + b.length() - 2; i >= 0; i--) {
		v[i] += carry;
		res += v[i] % 10 + '0';
		carry = v[i] / 10;
	}
	if(carry != 0)
		res += carry + '0';
	reverse(res.begin(), res.end());
	return res;
}

string removeDot(string s) {
	string res = "";
	for(int i = 0; i < s.length(); i++) {
		if (s[i] != '.')
			res += s[i];
	}
	return res;
}

int main() {
	string s;
	int n;
	string res = "1";
	while (cin >> s >> n) {
		res = "1";
		for (int i = 0; i < n; i++) {
			res = mul(removeDot(res), removeDot(s));
		}
		int m = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '.'){
				m = s.length() - i - 1;
				break;
			}
		}
		string result = "";
		for (int i = 0; i < res.length(); i++) {
			if (i == (res.length() - m*n)) {
				result += '.';
			}
			result += res[i];
		}
		// 去掉开头的0
		string finalResult = "";
		int FF = 0;
		for (int i = 0; i < result.length(); i++) {
			if (result[i] != '0')
				FF = 1;
			if (FF)
				finalResult += result[i];
		}
		// 处理xx.xx00的特殊情况
		int flag = 0;
		for (int i = 0; i < finalResult.length(); i++) {
			if (finalResult[i] == '.') {
				flag = 1;
			}
		}
		string Final = "";
		int F = 0;
		if (flag) {
			for (int i = finalResult.length() - 1; i >= 0; i--) {
				if (finalResult[i] != '0')
					F = 1;
				if (F)
					Final += finalResult[i];
			}
		}
		else {
			Final = finalResult;
		}
		reverse(Final.begin(), Final.end());
		//去掉最后的小数点
		string last = Final;
		if (Final.length() <= 1) {
			//如果啥都没有，输出0
			if (last == "")
				last = "0";
		}
		else {
			if (Final[Final.length() - 1] == '.')
				last = Final.substr(0, Final.length() - 1);
		}
		cout << last << endl;
	}
	return 0;
}
