#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N >= 2) {
        for (i = 0; i < N / 2; i++) {
            size_t j = N - i - 1;
            {
                double tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
            i++;
            if (i < N / 2) {
                j = N - i - 1;
                {
                    double tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
            }
        }
    }
}
