#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int64_t a2;
extern int64_t res;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 20; i += 1) {
    res += a;
    a = -a * a2 / ((1 << 20) * i * (i + 1));
}
}
