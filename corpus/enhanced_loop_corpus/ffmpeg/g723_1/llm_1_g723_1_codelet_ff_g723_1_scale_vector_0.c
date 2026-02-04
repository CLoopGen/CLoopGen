#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 0) {
        i = 0;
        for (;;) {
            max |= ((vector[i]) >= 0 ? (vector[i]) : (-(vector[i])));
            i++;
            if (i >= length) break;
        }
    }
}
