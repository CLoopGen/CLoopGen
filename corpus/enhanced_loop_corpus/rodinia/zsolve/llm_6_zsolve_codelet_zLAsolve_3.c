#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern int i;
extern complex *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_dim = dim;
    complex* local_b_ve = b_ve;
    int temp_i = local_dim - 1;
    for (i = local_dim - 1; i >= 0; i--) {
        if (!((local_b_ve[temp_i]).re == 0. && (local_b_ve[temp_i]).im == 0.)) {
            i = temp_i; // Introduce WAW dependency on 'i' and break
            break;
        }
        temp_i--;
    }
}
