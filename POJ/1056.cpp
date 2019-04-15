#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node {
        string str;
        int length;
};

bool compare(node a,node b){
        return a.length < b.length;
}

int main(){
        string s;
        vector <node> v;
        int count = 0;
        while(cin >> s) {
                if(s == "9") {
                        count++;
                        sort(v.begin(),v.end(),compare);
                        int size = v.size();
                        int repet = 0;
                        for(int i = 0; i < size; i++) {
                                for(int j = i + 1; j < size; j++) {
                                        string str1 = v[i].str;
                                        string str2 = v[j].str;
                                        int len1 = v[i].length;
                                        int flag = 1;
                                        for(int k = 0; k < len1; k++) {
                                                if(str1[k] == str2[k]) {

                                                }else{
                                                        flag = 0;
                                                }
                                        }
                                        if(flag == 1) {
                                                repet = 1;
                                                break;
                                        }
                                }
                                if(repet)
                                        break;
                        }
                        if(repet) {
                                cout << "Set " << count << " is not immediately decodable" << endl;
                        }else{
                                cout << "Set " << count << " is immediately decodable" << endl;
                        }
                        v.clear();
                }else{
                        node newNode;
                        int len = s.length();
                        newNode.length = len;
                        newNode.str = s;
                        v.push_back(newNode);
                }
        }
        return 0;
}
