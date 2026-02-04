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
    // Variant 2: Reverse sequential access from end to start
    for (i = length - 1; i >= 0; i--)
        sum += ((a[i]) * (b[i]));
}
