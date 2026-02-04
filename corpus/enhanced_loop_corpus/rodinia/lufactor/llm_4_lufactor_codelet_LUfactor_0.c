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
    for (i = 0; i < m; i++) {
        if (i % 2 == 0) {
            pivot->pe[i] = i;
        }
    }
}
