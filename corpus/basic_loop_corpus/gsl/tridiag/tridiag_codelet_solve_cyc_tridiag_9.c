#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *delta;
extern double *z;
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < N - 2; i++) {
    sum += delta[i] * z[i];
}

}
