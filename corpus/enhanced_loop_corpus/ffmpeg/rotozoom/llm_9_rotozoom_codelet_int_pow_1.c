#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_p = p;
    for (; temp_p > 0; temp_p -= 2) {
        if (temp_p >= 1) {
            v *= a;
            v /= (1 << 16);
        }
        if (temp_p >= 2) {
            v += a * 2;
            v -= (1 << 8);
        }
    }
}
