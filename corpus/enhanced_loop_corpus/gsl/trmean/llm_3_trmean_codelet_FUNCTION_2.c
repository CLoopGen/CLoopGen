#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *array = (double*)malloc((ihigh - ilow + 1) * sizeof(double));
    size_t stride = 2;
    for (i = ilow; i <= ihigh; i += stride) {
        size_t index = (i - ilow) % ((ihigh - ilow + 1) > 0 ? (ihigh - ilow + 1) : 1);
        double delta = array[index]; // Strided memory access with step size 2
        k += 1.;
        mean += delta / k;
    }
    free(array);
}
