#include <bits/stdc++.h>
using namespace std;
int test[10][(int)1e6];

int main()
{
    ofstream fout("input.txt");
    int run = 1;
    for(int c=0; c<(int)1e6; ++c, ++run)
        test[0][c] = run+1;
    for(int c=0; c<(int)1e6; ++c)
        test[1][c] = (int)1e6-c;
    for(int d=2; d<10; ++d)
    {
        for(int c=0; c<(int)1e6; ++c)
            test[d][c] = rand() % (int)1e6;
    }
    for(int d=0; d<10; ++d)
    {
        fout << "STT " << d << '\n';
        for(int c=0; c<(int)1e6; ++c)
            fout << test[d][c] << ' ';
        fout << '\n';
    }
}
