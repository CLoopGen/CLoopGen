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
    u_int temp = 0;
    for (i = 0; i < n; i++) {
        temp = i;
        pe[i] = temp;
    }
}
