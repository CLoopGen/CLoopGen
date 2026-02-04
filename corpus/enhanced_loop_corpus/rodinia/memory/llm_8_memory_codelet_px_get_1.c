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
    for (i = 0; i < size; i += 2) {
        permute->pe[i] = i;
        if (i + 1 < size) {
            permute->pe[i + 1] = i + 1;
        }
    }
}
