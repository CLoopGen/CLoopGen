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
    u_int temp_ok = 1;
    u_int stride = 2;
    u_int limit = (i + 1) / stride;

    for (j = 0; j < limit; j++) {
        u_int idx1 = j * stride;
        u_int idx2 = idx1 + 1;
        temp_ok &= (idx1 < i) ? (entry != px->pe[idx1]) : 1;
        temp_ok &= (idx2 < i) ? (entry != px->pe[idx2]) : 1;
    }
    ok &= temp_ok;
}
