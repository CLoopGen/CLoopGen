#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; p && v != 0; p--) {
    if (v < 0) {
        v = -v;
        continue;
    }
    v *= a;
    v /= (1 << 16);
}
}
