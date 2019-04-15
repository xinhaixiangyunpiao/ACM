/*
 * 迷宫问题
 */
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define SIZE 5

int maze[SIZE][SIZE];
int flag[SIZE][SIZE];
int dir[4][2] = {-1,0,0,1,1,0,0,-1};         //四个方向

struct point{
    int x;
    int y;
    point(int X,int Y){  //构造函数
        x = X;
        y = Y;
    }
    point(){             //重载构造函数

    }
};

queue<point> q;
point road[SIZE][SIZE];        //记录路径

void Init(){
    memset(flag, 0, sizeof(flag));
    memset(road, 0, sizeof(road));
}

bool IsInMaze(point p){
    if(p.x >= 0 && p.x < SIZE && p.y >= 0 && p.y < SIZE)
        return true;
    return false;
}

bool IsNotWall(point p){
    if(maze[p.x][p.y] != 1)
        return true;
    return false;
}

bool IsNotSearched(point p){
    if(flag[p.x][p.y] != 1)
        return true;
    return false;
}

void GetInput(){
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            cin >> maze[i][j];
}

bool SearchPath(){
    point start(0,0),end(SIZE-1,SIZE-1);    //定义起点终点
    point init(-1,-1);
    flag[0][0] = 1;
    road[0][0] = init;
    q.push(start);
    while(!q.empty()){
        point nowPoint = q.front(); //取当前点
        q.pop();
        if(nowPoint.x == end.x && nowPoint.y == end.y)    //找到终点
            return true;
        //根据当前点坐标扩展新的点
        point nextPoint;
        for(int i = 0; i < 4; i++){     //向四个方向试探
            nextPoint.x = nowPoint.x + dir[i][0];
            nextPoint.y = nowPoint.y + dir[i][1];    //计算下个点坐标
            if(IsInMaze(nextPoint)&&IsNotWall(nextPoint)&&IsNotSearched(nextPoint)){
                q.push(nextPoint);
                flag[nextPoint.x][nextPoint.y] = 1;
                road[nextPoint.x][nextPoint.y] = nowPoint;
            }
        }
    }
    return false;
}

void OutPath(){
    point p(SIZE-1,SIZE-1);
    point arr[SIZE*SIZE];
    int x,y,num = 0;
    while(p.x != 0 || p.y != 0){
        arr[num++] = p;
        x = p.x;
        y = p.y;
        p.x = (road[x][y]).x;
        p.y = (road[x][y]).y;
    }
    arr[num++] = p;
    for(int i = num-1; i >= 0; i--){
        cout << "(" << arr[i].x << ", " << arr[i].y << ")" << endl;
    }
}

int main(){
    Init();
    GetInput();
    if(SearchPath())
        OutPath();
    else
        cout << "no solution!" << endl;
    return 0;
}
