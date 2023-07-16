#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int i = low;
    int k = 0;
    int m, j = mid + 1;
    int *b = (int*)malloc((high - low + 1) * sizeof(int));
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
            k++;
        }
        else {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (m = 0; m < (high - low + 1); m++) {
        a[low + m] = b[m];
    }
    free(b);
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
