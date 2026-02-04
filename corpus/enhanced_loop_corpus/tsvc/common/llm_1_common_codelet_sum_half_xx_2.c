#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *restrict xx;
extern real_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000 / 2; i += 4) {
        temp += xx[i];
        if (i + 1 < 32000 / 2) temp += xx[i + 1];
        if (i + 2 < 32000 / 2) temp += xx[i + 2];
        if (i + 3 < 32000 / 2) temp += xx[i + 3];
    }
}
