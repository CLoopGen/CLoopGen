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
extern IVEC *iy;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ix->dim; i++) {
        int temp = 2 * i - 1;
        ix->ive[i] = temp;
        iy->ive[i] = 3 * i + 2;
    }
}
