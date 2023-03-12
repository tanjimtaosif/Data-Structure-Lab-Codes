#include <stdio.h>
#include <stdlib.h>

/**
 @author Md.Tanjim Mahtab Taosif (213902007) <itsmahtab007@gmail.com>
 */

void merge(int *a, int *b, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

int mergeSort(int *a, int *b, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, b, low, mid);
        mergeSort(a, b, mid + 1, high);
        merge(a, b, low, mid, high);
    }
}

int main()
{
    int i, j, k, n, temp, pivot;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[n];
    mergeSort(a, b, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}