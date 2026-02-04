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
        int64_t prod1 = (i + 0 < length) ? (int64_t)a[i + 0] * b[i + 0] : 0;
        int64_t prod2 = (i + 1 < length) ? (int64_t)a[i + 1] * b[i + 1] : 0;
        sum += prod1 + prod2;
    }
}
