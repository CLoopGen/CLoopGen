#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch <= 1; ++ch) {
    int8_t *const top = (int8_t*)&ch;
    int8_t *const left = top + 1;
    *left = *top + ch;
}
}
