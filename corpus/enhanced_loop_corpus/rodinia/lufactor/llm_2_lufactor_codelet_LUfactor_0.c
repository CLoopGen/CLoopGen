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
    u_int step = 2;
    u_int idx;
    for (idx = 0; idx < m; idx += step) {
        if (idx < m) pivot->pe[idx] = idx;
        u_int next = idx + 1;
        if (next < m) pivot->pe[next] = next;
    }
}
