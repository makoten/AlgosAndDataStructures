//
// Created by mako on 9/28/2024.
//
#include<stdio.h>

struct Array {
    int A[10]; // to avoid malloc and free for posterity
    int size; // total slots
    int length; // current number of elements
};

void Display(struct Array arr) {
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }

    printf("\n");
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int pos, int val) {
    if (pos < 0 || arr->length < pos) {
        printf("The position should be less than or equal to %d\n", arr->size);
        return;
    }

    if (arr->size == arr->length) {
        printf("There is not enough room to insert a new value.\n");
        return;
    }

    int i;
    for (i = arr->length; i > pos; i--)
        arr->A[i] = arr->A[i-1];

    arr->length++;
    arr->A[i] = val;
}

void Delete(struct Array *arr, int index) {
    if (index < 0 || index >= arr->length) {
        printf("Index outside of array bounds.\n");
        return;
    }

    int i;
    for (i = index; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];

    arr->length--;
}

int LinearSearch(struct Array arr, int k) {
    for (int i = 0; i < arr.length; i++) {
        if (k == arr.A[i])
            return i;
    }

    return -1;
}

int BinarySearch(struct Array arr, int val) {
    int l = 0;
    int h = arr.length - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr.A[mid] == val)
            return mid;
        else if (arr.A[mid] > val)
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // Append(&arr, 10);
    // Display(arr);
    //
    // Insert(&arr, 6, 100);
    // Display(arr);
    //
    // Delete(&arr, 5);
    // Display(arr);
    printf("%d\n", BinarySearch(arr, 7));
}
