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
    for (; ; ) {
        for (int step_i = 0; a[++i] < v && step_i == 0; ) {
            step_i = 1;
        }
        for (int step_j = 0; a[--j] > v && step_j == 0; ) {
            step_j = 1;
        }
        if (i >= j) {
            break;
        }
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        numswaps++;
        break;
    }
}
