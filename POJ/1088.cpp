// //解法一  BFS  超时
#include <iostream>
#include <queue>
using namespace std;

int height[101][101];
int length[101][101];
int R,C;

struct Node {
        int x;
        int y;
        int step;
        Node(int X,int Y,int Step) : x(X),y(Y),step(Step){
        }
};

bool judge(int x,int y){
        bool flag = 0;
        if(x > 0) {
                if(height[x - 1][y] < height[x][y])
                        flag = 1;
        }
        if(x < R - 1) {
                if(height[x + 1][y] < height[x][y]) {
                        flag = 1;
                }
        }
        if(y > 0) {
                if(height[x][y - 1] < height[x][y]) {
                        flag = 1;
                }
        }
        if(y < C - 1) {
                if(height[x][y + 1] < height[x][y]) {
                        flag = 1;
                }
        }
        return flag;
}

void search(int initialX,int initialY){
        cout<<"Search road:     "<<initialX<<"   "<<initialY<<endl;
        Node node(initialX,initialY,0);
        int MAX = 0;
        queue <Node> q;
        while(!q.empty())
                q.pop();
        q.push(node);
        while(!q.empty()) {
                node = q.front();
                cout<<"node "<<node.step<<"    x:   "<<node.x<<"     y:   "
                    <<node.y<<"    value:    "<<height[node.x][node.y]<<endl;
                q.pop();
                if(node.x <= initialX) {
                        if(node.y < initialY) {
                                if(node.step + length[node.x][node.y] > MAX)
                                        MAX = node.step + length[node.x][node.y];
                                continue;
                        }
                }
                if(!judge(node.x,node.y)) {
                        if(node.step > MAX)
                                MAX = node.step;
                        continue;
                }
                node.step++;
                if(node.x > 0) {
                        if(height[node.x - 1][node.y] < height[node.x][node.y]) {
                                Node NextNode(node.x - 1,node.y,node.step);
                                q.push(NextNode);
                        }
                }
                if(node.x < R - 1) {
                        if(height[node.x + 1][node.y] < height[node.x][node.y]) {
                                Node NextNode(node.x + 1,node.y,node.step);
                                q.push(NextNode);
                        }
                }
                if(node.y > 0) {
                        if(height[node.x][node.y - 1] < height[node.x][node.y]) {
                                Node NextNode(node.x,node.y - 1,node.step);
                                q.push(NextNode);
                        }
                }
                if(node.y < C - 1) {
                        if(height[node.x][node.y + 1] < height[node.x][node.y]) {
                                Node NextNode(node.x,node.y + 1,node.step);
                                q.push(NextNode);
                        }
                }
        }
        length[initialX][initialY] = MAX;
}

int main(){
        cin>>R>>C;
        for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                        cin>>height[i][j];
                }
        }
        for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                        search(i,j);
                }
        }
        int max = 0;
        for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                        if(length[i][j] > max) {
                                max = length[i][j];
                        }
                }
        }
        cout<<max+1<<endl;
        return 0;
}

//解法二 DFS （按理说BFS应该比DFS快，
//DFS重复利用结点后速度就比BFS快了
// #include <iostream>
// using namespace std;
// int R,C;
// int cnt[101][101];
// int visited[101][101];
// int Max,result;
// int dic[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
//
// int dfs(int x,int y){
//         int result = 1;
//         if(visited[x][y])
//                 return visited[x][y];
//         for(int k = 0; k < 4; k++) {
//                 int tx = x + dic[k][0];
//                 int ty = y + dic[k][1];
//                 if(tx >= 0 && tx < R && ty >= 0 && ty < C
//                    && cnt[tx][ty] < cnt[x][y]) {
//                         result = max(result,dfs(tx,ty));
//                         visited[x][y] = visited[x][y]<result ? result+1 : visited[x][y];
//                 }
//         }
//         return visited[x][y];
// }
//
// int main(){
//         cin>>R>>C;
//         for(int i = 0; i < R; i++) {
//                 for(int j = 0; j < C; j++) {
//                         cin>>cnt[i][j];
//                 }
//         }
//         for(int k = 0; k < R; k++) {
//                 for(int d = 0; d < C; d++) {
//                         visited[k][d]= 0;
//                 }
//         }
//         for(int i = 0; i < R; i++) {
//                 for(int j = 0; j < C; j++) {
//                         dfs(i,j);
//                 }
//         }
//         int ans = 1;
//         for(int i = 0; i < R; i++) {
//                 for(int j = 0; j < C; j++) {
//                         ans = max(ans,visited[i][j]);
//                 }
//         }
//         cout<<ans<<endl;
// }
