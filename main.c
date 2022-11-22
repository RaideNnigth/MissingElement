#include <stdio.h>

void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);
void checkMissingNumber(int arr[], int size);

int main(int argc, char const *argv[])
{
    int size ;
    printf("What's the size of the array: ");
    scanf("%d", &size);
    int nums[size];
    for (int i = 0; i < size; i++){
        printf("Number %d to insert is: ", i);
        scanf("%d", &nums[i]);
    }
    mergeSort(nums, 0, size - 1);
    printArray(nums, size);
    checkMissingNumber(nums, size);
    return 0;
}

void merge(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("- ");
}
void checkMissingNumber(int arr[], int size)
{
    int missing = 0;
    for (int i = 0; i <= size; i++){
        if (arr[i] != i){
            missing = i;
            break;
        }
    }
    printf("The missing number is: %d", missing);
}