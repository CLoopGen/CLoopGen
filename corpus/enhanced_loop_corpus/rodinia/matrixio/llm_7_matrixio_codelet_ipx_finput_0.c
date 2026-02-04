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
    ok = 1;
    for (j = 0; j < i; j += 2) {
        u_int comp1 = (entry != px->pe[j]);
        u_int comp2 = 1;
        if (j + 1 < i) {
            comp2 = (entry != px->pe[j + 1]);
        }
        ok &= (comp1 & comp2);
    }
}
