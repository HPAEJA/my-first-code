#include <stdio.h>

int main() {
    int arr[] = {12, 2, 5, 3, 1, 9};
    int size = 6;
    int temp[6];
    int i, j, k;
    int curr_size, left_start;

    for (curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < size - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;
            if (right_end >= size)
                right_end = size - 1;

            i = left_start;
            j = mid + 1;
            k = left_start;

            while (i <= mid && j <= right_end) {
                if (arr[i] <= arr[j]) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }

            while (i <= mid) {
                temp[k++] = arr[i++];
            }

            while (j <= right_end) {
                temp[k++] = arr[j++];
            }

            for (i = left_start; i <= right_end; i++) {
                arr[i] = temp[i];
            }
        }
    }

    printf("After merge sort:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
