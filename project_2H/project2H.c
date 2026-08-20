#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *AllocateArray(int N)
{
    int* array = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % ((10 * N) + 1);
    }
    return array;
}

int compare_ints(const void *X, const void *Y)
{
    int x = *(const int *)X;
    int y = *(const int *)Y;

    return (x > y) - (x < y);
}

void SortArray(int N, int *A)
{
    qsort(A, N, sizeof(int), compare_ints);
}

void DeallocateArray(int *A)
{
    free(A);
}

int main()
{
    //int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };
    int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000 };

    int* A;
    for (int i = 0 ; i < 11 ; i++)
    {
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;

        gettimeofday(&startTime, NULL);
        A = AllocateArray(sizes[i]);
        gettimeofday(&endTime, NULL);
        alloc_time = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec) / 1000000.0);

        gettimeofday(&startTime, NULL);
        SortArray(sizes[i], A);
        gettimeofday(&endTime, NULL);
        sort_time = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec) / 1000000.0);

        gettimeofday(&startTime, NULL);
        DeallocateArray(A);
        gettimeofday(&endTime, NULL);
        dealloc_time = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec) / 1000000.0);

        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
    return 0;
}
