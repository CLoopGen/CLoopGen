#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *a;
extern  int16_t *b;
extern int length;
extern int i;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < length; i += 2) {
        if (i + 1 < length) {
            sum += (a[i] * b[i]) + (a[i+1] * b[i+1]);
        } else {
            sum += a[i] * b[i];
        }
    }
}
