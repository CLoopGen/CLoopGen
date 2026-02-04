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
    int indices[5] = {2, 4, 6, 8, 10};
    for (i = 0; i < 5; i++) {
        res += a;
        a = -a * a2 / ((1 << 20) * indices[i] * (indices[i] + 1));
    }
}
