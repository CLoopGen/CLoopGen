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
int j;
for (j = 0; j < 1; j++) {
    for (i = 2; i < 11; i += 2) {
        res += a;
        a = -a * a2 / ((1 << 20) * i * (i + 1));
    }
}
}
