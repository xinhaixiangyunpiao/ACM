#include <iostream>
using namespace std;
int main(){
        int n,m;
        cin>>n>>m;
        char **ch = new char*[m];
        for(int i = 0; i < m; i++)
                ch[i] = new char[n];
        int *sorted = new int[m];
        int *range = new int[m];
        for(int i = 0; i < m; i++) {
                range[i] = i;
        }
        for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                        cin>>ch[i][j];
        for(int i = 0; i < m; i++) {
                sorted[i] = 0;
                for(int j = 0; j < n; j++) {
                        for(int k = j + 1; k < n; k++) {
                                if(ch[i][j]>ch[i][k])
                                        sorted[i]++;
                        }
                }
        }
        for(int i = 0; i < m; i++) {
                for(int j = i + 1; j < m; j++) {
                        if(sorted[i] > sorted[j]) {
                                int q = sorted[i];
                                sorted[i] = sorted[j];
                                sorted[j] = q;
                                int p = range[i];
                                range[i] = range[j];
                                range[j] = p;
                        }
                }
        }
        for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                        cout<<ch[range[i]][j];
                }
                cout<<endl;
        }
        return 0;
}
