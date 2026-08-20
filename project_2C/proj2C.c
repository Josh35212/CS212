#include <stdio.h>

int main()
{
    int i;
    int A[21];
    int *B[3];

    A[0] = 0;
    A[1] = 1;
    A[2] = 1;
    for (i = 3 ; i < 21 ; i++)
        A[i] = A[i-3]+A[i-2]+A[i-1];

    for (i = 0 ; i < 21 ; i++)
        printf("%d: %d\n", i, A[i]);

    B[0] = A;
    B[1] = A+7;
    B[2] = A+14;

    // -----Check Answers-----
    printf("-----Check Answers-----\n");
    printf("%d\n", *(A+5) - *(A+3));
    printf("%d\n", (A+7) - (A+2));
    printf("%d\n", A[5] - *(A+4));
    printf("%d\n", *A);
    printf("%d\n", (A+12)- B[1]);
    printf("%d\n", B[1][4]);
    printf("%d\n", *(A+4));
    printf("%d\n", B[2][3]- A[16]);
    printf("%d\n", &(B[2][3]) - &(A[15]));
    printf("%d\n", B[2][0] - B[1][6]);
    printf("%d\n", *(&A[6]));
    printf("%d\n", B[2][0] - B[1][7]);
}
