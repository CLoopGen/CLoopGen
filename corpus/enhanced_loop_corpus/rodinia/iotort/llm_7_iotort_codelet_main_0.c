#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *ix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (i = 0; i < 10; i++) {
        ix->ive[i] = prev + 1;
        prev = ix->ive[i];
    }
}
