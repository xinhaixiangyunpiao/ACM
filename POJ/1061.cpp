/**数论相关-----线性同余**?
/**
算法思想：
        青蛙A：Sa = mt + x
        青蛙B：Sb = nt + y
        (mt+x) - (nt+y) = KL
        (m-n)t = KL + (y-x)
        (m-n)t = y-x (mod L)
        当 gcd(m-n,L)|y-x时，方程有解，且解为 X0（特解）+ K*L/gcd(m-n,L)，且在[0,L/gcd(m-n.L)]上有唯一解，此唯一解即为唯一的正解。
        证明：
                令a = m-n，b = L，x = t， y为整数 y-x = c
                则上述同余方程等价于ax + by = c 且 d = gcd(a,b)
                若方程有解（d|c），则方程a/d*x + b/d*y = c/d有解
                gcd(a/d,b/d) = 1， 即上方程在[0,b/d-1]上有唯一解。
        ax = c (mod b) 某一特解X， r = b/gcd(a,b) = b/d
        在[0,r-1]上有唯一解
        则最小正解为：x = (X%r+r)%r (X%r可能是负值) 这样算会得到最小正解。
        扩展欧几里得法用于求解ax + by = c的一组x，y，也就可以求出一个特解。
**/
#include <iostream>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
        long long ans, t;
        if (b == 0)
        {
                x = 1;
                y = 0;
                return a;
        }
        else
        {
                ans = extended_gcd(b, a % b, x, y);
                t = x;
                x = y;
                y = t - (a / b) * y;
        }
        return ans;
}

int main()
{
        long long x,y,m,n,L;
        cin >> x >> y >> m >> n >> L;
        long long xx,yy,d,r;
        d = extended_gcd(n-m,L,xx,yy);
        if ((x - y) % d != 0)             //gcd(n-m,L)|x-y不成立
                cout << "Impossible" << endl;
        else
        {
                xx = xx * ((x - y) / d);
                r = L / d;
                xx = (xx % r + r) % r; //求出最小非负整数解
                cout << xx << endl;
        }
        return 0;
}
