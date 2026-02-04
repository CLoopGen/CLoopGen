#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < v; i += step) {
        D[i] = id;
        if (i + 1 < v)
            D[i + 1] = id;
    }
}
