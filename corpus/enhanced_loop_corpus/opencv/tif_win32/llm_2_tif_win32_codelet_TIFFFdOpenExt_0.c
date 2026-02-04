#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *mode;
extern int fSuppressMap;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t i;
    char *base = mode;
    for (i = 0; base[i] != 0; i += 1) {
        if (*(base + i) == 'u') {
            fSuppressMap = 1;
            break;
        }
    }
}
