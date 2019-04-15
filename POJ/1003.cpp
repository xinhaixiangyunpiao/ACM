#include <iostream>
using namespace std;

int func(float cc){
        float result = 0;
        int n = 2;
        while(result < cc) {
                result += 1.0/n;
                n++;
        }
        return n - 2;
}

int main(){
        float length;
        while(cin>>length) {
                if(length == 0)
                        break;
                cout<<func(length)<<" card(s)"<<endl;
        }
        return 0;
}
