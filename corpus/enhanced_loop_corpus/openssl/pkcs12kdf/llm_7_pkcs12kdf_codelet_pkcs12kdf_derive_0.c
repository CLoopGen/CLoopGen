#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = id;
    for (i = 0; i < v; i++) {
        D[i] = temp;
        temp = D[i]; // Introduce RAW and WAW dependency: read after write, same location
    }
}
