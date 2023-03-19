#include <bits/stdc++.h>
using namespace std;
int arr[(int)1e6];

void Merge(int arr[], int const left, int const mid,
           int const right)
{
    auto const subarrOne = mid - left + 1;
    auto const subarrTwo = right - mid;

    // Create temp arrs
    auto *leftarr = new int[subarrOne],
         *rightarr = new int[subarrTwo];

    // Copy data to temp arrs leftarr[] and rightarr[]
    for (auto i = 0; i < subarrOne; i++)
        leftarr[i] = arr[left + i];
    for (auto j = 0; j < subarrTwo; j++)
        rightarr[j] = arr[mid + 1 + j];

    auto indexOfSubarrOne
        = 0, // Initial index of first sub-arr
        indexOfSubarrTwo
        = 0; // Initial index of second sub-arr
    int indexOfMergedarr
        = left; // Initial index of Merged arr

    // Merge the temp arrs back into arr[left..right]
    while (indexOfSubarrOne < subarrOne
           && indexOfSubarrTwo < subarrTwo) {
        if (leftarr[indexOfSubarrOne]
            <= rightarr[indexOfSubarrTwo]) {
            arr[indexOfMergedarr]
                = leftarr[indexOfSubarrOne];
            indexOfSubarrOne++;
        }
        else {
            arr[indexOfMergedarr]
                = rightarr[indexOfSubarrTwo];
            indexOfSubarrTwo++;
        }
        indexOfMergedarr++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubarrOne < subarrOne) {
        arr[indexOfMergedarr]
            = leftarr[indexOfSubarrOne];
        indexOfSubarrOne++;
        indexOfMergedarr++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubarrTwo < subarrTwo) {
        arr[indexOfMergedarr]
            = rightarr[indexOfSubarrTwo];
        indexOfSubarrTwo++;
        indexOfMergedarr++;
    }
    delete[] leftarr;
    delete[] rightarr;
}

// Begin is for left index and End is
// right index of the sub-arr
// of arr to be sorted */
void MergeSort(int arr[], int const Begin, int const End)
{
    if (Begin >= End)
        return; // Returns recursively

    auto mid = Begin + (End - Begin) / 2;
    MergeSort(arr, Begin, mid);
    MergeSort(arr, mid + 1, End);
    Merge(arr, Begin, mid, End);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("MergeSort_output.txt");
    for(int d=0; d<10; ++d)
    {
        string s;
        getline(fin,s);
        for(int c=0; c<(int)1e6; ++c)
            fin >> arr[c]; // test theo từng ví dụ
        clock_t start, finish;   // Khai báo biến thời gian
        double time_use;      // Thời gian sử dụng
        start = clock();     // Lấy thời gian trước khi thực hiện
        MergeSort(arr,0,(int)1e6-1); // Gọi hàm quickSort
        finish = clock();  // lấy thời gian sau khi thực hiện
        time_use = (double)(finish - start) / CLOCKS_PER_SEC;
        fout << time_use << '\n';
    }
}

