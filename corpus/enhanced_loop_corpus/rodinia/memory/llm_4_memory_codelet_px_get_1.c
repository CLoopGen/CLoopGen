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
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            permute->pe[i] = i;
        } else {
            permute->pe[i] = i + 1;
        }
    }
}
