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
    for (i = ilow; i <= ihigh; ++i) {
        size_t index = i - ilow;
        double delta = array[index];
        k += 1.;
        mean += delta / k;
    }
    free(array);
}
