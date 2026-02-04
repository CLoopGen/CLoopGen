#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch <= 1; ++ch) {
    int8_t temp = 42;
    int8_t *const top = &temp;
    int8_t *const left = &temp;
    if (ch > 0) {
        *top = *(left - 0) - 1;
    }
}
}
