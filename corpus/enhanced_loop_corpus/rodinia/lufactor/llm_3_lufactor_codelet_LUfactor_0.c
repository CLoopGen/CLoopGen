#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *pivot;
extern u_int i;
extern u_int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int stride = 4;
    u_int j;
    for (j = 0; j < m; j += stride) {
        u_int k;
        for (k = 0; k < stride && (j + k) < m; k++) {
            pivot->pe[j + k] = j + k;
        }
    }
}
