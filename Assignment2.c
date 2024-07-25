#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int arr[], int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i == -1) {
        return 0;
    }
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    swap(&arr[i], &arr[j]);
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    return 1;
}

int calculate_assignments(int n, int preferences[][n]) {
    int i, j, temp[n];
    int count = 0;

    // Initialize the temporary array
    for (i = 0; i < n; i++) {
        temp[i] = i;
    }

    // Calculate the number of assignments
    do {
        int valid = 1;
        for (i = 0; i < n; i++) {
            if (preferences[i][temp[i]] == 0) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            count++;
        }
    } while (next_permutation(temp, n));

    return count;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int preferences[n][n];
    printf("Enter the preferences of each student (1 for like, 0 for dislike):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &preferences[i][j]);
        }
    }
    int result = calculate_assignments(n, preferences);
    printf("Number of different assignments: %d\n", result);
    return 0;
}
