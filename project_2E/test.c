#include <stdio.h>
#include <string.h>

// int my_strlen(char *s)
// {
//     /* Return the length of string s using the C convention of
//      * being terminated by the NULL character. 
//      * Do not call any other functions whatsoever.
//      * Even my_strlen -- no solutions involving recursion. */
//     int i = 0;
//     while (s[i] != '\0')
//     {
//         i++;
//     }
//     printf("str length = %d\n", i);
//     return i;
// }

void str_reverse(char *str)
{
    /* Modify s to be the reverse string.
     * If s is "hello" when the function is called, then it
     * should be "olleh" when the function is completed. 
     * Do not call any other functions whatsoever. */
    int i = 0;
    int left = 0;
    char temp = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    int right = i - 1;

    while (left < right)
    {
        temp = str[right];
        str[right] = str[left];
        str[left] = temp;
        left++;
        right--;
    }
}

int main()
{
    // my_strlen("hello world");
    char str[] = "hello world";
    char str2[] = "cs 212";
    str_reverse(str);
    str_reverse(str2);
    printf("str_reverse = %s\n", str);
    printf("str_reverse2 = %s\n", str2);
}