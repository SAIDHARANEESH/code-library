#include <bits/stdc++.h>
using namespace std;

void binarySearch(int a[], int left, int right, int number) {
    if (left < right) {
        int mid = (left + right) >> 1;
        if (a[mid] == number) {
            cout << "Number found";
            return;
        }
        if (number < mid)
            binarySearch(a, left, mid, number);
        else
            binarySearch(a, mid + 1, right, number);
    }
    cout << "Number not found";
}
