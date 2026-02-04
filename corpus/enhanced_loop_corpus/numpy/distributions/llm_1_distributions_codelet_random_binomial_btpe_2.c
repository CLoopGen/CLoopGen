#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a;
extern double s;
extern double F;
extern int64_t m;
extern int64_t y;
extern int64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (m + 1 <= y) {
        i = m + 1;
        for (; i <= y; i++) {
            F *= (a / i - s);
        }
    }
}
