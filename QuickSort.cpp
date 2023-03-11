#include <bits/stdc++.h>
using namespace std;
int arr[(int)1e6];
int partition (int arr[], int low, int high)
{
    int pivot = arr[rand() % ((int)1e6)];    // khai báo phần tử đánh dâu pivot
    int left = low;   //khai báo biến bên trái
    int right = high - 1; //khai báo biến bên phải
    while(true){
        while(left <= right && arr[left] < pivot) left++; // tìm phần tử >= phần tử pivot trong mảng
        while(right >= left && arr[right] > pivot) right--; // tìm phần tử <= phần tử pivot trong mảng
        if (left >= right) break; // sau khi duyệt xong thì thoát khỏi vòng lặp
        swap(arr[left], arr[right]); // nếu chưa xong thì sử dụng hàm swap() để tráo đổi.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(arr[left], arr[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đôi mảng
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* index là chỉ số nơi phần tử này đã đứng đúng vị trí
         và đây là phần tử chia mảng làm 2 mảng con trái & phải */
        int index = partition(arr, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

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
        quickSort(arr,0,(int)1e6-1); // Gọi hàm quickSort
        finish = clock();  // lấy thời gian sau khi thực hiện
        time_use = (double)(finish - start) / CLOCKS_PER_SEC;
        cout << time_use << '\n';
    }
}
