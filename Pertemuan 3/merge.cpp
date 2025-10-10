#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    // Bagi array menjadi 2 bagian
    int n1 = mid - left + 1;  
    int n2 = right - mid;    

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisiasi variabel i, j, dan k
    int i = 0;   
    int j = 0;      
    int k = left;

    // Bandingkan antara elemen L dan R
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari L jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari R jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    // Jika data di kiri lebih >= data di kanan, jangan diurutkan
    if (left >= right)
        return;

    // Bagi array menjadi dua bagian hingga tersisa elemen tunggal
    int mid = left + (right - left) / 2;

    // Panggil mergeSort secara rekursif
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Gabungkan dua bagian array yang sudah diurutkan
    merge(arr, left, mid, right);
}

void printArray(const vector<int>& arr) {
    // Menampilkan seluruh elemen array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Input jumlah data
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    // Input elemen-elemen data
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Tampilkan array yang belum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);

    // Urutkan array dengan mergeSort
    mergeSort(data, 0, n - 1);

    // Tampilkan array yang sudah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;
}