#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 0) {
        i = 0;
        for (;;) { // Decreased loop depth: transformed into single-expression loop using empty for condition
            uint32_t a = p1[i];
            uint32_t b = p2[i];
            p1[i] = b - a;
            i++;
            if (i >= length) break;
        }
    }
}
