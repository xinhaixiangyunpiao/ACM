// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// string InputConvert(string s){
//     int i = 0,j = s.length()-1;
//     while(s[i] == '0' && i <= j) 
//         i++;
//     while(s[j] == '0' && i <= j)
//         j--;
//     string res = "";
//     for(int k = i; k <= j; k++)
//         res += s[k];
//     return res == "" ? "0" : res;
// }

// string STRMUL(string a, string b){
//     vector<int> A;
//     vector<int> B;
//     int PosA = a.length(),PosB = b.length();
//     for(int i = 0; i < a.length(); i++){
//         if(a[i] != '.')
//             A.push_back(a[i]-'0');
//         else
//             PosA = i;
//     }
//     for(int i = 0; i < b.length(); i++){
//         if(b[i] != '.')
//             B.push_back(b[i]-'0');
//         else
//             PosB = i;
//     }
//     int Len_A = A.size();
//     int Len_B = B.size();
//     vector <int> S(Len_A+Len_B-1);
//     for(int i = 0; i < Len_A; i++){
//         for(int j = 0; j < Len_B; j++){
//             S[i+j] += A[i]*B[j];
//         }
//     }
//     int C = 0;
//     for(int i = Len_A+Len_B-2; i >= 0; i--){
//         int temp = S[i];
//         S[i] = (S[i]+C)%10;
//         C = (temp+C)/10;
//     }
//     string jin = to_string(C);
//     jin = jin == "0" ? "" : jin;
//     string res = ""; 
//     int dot = jin.length() + PosA + PosB - 1;
//     if(dot < 0){
//         res += ".";
//         for(int i = 0; i < -1*dot; i++)
//             res += "0";
//     }
//     res += jin;
//     for(int i = 0; i < Len_A+Len_B-1; i++){
//         if(i == dot)
//             res += '.';  
//         res += S[i] + '0';
//     }
//     return res;
// }

// int main(){
//     string u = "0.0314";
//     string v = "0.0314";
//     cout << STRMUL(u,v) << endl;
//     return 0;
//     string a;
//     int n;
//     while(cin >> a >> n){
//         string op;
//         op = InputConvert(a);
//         string res = "1";
//         for(int i = 0; i < n; i++){
//             res = STRMUL(res,op);
//         }
//         cout << res << endl;
//     }
//     return 0;
// }

//#include <stdio.h>
//_=1;main($){for(;_%$?:(_+=$=1);++$*$>_&&printf("%i|",$=_));}
