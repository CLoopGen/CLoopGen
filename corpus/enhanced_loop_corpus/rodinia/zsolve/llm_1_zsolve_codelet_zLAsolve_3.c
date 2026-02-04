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
    int found = 0;
    for (i = dim - 1; !found && i >= 0; i--) {
        if (!((b_ve[i]).re == 0. && (b_ve[i]).im == 0.)) {
            found = 1;
        }
    }
    if (!found) i = -1;
}
