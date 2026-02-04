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
    for (i = 0; i < length; i++) {
        int16_t temp_a = a[i];
        int16_t temp_b = b[i];
        if (temp_a != 0 && temp_b != 0) {
            sum += temp_a * temp_b;
        }
    }
}
