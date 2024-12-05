#include <stdlib.h>
#include <stdio.h>

int main(void)
{
        int *p;
        p = malloc(128);
        printf("%ld\n", (long)p);

        return (0);
}
