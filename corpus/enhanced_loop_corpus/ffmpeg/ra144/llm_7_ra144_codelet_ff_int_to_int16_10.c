#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int *inp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev = 0;
    for (i = 0; i < 10; i++) {
        int16_t current = (int16_t)(*inp++);
        *out++ = current + prev;
        prev = current;
    }
}
