#include <iostream>
using namespace std;

int N;
int Catalan[20] = {1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,
                   742900,2674440,9694845,35357670,129644790,477638700};

int GetN(int n){
        int sum = 0;
        for(int i = 0; i < 20; i++) {
                sum += Catalan[i];
                if(sum > n) {
                        return i;
                }
        }
        return 0;
}

int GetOrder(int n){
        int sum = 0;
        int last = 0;
        for(int i = 0; i < 20; i++) {
                sum += Catalan[i];
                if(sum > n) {
                        return (n - last);
                }
                last += Catalan[i];
        }
        return 0;
}

int GetLength(int n){
        int sum = 0;
        for(int i = 0; i < 20; i++) {
                sum += Catalan[i];
                if(sum > n) {
                        return Catalan[i];
                }
        }
        return 0;
}

void func(int N,int Order,int Length){
        if(N == 1) {
                cout<<"X";
                return;
        }
        int LeftNum = 0;
        int RightNum = 0;
        int sum = 0;
        int last = 0;
        int newLeftOrder;
        int newRightOrder;
        int newLength;
        int o = Order;
        for(int i = 0; i < N; i++) {
                sum += Catalan[i]*Catalan[N - i - 1];
                if(sum > Order) {
                        LeftNum = i;
                        newLength = Catalan[i]*Catalan[N - i - 1];
                        o = Order - last;
                        int s = 0;
                        newLeftOrder = 0;
                        for(int j = 0; j < Length; j++) {
                                s += Catalan[N - i - 1];
                                if(s > o) {
                                        newLeftOrder = j;
                                        newRightOrder = Catalan[N - i - 1] - (s - o);
                                        break;
                                }
                        }
                        break;
                }
                last += Catalan[i]*Catalan[N - i - 1];
        }
        RightNum = N - LeftNum - 1;
        if(LeftNum > 0) {
                cout<<"(";
                func(LeftNum,newLeftOrder,newLength);
                cout<<")";
        }
        cout<<"X";
        if(RightNum > 0) {
                cout<<"(";
                func(RightNum,newRightOrder,newLength);
                cout<<")";
        }
}

int main(){
        while(1) {
                cin>>N;
                if(N == 0)
                        break;
                func(GetN(N),GetOrder(N),GetLength(N));
                cout<<endl;
        }
        return 0;
}
