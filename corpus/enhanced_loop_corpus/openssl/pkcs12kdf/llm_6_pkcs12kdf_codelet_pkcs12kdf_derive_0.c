#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < v; j += 2) {
        if (j + 1 < v) {
            D[j] = id;
            D[j + 1] = id;
        } else {
            D[j] = id;
        }
    }
}
