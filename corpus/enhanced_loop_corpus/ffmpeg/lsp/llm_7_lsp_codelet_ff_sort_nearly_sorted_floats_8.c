#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i++) {
        for (j = i; j > 0; j--) {
            float current = vals[j];
            float prev = vals[j - 1];
            if (prev > current) {
                vals[j] = prev;
                vals[j - 1] = current;
            } else {
                break;
            }
        }
    }
}
