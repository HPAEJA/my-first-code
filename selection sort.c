int main() {
    int arr[] = {31, 1, 3, 23, 44, 100, 7};
    int size = 7;
    int i, j, min_idx, temp;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum with the first element
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    printf("After sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
