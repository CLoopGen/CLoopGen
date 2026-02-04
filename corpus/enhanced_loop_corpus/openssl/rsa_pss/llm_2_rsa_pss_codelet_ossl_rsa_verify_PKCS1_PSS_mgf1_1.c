#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < (maskedDBLen - 1) && DB[i] == 0; i += 2)
        ;
}
