#include <bits/stdc++.h>
using namespace std;
int arr[(int)1e6];
int partition(int arr[], int start, int finish)
{

    int pivot = arr[rand() % (finish-start) + start];

    int Count = 0;
    for (int i = start + 1; i <= finish; i++) {
        if (arr[i] <= pivot)
            Count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + Count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = finish;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int finish)
{

    // base case
    if (start >= finish)
        return;

    // partitioning the array
    int p = partition(arr, start, finish);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, finish);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("QuickSort_output.txt");
    for(int d=0; d<10; ++d)
    {
        string s;
        getline(fin,s);
        for(int c=0; c<(int)1e6; ++c)
            fin >> arr[c]; // test theo từng ví dụ
        clock_t start, finish;   // Khai báo biến thời gian
        double time_use;      // Thời gian sử dụng
        start = clock();     // Lấy thời gian trước khi thực hiện
        quickSort(arr,0,(int)1e6-1); // Gọi hàm quickSort
        finish = clock();  // lấy thời gian sau khi thực hiện
        time_use = (double)(finish - start) / CLOCKS_PER_SEC;
        fout << time_use << '\n';
    }
}
