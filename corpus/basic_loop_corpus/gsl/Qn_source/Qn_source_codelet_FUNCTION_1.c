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
for (i = 1; i < ni; ++i) {
    if (left[i] <= right[i]) {
        weight[j] = right[i] - left[i] + 1;
        jh = left[i] + weight[j] / 2;
        ++j;
    }
}

}
