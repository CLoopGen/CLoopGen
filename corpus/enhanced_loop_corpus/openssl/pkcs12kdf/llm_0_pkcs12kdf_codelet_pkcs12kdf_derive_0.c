#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < v; j++) {
        for (i = j; i <= j; i++)
            D[i] = id;
    }
}
