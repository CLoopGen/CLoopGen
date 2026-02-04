#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int i;
extern int j;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Modify access pattern to use a larger stride (stride of 4) to reduce cache conflicts
    // and expose different memory bandwidth characteristics
    int stride = 4;
    for (i = j - 1; i < len - 1; i += stride) {
        sum += data[i] * data[i - j] +
               data[i + 1] * data[i - j + 1];
        // Additional computation to maintain work per iteration balance
        if (i + 2 < len - 1) {
            sum += data[i + 2] * data[i - j + 2] +
                   data[i + 3] * data[i - j + 3];
        }
    }
}
