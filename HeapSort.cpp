#include <bits/stdc++.h>
using namespace std;
int a[(int)1e6];
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root; // root is the largest element
   int l = 2*root + 1; // left = 2*root + 1
   int r = 2*root + 2; // right = 2*root + 2

   // If left child is larger than root
   if (l < n && arr[l] > arr[largest])
   largest = l;

   // If right child is larger than largest so far
   if (r < n && arr[r] > arr[largest])
   largest = r;

   // If largest is not root
   if (largest != root)
      {
      //swap root and largest
      swap(arr[root], arr[largest]);

      // Recursively heapify the sub-tree
      heapify(arr, n, largest);
      }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i);

   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--)
   {
      // Move current root to end
      swap(arr[0], arr[i]);

      // again call max heapify on the reduced heap
      heapify(arr, i, 0);
   }
}
int main()
{
    ifstream fin("input.txt");
    for(int d=0; d<10; ++d)
    {
        for(int c=0; c<(int)1e6; ++c)
            fin >> a[c]; // test theo từng ví dụ
        clock_t start, finish;   // Khai báo biến thời gian
        double time_use;      // Thời gian sử dụng
        start = clock();     // Lấy thời gian trước khi thực hiện
        heapSort(a,(int)1e6); // gọi hàm
        finish = clock();  // lấy thời gian sau khi thực hiện
        time_use = (double)(finish - start) / CLOCKS_PER_SEC;
        cout << time_use << '\n';
    }
}

