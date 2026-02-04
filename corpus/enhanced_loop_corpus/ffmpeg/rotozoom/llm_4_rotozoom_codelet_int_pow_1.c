#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; p > 0; p--) {
    if (a == 0) {
        v = 0;
        break;
    }
    v *= a;
    v /= (1 << 16);
}
}
