#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void print_arr(int arr[], int arr_len)
{
    int i;

    for (i = 0; i < arr_len; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void create_arr(int arr[], int arr_len)
{
    int i;
    srand((unsigned)time(NULL));

    for (i = 0; i < arr_len; i++)
    {
        arr[i] = rand();
    }    
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort1(int arr[], int arr_len)
{
    int i, j;

    for (i = 0; i < arr_len-1; i++)
    {
        /* arr_len - i -1 - 1 - 0 + 1 = arr_len - i - 1 */
        for (j = 0; j < arr_len-i-1; j++) /* 这种方法实现不是很好理解 */
        {
            if (arr[j] > arr[j+1])
            {
                assert(j+1 < 10);
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


void bubble_sort2(int arr[], int arr_len)
{
    int i, j;

    for (i = 0; i < arr_len-1; i++)
    {
        /* arr_len - 1 - (i + 1) + 1 = arr_len - i - 1 */
        for (j = arr_len-1; j > i; j--) /* 每次让j-1 == i就可以了 */
        {
            if (arr[j-1] > arr[j])
            {
                swap(&arr[j-1], &arr[j]);
            }
        }
    }
}

void bubble_sort3(int arr[], int arr_len)
{
    int i, j;

    for (i = 0; i < arr_len-1; i++)
    {
        for (j = arr_len-1; j > i; j--)
        {
            if (arr[j-1] <= arr[j])
            {
                continue;
            }

            swap(&arr[j-1], &arr[j]); /* 减少了代码进缩层次 */
        }
    }
}

int main(void)
{
    int array[10];
    
    create_arr(array, sizeof(array)/sizeof(array[0]));
    bubble_sort1(array, sizeof(array)/sizeof(array[0]));
    print_arr(array, sizeof(array)/sizeof(array[0]));
    printf("\n");
    create_arr(array, sizeof(array)/sizeof(array[0]));
    bubble_sort2(array, sizeof(array)/sizeof(array[0]));
    print_arr(array, sizeof(array)/sizeof(array[0]));
    
    return 0;
}
