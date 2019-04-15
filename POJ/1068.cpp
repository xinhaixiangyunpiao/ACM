#include <iostream>
using namespace std;
int main(){
        int *p;
        int *w;
        char *s;
        int N;
        cin>>N;
        for(int i = 0; i < N; i++) {
                int length = 0;
                cin>>length;
                p = new int[length];
                w = new int[length];
                s = new char[2*length];
                for(int i =0; i < length; i++) {
                        cin>>p[i];
                }
                for(int i = 0; i < 2*length; i++) {
                        s[i] = '(';
                }
                int temp = p[0];
                for(int i = 0; i < length; i++) {
                        s[temp] = ')';
                        temp += p[i+1] - p[i] + 1;
                }
                int o =0;
                for(int i = 0; i < 2*length; i++) {
                        if(s[i] == ')') {
                                int number = 0;
                                int n = 0;
                                for(int j = i - 1; j >= 0; j--) {
                                        if(s[j] == '(' && number == 0) {
                                                n++;
                                                w[o] = n;
                                                o++;
                                                break;
                                        }else if(s[j] == '(') {
                                                number--;
                                                n++;
                                        }else{
                                                number++;
                                        }
                                }
                        }
                }
                for(int i = 0; i < length; i++) {
                        cout<<w[i]<<" ";
                }
                cout<<endl;
        }
        delete p;
        delete w;
        delete s;
        return 0;
}
