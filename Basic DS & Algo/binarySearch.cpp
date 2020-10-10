void binarySearch(int a[], int left, int right, int number) {
    if (left < right) {
        int mid = (left + right) >> 1;
        if (a[mid] == number) {
            cout << "Number found";
            return;
        }
        if (number < mid)
            binarySearch(a, left, mid);
        else
            binarySearch(a, mid + 1, right);
    }
    cout << "Number not found";
}