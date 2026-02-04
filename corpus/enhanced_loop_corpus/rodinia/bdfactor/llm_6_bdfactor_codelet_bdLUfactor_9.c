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
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int *pe = pivot->pe;
    for (i = 0; i < n; i++)
        pe[i] = i + (i > 0 ? pe[i-1] : 0);
}
