#include <iostream>
#include <string>
#include "Header.h"
#include "ArrayList.h"

using namespace std;

int getMinrun(int n) {

    int r = 0;
    while (n >= 256) {

        r |= n & 1;
        n >>= 1;
    }

    return n + r;
}

void insertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

Stack stack;

void merge(int* arr, int l, int m, int r) {

    int len1 = m - l + 1, len2 = r - m;
    int* left = new int[len1];
    int* right = new int[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++]; 
        }
    }

    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void timSort(int* arr, int n) {

    int minRun = getMinrun(n);

    Stack stack;
    for (int i = 0; i < n; i += minRun) {

        insertionSort(arr, i, min((i + minRun - 1), (n - 1)));
        stack.push(i);
        if ((i + minRun - 1) < n - 1) {
            stack.push(i + minRun - 1);
        }
        else {

            stack.push(n - 1);

        }
    }

    while (stack.size() > 2) {
        int start1, end1, start2, end2;
        end1 = stack.peek();
        stack.pop();
        start1 = stack.peek();
        end2 = start1 - 1;
        stack.pop();
        start2 = stack.isEmpty() ? 0 : stack.peek();
        merge(arr, start2, end2, end1);
        stack.push(start2);
        stack.push(end1);
    }

}


int main()
{
    int arr[] = { 9, 2, 5, 1, 7, 4, 8, 3, 6, 4, 7, 9, 67, 48, 29, 29, 5, 7, 9, 2, 11, 25, 42, 65, 28,
        1, 92, 19, 34, 73, 85, 47, 92, 34, 21, 23, 43, 21, 56, 9, 2, 5, 1, 7, 4, 8, 3, 6, 4, 7, 9, 67,
        48, 29, 29, 5, 7, 9, 2, 11, 25, 42, 65, 56, 9, 2, 5, 1, 7, 4, 8, 3, 6, 4, 7, 9, 67,
        48, 29, 29, 5, 7, 9, 2, 11, 25, 42, 65, 56, 9, 2, 5, 1, 7, 4, 8, 3, 6, 4, 7, 9, 67,
        48, 29, 29, 5, 7, 9, 2, 11, 25, 42, 65 };
    
    cout << sizeof(arr) / sizeof(arr[0]);
    cout << "\n\n";

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting : \n\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    timSort(arr, n);

    cout << "After sorting : \n\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

