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
int w;
int mid;
for (i = 1; i < ni / 2; ++i) {
    if (left[i] <= right[i]) {
        w = right[i] - left[i] + 1;
        mid = left[i] + w / 2;
        if (w > 0) {
            weight[j] = w;
            jh = mid;
            j++;
        }
    }
    if (left[ni - i] <= right[ni - i]) {
        w = right[ni - i] - left[ni - i] + 1;
        mid = left[ni - i] + w / 2;
        if (w > 0) {
            weight[j] = w;
            jh = mid;
            j++;
        }
    }
}
}
