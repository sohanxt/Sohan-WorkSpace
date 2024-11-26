#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int ltemp[n1], rtemp[n2];
    for (int i = 0; i < n1; i++)
        ltemp[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
    rtemp[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (ltemp[i] <= rtemp[j]) {
            arr[k++] = ltemp[i++];
        } else {
            arr[k++] = rtemp[j++];
        }
    }
    while (i < n1) arr[k++] = ltemp[i++];
    while (j < n2) arr[k++] = rtemp[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1, 6};
    int n = 6;

    cout << "Unsorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
