#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
        float Vs,R,C,w;
        unsigned int n;
        cin>>Vs>>R>>C>>n;
        for(int i = 0; i < n; i++) {
                cin>>w;
                cout<<setiosflags(ios::fixed)<<setprecision(3)
                    <<Vs*w*C/float(sqrt(1/(R*R)+w*w*C*C))<<endl;
        }
        return 0;
}
