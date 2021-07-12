#include <stdio.h>
#include <stdint.h>


int sum(int a, int b)
{
    return (a + b);
}

uint64_t string_len(const char *str)
{
    char *tmp = (char *)str;

    while (*tmp)
        tmp++;
    
    return (tmp - str);
}

int main(void)
{
    printf("%d\n", sum(2, 2));
    printf("hello world\n");
    printf("%lld\n", string_len("hello world"));
    return (0);
}