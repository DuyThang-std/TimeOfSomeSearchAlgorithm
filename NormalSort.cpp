#include <bits/stdc++.h>
using namespace std;
int arr[(int)1e6];

int main()
{
    ifstream fin("input.txt");
    for(int d=0; d<10; ++d)
    {
        for(int c=0; c<(int)1e6; ++c)
            fin >> arr[c]; // test theo từng ví dụ
        clock_t start, finish;   // Khai báo biến thời gian
        double time_use;      // Thời gian sử dụng
        start = clock();     // Lấy thời gian trước khi thực hiện
        sort(arr,arr+(int)1e6); // Gọi hàm
        finish = clock();  // lấy thời gian sau khi thực hiện
        time_use = (double)(finish - start) / CLOCKS_PER_SEC;
        cout << time_use << '\n';
    }
}

