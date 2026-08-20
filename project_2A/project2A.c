#include <stdio.h>

int main()
{
    int i;
    int j;
    for (i = 2; i <= 1000; i++)
    {
        int current = i;
        int count = 0;
        for (j = 2; j <= i; j++)
        {
            if (current % j == 0)
            {
                // Count j as a distinct prime factor,
                // then remove/reduce all copies of j from current
                count++;
                while (current % j == 0)
                {
                    current /= j;
                }
            }
        }
        if (count == 3)
        {
            printf("%d has three factors\n", i);
        }
    }
    return 0;
}