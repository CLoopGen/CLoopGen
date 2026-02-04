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
    for (int k = 0; k < 1; ++k) {
        for (++i; a[i] < v && i < j; ++i)
            ;
        for (--j; a[j] > v && i < j; --j)
            ;
        if (i >= j) continue;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        numswaps++;
        break;
    }
}
