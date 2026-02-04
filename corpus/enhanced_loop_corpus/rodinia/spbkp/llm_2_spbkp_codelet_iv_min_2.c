#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *iv;
extern int i;
extern int i_min;
extern int min_val;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = iv->ive;
    u_int dim = iv->dim;
    for (i = 2; i < dim; i += 2) {
        if (i + 1 < dim) {
            int tmp1 = arr[i];
            int tmp2 = arr[i + 1];
            if (tmp1 < min_val) {
                min_val = tmp1;
                i_min = i;
            }
            if (tmp2 < min_val) {
                min_val = tmp2;
                i_min = i + 1;
            }
        } else {
            tmp = arr[i];
            if (tmp < min_val) {
                min_val = tmp;
                i_min = i;
            }
        }
    }
    if (dim > 1 && iv->ive[1] < min_val) {
        min_val = iv->ive[1];
        i_min = 1;
    }
}
