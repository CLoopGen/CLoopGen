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
    for (int iter = 0; iter < 100 && !(i >= j); ++iter) {
        i += (a[i + 1] < v) ? 1 : 0;
        j -= (a[j - 1] > v) ? 1 : 0;
        if (i >= j) break;
        if (a[i] < v) continue;
        if (a[j] > v) continue;
        if (i < j) {
            int swap_temp = a[i];
            a[i] = a[j];
            a[j] = swap_temp;
            numswaps++;
        }
        i++;
        j--;
    }
}
