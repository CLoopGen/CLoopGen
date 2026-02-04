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
    u_int *pe_local = px->pe;
    for (i = px->size; i < new_size; i++) {
        pe_local[i] = i;
        pe_local[i + 1] = pe_local[i] + 1; // Introduce WAW and RAW dependency: reuse current iteration's write in next (simulated via offset)
    }
    if (new_size > px->size) {
        pe_local[new_size] = new_size; // Fix potential out-of-bounds from last iteration
    }
}
