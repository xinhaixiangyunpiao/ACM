/**
 * 八数码问题（双向广搜+哈希去重）
 * @param X    [description]
 * @param Y    [description]
 * @param Step [description]
 */
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
char pos[3][3];
int hashsize = 1000003;
int hash1[1000003] = {0};
int hash2[1000003] = {0};
char Road1[1000003][30] = {0};
char Road2[1000003][30] = {0};

struct Node {
        int x;
        int y;
        int step;
        char state[3][3];
        char road[30];
        Node(int X,int Y,int Step) : x(X),y(Y),step(Step){
        }
};

struct Mem {
        char trace[30];
        char state[3][3];
};

Mem Crash1[400000];
Mem Crash2[400000];
int temp1 = 0;
int temp2 = 0;
int final = 0;

int Hash(Node node){
        int result = 0;
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        result *= 10;
                        if(node.state[i][j] != 120) {
                                result += node.state[i][j] - 48;
                        }
                }
        }
        result %= hashsize;
        return result;
}

int HashAgain(Node node){
        int result = 0;
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        result *= 10;
                        if(node.state[i][j] != 120) {
                                result += node.state[i][j] - 48;
                        }
                }
        }
        result /= hashsize;
        return result;
}

bool JUDGE(){
        char p[9];
        p[0] = pos[0][0];
        p[1] = pos[0][1];
        p[2] = pos[0][2];
        p[3] = pos[1][0];
        p[4] = pos[1][1];
        p[5] = pos[1][2];
        p[6] = pos[2][0];
        p[7] = pos[2][1];
        p[8] = pos[2][2];
        int sum = 0;
        for(int i = 0; i < 9; i++) {
                if(p[i] != 120) {
                        for(int j = 0; j < i; j++) {
                                if(p[j] != 120) {
                                        if(p[i] < p[j])
                                                sum++;
                                }
                        }
                }
        }
        if(sum%2 == 1)
                return 0;
        else
                return 1;
}

int judgeAgain(Node node1,Node node2){
        int flag = 1;
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        if(node1.state[i][j] != node2.state[i][j])
                                flag = 0;
                }
        }
        return flag;
}

int judge(Node node1,Node node2){
        if(hash2[Hash(node1)] == 0 && hash1[Hash(node2)] == 0) {
                if(judgeAgain(node1,node2)) {
                        return 5;
                }
                return 0;
        }
        if(hash2[Hash(node1)] == 0) {

        }
        else if(hash2[Hash(node1)] == HashAgain(node1))
                return 1;
        else{
                for(int i = 0; i < temp2; i++) {
                        int flag = 1;
                        for(int j = 0; j < 3; j++) {
                                for(int k = 0; k < 3; k++) {
                                        if(node1.state[j][k] != Crash2[i].state[j][k])
                                                flag = 0;
                                }
                        }
                        if(flag) {
                                final = i;
                                return 3;
                        }
                }
                for(int i = 0; i < 3; i++) {
                        for(int j = 0; j < 3; j++) {
                                Crash1[temp1].state[i][j] = node1.state[i][j];
                        }
                }
                int i = 0;
                for(i = 0; i < node1.step; i++) {
                        Crash1[temp1].trace[i] = node1.road[i];
                }
                Crash1[temp1].trace[i] = '\0';
                temp1++;
                return 0;
        }
        if(hash1[Hash(node2)] == 0) {

        }
        else if(hash1[Hash(node2)] == HashAgain(node2))
                return 2;
        else {
                for(int i = 0; i < temp1; i++) {
                        int flag = 1;
                        for(int j = 0; j < 3; j++) {
                                for(int k = 0; k < 3; k++) {
                                        if(node2.state[j][k] != Crash1[i].state[j][k])
                                                flag = 0;
                                }
                        }
                        if(flag) {
                                final = i;
                                return 4;
                        }
                }
                for(int i = 0; i < 3; i++) {
                        for(int j = 0; j < 3; j++) {
                                Crash2[temp2].state[i][j] = node2.state[i][j];
                        }
                }
                int i = 0;
                for(i = 0; i < node2.step; i++) {
                        Crash2[temp2].trace[i] = node2.road[i];
                }
                Crash2[temp2].trace[i] = '\0';
                temp2++;
                return 0;
        }
        return 0;
}

void func(int x,int y){
        Node node(x,y,0);
        Node Denode(2,2,0);
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        node.state[i][j] = pos[i][j];
                }
        }
        for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                        Denode.state[i][j] = 3*i+j+49;
                }
        }
        Denode.state[2][0] = '7';
        Denode.state[2][1] = '8';
        Denode.state[2][2] = 'x';
        queue <Node> q;
        queue <Node> Deq;
        while(!q.empty())
                q.pop();
        while(!Deq.empty())
                Deq.pop();
        q.push(node);
        Deq.push(Denode);
        while(!q.empty() || Deq.empty()) {
                node = q.front();
                Denode = Deq.front();
                q.pop();
                Deq.pop();
                if(judge(node,Denode)) {
                        switch(judge(node,Denode)) {
                        case 1:   {
                                for(int i = 0; i < node.step; i++)
                                        cout<<node.road[i];
                                int l = 0;
                                for(int i = 0; i < 30; i++) {
                                        if(Road2[Hash(node)][i] == '\0') {
                                                l = i;
                                                break;
                                        }
                                }
                                for(int i = l - 1; i >= 0; i--) {
                                        cout<<Road2[Hash(node)][i];
                                }
                                cout<<endl;
                        }  break;
                        case 2:   {
                                int l = 0;
                                for(int i = 0; i < 30; i++) {
                                        if(Road1[Hash(Denode)][i] == '\0') {
                                                l = i;
                                                break;
                                        }
                                }
                                for(int i = 0; i < l; i++) {
                                        cout<<Road1[Hash(Denode)][i];
                                }
                                for(int i = Denode.step - 1; i >= 0; i--)
                                        cout<<Denode.road[i];
                                cout<<endl;
                        } break;
                        case 3:   {
                                for(int i = 0; i < node.step; i++)
                                        cout<<node.road[i];
                                int l = 0;
                                for(int i = 0; i < 30; i++) {
                                        if(Crash2[final].trace[i] == '\0') {
                                                l = i;
                                                break;
                                        }
                                }
                                for(int i = l - 1; i >= 0; i--) {
                                        cout<<Crash2[final].trace[i];
                                }
                                cout<<endl;
                        } break;
                        case 4:   {
                                int l = 0;
                                for(int i = 0; i < 30; i++) {
                                        if(Crash1[final].trace[i] == '\0') {
                                                l = i;
                                                break;
                                        }
                                }
                                for(int i = 0; i < l; i++) {
                                        cout<<Crash1[final].trace[i];
                                }
                                for(int i = Denode.step - 1; i >= 0; i--)
                                        cout<<Denode.road[i];
                                cout<<endl;
                        } break;
                        case 5:   {
                                for(int i = 0; i < node.step; i++)
                                        cout<<node.road[i];
                                int l = 0;
                                for(int i = 0; i < 30; i++) {
                                        if(Road2[Hash(node)][i] == '\0') {
                                                l = i;
                                                break;
                                        }
                                }
                                for(int i = l - 1; i >= 0; i--) {
                                        cout<<Road2[Hash(node)][i];
                                }
                                cout<<endl;
                        } break;
                        }
                        break;
                }
                if(hash1[Hash(node)] == HashAgain(node))
                        continue;
                else{
                        hash1[Hash(node)] = HashAgain(node);
                }
                if(hash2[Hash(Denode)] == HashAgain(Denode))
                        continue;
                else{
                        hash2[Hash(Denode)] = HashAgain(Denode);
                }
                node.step++;
                Denode.step++;
                if(node.x > 0) {
                        Node NewNode(node.x - 1,node.y,node.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = node.state[i][j];
                                }
                        }
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {

                                }
                        }
                        int p = NewNode.state[node.x][node.y];
                        NewNode.state[node.x][node.y] = NewNode.state[node.x - 1][node.y];
                        NewNode.state[node.x - 1][node.y] = p;
                        if(hash1[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < node.step - 1; i++)
                                        NewNode.road[i] = node.road[i];
                                NewNode.road[node.step - 1] = 'u';
                                int i = 0;
                                for(i = 0; i < node.step; i++) {
                                        Road1[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                q.push(NewNode);
                        }
                }
                if(node.x < 2) {
                        Node NewNode(node.x + 1,node.y,node.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = node.state[i][j];
                                }
                        }
                        int p = NewNode.state[node.x][node.y];
                        NewNode.state[node.x][node.y] = NewNode.state[node.x + 1][node.y];
                        NewNode.state[node.x + 1][node.y] = p;
                        if(hash1[Hash(NewNode)] != HashAgain(NewNode)) {

                                for(int i = 0; i < node.step - 1; i++)
                                        NewNode.road[i] = node.road[i];
                                NewNode.road[node.step - 1] = 'd';
                                int i = 0;
                                for(i = 0; i < node.step; i++) {
                                        Road1[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                q.push(NewNode);
                        }
                }
                if(node.y > 0) {
                        Node NewNode(node.x,node.y - 1,node.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = node.state[i][j];
                                }
                        }
                        int p = NewNode.state[node.x][node.y];
                        NewNode.state[node.x][node.y] = NewNode.state[node.x][node.y - 1];
                        NewNode.state[node.x][node.y - 1] = p;
                        if(hash1[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < node.step - 1; i++)
                                        NewNode.road[i] = node.road[i];
                                NewNode.road[node.step - 1] = 'l';
                                int i = 0;
                                for(i = 0; i < node.step; i++) {
                                        Road1[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                q.push(NewNode);
                        }
                }
                if(node.y < 2) {
                        Node NewNode(node.x,node.y + 1,node.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = node.state[i][j];
                                }
                        }
                        int p = NewNode.state[node.x][node.y];
                        NewNode.state[node.x][node.y] = NewNode.state[node.x][node.y + 1];
                        NewNode.state[node.x][node.y + 1] = p;
                        if(hash1[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < node.step - 1; i++)
                                        NewNode.road[i] = node.road[i];
                                NewNode.road[node.step - 1] = 'r';
                                int i = 0;
                                for(i = 0; i < node.step; i++) {
                                        Road1[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                q.push(NewNode);
                        }
                }
                if(Denode.x > 0) {
                        Node NewNode(Denode.x - 1,Denode.y,Denode.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = Denode.state[i][j];
                                }
                        }
                        int p = NewNode.state[Denode.x][Denode.y];
                        NewNode.state[Denode.x][Denode.y] = NewNode.state[Denode.x - 1][Denode.y];
                        NewNode.state[Denode.x - 1][Denode.y] = p;
                        if(hash2[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < Denode.step - 1; i++)
                                        NewNode.road[i] = Denode.road[i];
                                NewNode.road[Denode.step - 1] = 'd';
                                int i = 0;
                                for(i = 0; i < Denode.step; i++) {
                                        Road2[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                Deq.push(NewNode);
                        }
                }
                if(Denode.x < 2) {
                        Node NewNode(Denode.x + 1,Denode.y,Denode.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = Denode.state[i][j];
                                }
                        }
                        int p = NewNode.state[Denode.x][Denode.y];
                        NewNode.state[Denode.x][Denode.y] = NewNode.state[Denode.x + 1][Denode.y];
                        NewNode.state[Denode.x + 1][Denode.y] = p;
                        if(hash2[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < Denode.step - 1; i++)
                                        NewNode.road[i] = Denode.road[i];
                                NewNode.road[Denode.step - 1] = 'u';
                                int i = 0;
                                for(i = 0; i < Denode.step; i++) {
                                        Road2[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                Deq.push(NewNode);
                        }
                }
                if(Denode.y > 0) {
                        Node NewNode(Denode.x,Denode.y - 1,Denode.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = Denode.state[i][j];
                                }
                        }
                        int p = NewNode.state[Denode.x][Denode.y];
                        NewNode.state[Denode.x][Denode.y] = NewNode.state[Denode.x][Denode.y - 1];
                        NewNode.state[Denode.x][Denode.y - 1] = p;
                        if(hash2[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < Denode.step - 1; i++)
                                        NewNode.road[i] = Denode.road[i];
                                NewNode.road[Denode.step - 1] = 'r';
                                int i = 0;
                                for(i = 0; i < Denode.step; i++) {
                                        Road2[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                Deq.push(NewNode);
                        }
                }
                if(Denode.y < 2) {
                        Node NewNode(Denode.x,Denode.y + 1,Denode.step);
                        for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                        NewNode.state[i][j] = Denode.state[i][j];
                                }
                        }
                        int p = NewNode.state[Denode.x][Denode.y];
                        NewNode.state[Denode.x][Denode.y] = NewNode.state[Denode.x][Denode.y + 1];
                        NewNode.state[Denode.x][Denode.y + 1] = p;
                        if(hash2[Hash(NewNode)] != HashAgain(NewNode)) {
                                for(int i = 0; i < Denode.step - 1; i++)
                                        NewNode.road[i] = Denode.road[i];
                                NewNode.road[Denode.step - 1] = 'l';
                                int i = 0;
                                for(i = 0; i < Denode.step; i++) {
                                        Road2[Hash(NewNode)][i] = NewNode.road[i];
                                }
                                Deq.push(NewNode);
                        }
                }
        }

}

int main(){
        int x,y;
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        cin>>pos[i][j];
                        if(pos[i][j] == 'x') {
                                x = i;
                                y = j;
                        }
                }
        }
        Node n(0,0,0);
        for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                        n.state[i][j] = 3*i+j+49;
                }
        }
        n.state[2][0] = '7';
        n.state[2][1] = '8';
        n.state[2][2] = 'x';
        int flag = 1;
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        if(n.state[i][j] != pos[i][j])
                                flag = 0;
                }
        }
        if(flag)
                return 0;
        else{
                if(JUDGE()) {
                        func(x,y);
                }
                else{
                        cout<<"unsolvable"<<endl;
                }
        }
        return 0;
}
