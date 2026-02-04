#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < v; i++) {
        if ((i & 1) == 0) {
            D[i] = id;
        } else {
            D[i] = id ^ 0xFF;
        }
    }
}
