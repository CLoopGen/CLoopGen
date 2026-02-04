#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern size_t j;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        size_t limit = (i + 1) * tda + N;
        for (j = N; j < tda && (i * tda + j) < limit; j++) {
            if (i * tda + j < limit) {
                status |= (data[i * tda + j] != (12345. + (i * tda + j)));
            }
            if ((i + 1) * tda + j < limit) {
                status |= (data[(i + 1) * tda + j] != (12345. + ((i + 1) * tda + j)));
            }
        }
    }
}
