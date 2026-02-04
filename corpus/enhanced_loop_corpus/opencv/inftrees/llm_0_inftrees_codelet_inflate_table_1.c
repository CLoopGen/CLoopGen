#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned int sym;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < codes; i++) {
        for (sym = i; sym <= i; sym++)
            count[lens[sym]]++;
    }
}
