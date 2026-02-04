#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern int size;
extern PERM *permute;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int *pe = permute->pe;
    for (i = 0; i < size; i++) {
        pe[i] = i;
        if (i > 0) {
            pe[i] += pe[i-1]; // Introduces RAW and WAW loop-carried dependency
        }
    }
}
