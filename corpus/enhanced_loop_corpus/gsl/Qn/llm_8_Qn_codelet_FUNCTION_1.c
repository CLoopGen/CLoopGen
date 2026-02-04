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
for (i = 1; i < ni; i += 2) {
    if (left[i] <= right[i]) {
        int diff = right[i] - left[i];
        weight[j] = diff + 1;
        jh = left[i] + (diff >> 1);
        j++;
    }
    if (i + 1 < ni && left[i+1] <= right[i+1]) {
        int diff = right[i+1] - left[i+1];
        weight[j] = diff + 1;
        jh = left[i+1] + (diff >> 1);
        j++;
    }
}
}
