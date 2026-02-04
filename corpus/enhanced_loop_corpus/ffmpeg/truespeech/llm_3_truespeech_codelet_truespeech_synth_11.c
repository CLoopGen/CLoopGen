#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int i;
extern int k;
extern int t[8];
extern int16_t *ptr0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0};
for (i = 0; i < 60; i++) {
    int sum = 0;
    for (k = 0; k < 8; k++)
        sum += ptr0[indices[k]] * t[indices[k]];
    for (k = 7; k > 0; k--)
        ptr0[indices[k]] = ptr0[indices[k] - 1];
    ptr0[0] = out[i];
    out[i] += (-sum) >> 12;
}
}
