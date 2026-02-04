#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < v; i++) {
        D[i] = id ^ (unsigned char)(i & 0xFF);
        for (j = 0; j < 3; j++) {
            D[i] ^= (D[i] >> (j + 1)) ^ (id + j);
        }
    }
}
