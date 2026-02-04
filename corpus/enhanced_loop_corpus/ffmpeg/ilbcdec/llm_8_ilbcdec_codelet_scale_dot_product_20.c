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
    sum = 0;
    for (int i = 0; i < length; i += 2) {
        if (i + 1 < length) {
            sum += ((v1[i] * v2[i]) >> scaling) + ((v1[i+1] * v2[i+1]) >> scaling);
        } else {
            sum += (v1[i] * v2[i]) >> scaling;
        }
    }
}
