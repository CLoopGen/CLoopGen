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
    for (i = y + 1; i <= m; i++) {
        if (a / i - s != 0) {
            F /= (a / i - s);
        } else {
            F = 0;
            break;
        }
    }
}
