#include <bits/stdc++.h>
using namespace std;
int arr[(int)1e6];
/* Hàm trộn - merge
 start - chỉ số bắt đầu mảng
 mid - chỉ số giữa, chia đôi mảng
*/
void merge(int a[], int start, int mid, int end){
    int n1 = mid - start + 1; // Số phần tử mảng con trái
                                    // + 1 là do lưu thêm phần tử ở vị trí mid
    int n2= end-mid;          // Số phần tử mảng con phải
    int left[n1]; int right[n2];  // Khai báo hai mảng trung gian

    // Copy giữ liệu từ mảng chính ra hai mảng con
    for(int x=0; x<n1; x++) left[x] = a[start+x];
    for(int y=0; y<n2; y++) right[y] = a[mid+1+y];

    int i=0, j=0;     // Khai báo hai biến chạy để duyệt mảng con
    int k=start;     // Lưu k làm vị trí bắt đầu của mảng chính,

    while(i<n1 && j<n2){    // Trong khi cả hai mảng con chưa hết phần tử
        if(left[i]>=right[j]){   // Nếu phần tử mảng con trái >= mảng con phải
            a[k]=right[j];   // Điển phần tử mảng con phải vào mảng chính
            j++;             // xét phần tử tiếp theo của mảng right
        }
        else{               // Ngược lại tức là left[i] < right[j]
            a[k]=left[i];
            i++;
        }
        k++;              // Tăng index của mảng chính, mỗi lần lặp sẽ tìm được 1 phần tử thích hợp
    }

        // Sau vòng lặp trên, 1 trong 2 mảng đã duyệt hết phần tử, hoặc cả hai cùng hết

    while(j<n2){      // Nếu mảng right chưa hết, mảng left đã hết
        a[k]=right[j]; // Cho toàn bộ các phần tử còn lại vào mảng chính
        k++;
        j++;
    }

    while(i<n1){     // Nếu mảng left chưa hết, mảng right hết
        a[k]= left[i];
        k++;
        i++;
    }
}

// MergeSort
void mergeSort(int a[], int first, int end){
    int t;    //  biến để lưu vị trí chia đôi mảng
    if(first<end){              // Nếu mảng còn ít nhất 1 phần tử
        t=(first+end)/2;    // Chia đôi mảng
        mergeSort(a,first,t);   // Đệ quy mảng trái
        mergeSort(a,t+1,end);   // Đệ quy mảng phải
        merge(a,first,t,end);   // Trộn hai mảng lại
    }
    else    // Mảng < 1 phần tử sẽ dừng đệ quy
        return;
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
        mergeSort(arr,0,(int)1e6); // Gọi hàm quickSort
        finish = clock();  // lấy thời gian sau khi thực hiện
        time_use = (double)(finish - start) / CLOCKS_PER_SEC;
        cout << time_use << '\n';
    }
}

