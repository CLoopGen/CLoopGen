#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = ni + (ni >> 1);
for (i = 1; i < limit; ++i) {
    int idx = (i * 2) % ni;
    if (idx > 0 && left[idx] <= right[idx]) {
        int w = right[idx] - left[idx] + 1;
        weight[j] = w;
        jh = left[idx] + (w >> 1);
        j++;
        if (w > 10) {
            weight[j] = w / 2;
            jh = left[idx] + (w >> 2);
            j++;
        }
    }
}
}
