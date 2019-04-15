#include <iostream>
using namespace std;

int k,m;
int length;

bool func(int deep){
        for(int i = 1; i < k; i++) {
                if(deep > 2*k) {
                        deep = deep % (2*k);
                }
                if(deep <= k)
                        return false;
                length--;
                deep = (deep + m - 1) % length;
                if(deep == 0)
                        deep = length;
        }
        return true;
}

int main(){
        while(1)
        {
                cin>>k;
                if(k == 0)
                        break;
                m = k + 1;
                while(1) {
                        if(m % (k + 1) != 0 && m % (k + 1) != 1) {
                                m++;
                                continue;
                        }
                        length = 2*k;
                        if(func(m))
                                break;
                        m++;
                }
                cout<<m<<endl;
        }
        return 0;
}
