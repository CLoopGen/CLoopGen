#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *v1;
extern  int16_t *v2;
extern int length;
extern int scaling;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = length;
    for (int i = 0; i < n; i += 2) {
        sum += (v1[i] * v2[i]) >> scaling;
        if (i + 1 < length) {
            sum += (v1[i + 1] * v2[i + 1]) >> scaling;
        }
    }
}
