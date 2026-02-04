#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *px;
extern int new_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified access and minimal arithmetic, focusing on memory efficiency
    int step = (new_size > 10) ? new_size / 10 : 1;
    for (i = 0; i < new_size; i += step) {
        px->pe[i] = 0;  // Minimal computation, simulating coarse sampling or initialization stride
    }
}
