#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (half = len2; tmp > 1; half += half, tmp >>= 1) {
        if (tmp & 1) {
            tmp += 1;
        }
    }
}
