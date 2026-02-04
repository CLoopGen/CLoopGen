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
    int current_left = left[i];
    int current_right = right[i];
    if (current_left <= current_right) {
        weight[j] = current_right - current_left + 1;
        jh = current_left + weight[j] / 2;
        ++j;
    }
    if (i + 1 < ni) {
        int next_idx = i + 1;
        if (left[next_idx] <= right[next_idx]) {
            weight[j] = right[next_idx] - left[next_idx] + 1;
            jh = left[next_idx] + weight[j] / 2;
            ++j;
        }
    }
}
}
