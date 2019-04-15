#include <iostream>
using namespace std;

int N;
int **p;
int **temp;

int func(){
        int sb = 0;
        temp = new int*[N];
        for(int i = 0; i < N; i++) {
                temp[i] = new int[N];
        }
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        sb = 0;
                        for(int k = 0; k <= i; k++) {
                                for(int o = 0; o <= j; o++)
                                        sb += p[k][o];
                        }
                        temp[i][j] = sb;
                }
        }
        int max = 0;
        int sum = 0;
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        for(int k = i; k < N; k++) {
                                for(int r = j; r < N; r++) {
                                        if(i == 0 && j == 0) {
                                                sum = temp[k][r];
                                        }
                                        else if(i != 0 && j == 0) {
                                                sum = temp[k][r] - temp[i-1][r];
                                        }
                                        else if(i == 0 && j != 0) {
                                                sum = temp[k][r] - temp[k][j-1];
                                        }
                                        else{
                                                sum = temp[k][r] - temp[i-1][r] - temp[k][j-1] + temp[i-1][j-1];
                                        }
                                        if(sum > max)
                                                max = sum;
                                }
                        }
                }
        }
        return max;
}

int main(){
        cin>>N;
        p = new int*[N];
        for(int i = 0; i < N; i++) {
                p[i] = new int[N];
        }
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        cin>>p[i][j];
                }
        }
        cout<<func()<<endl;
        cout<<endl;
        delete p;
        delete temp;
        return 0;
}
