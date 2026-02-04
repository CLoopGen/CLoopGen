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
extern u_int i;
extern u_int j;
extern u_int entry;
extern u_int ok;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    u_int temp_j = i;
    for (j = 0; j < i; j++) {
        temp_j--;
        ok &= (entry != px->pe[temp_j]);
    }
}
