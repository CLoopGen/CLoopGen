#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned short *work;
extern unsigned int sym;
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < codes; i += 4) {
        for (unsigned int j = 0; j < 4 && (i + j) < codes; j++) {
            sym = i + j;
            if (lens[sym] != 0)
                work[offs[lens[sym]]++] = (unsigned short)sym;
        }
    }
}
