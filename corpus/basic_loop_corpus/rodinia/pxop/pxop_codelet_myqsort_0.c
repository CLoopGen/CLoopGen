#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *a;
extern int i;
extern int j;
extern int tmp;
extern int v;
extern int numswaps;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (;;) {
    while (a[++i] < v)
        ;
    while (a[--j] > v)
        ;
    if (i >= j)
        break;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    numswaps++;
}

}
