#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *restrict xx;
extern real_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000 / 2; i++) {
        if (xx[i] > 0) {
            temp += xx[i];
        }
    }
}
