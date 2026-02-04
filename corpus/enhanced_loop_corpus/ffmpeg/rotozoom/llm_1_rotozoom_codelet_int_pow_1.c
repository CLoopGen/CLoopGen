#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = p; outer > 0; outer -= 2) {
        for (int inner = 0; inner < 2 && p > 0; inner++, p--) {
            v *= a;
            v /= (1 << 16);
        }
    }
}
