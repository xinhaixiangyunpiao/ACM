#include <iostream>
#include <string>
using namespace std;

enum Mg {
        VISIT,
        BACK,
        FORWARD,
        QUIT,
        HOLD
};

class Manage {
public:
        Manage(){
                str = "";
                number = 0;
        }
        string getManage(){
                cin>>str;
                number++;
                return str;
        }
        Mg judge(){
                getManage();
                if(str == "VISIT")
                        return VISIT;
                else if(str == "BACK")
                        return BACK;
                else if(str == "FORWARD")
                        return FORWARD;
                else if(str == "QUIT")
                        return QUIT;
                else {
                        return HOLD;
                }
        }
private:
        string str;
        int number;
};

int main(){
        string trace[100];
        trace[0] = "http://www.acm.org/ ";
        int count = 0;
        Manage manage;
        Mg msg = BACK;
        while(msg != QUIT) {
                msg = manage.judge();
                if(msg == VISIT) {
                        count++;
                        cin>>trace[count];
                        for(int i = count + 1; i < 100; i++) {
                                trace[i] = " ";
                        }
                        cout<<trace[count]<<endl;
                }
                else if(msg == BACK) {
                        if(count == 0)
                                cout<<"Ignored"<<endl;
                        else{
                                count--;
                                cout<<trace[count]<<endl;
                        }
                }
                else if(msg == FORWARD) {
                        count++;
                        if(trace[count] != " ") {
                                cout<<trace[count]<<endl;
                        }
                        else{
                                cout <<"Ignored"<<endl;
                                count--;
                        }
                }
                else if(msg == HOLD) {
                        cout<<trace[count]<<endl;
                }
        }
        return 0;
}
