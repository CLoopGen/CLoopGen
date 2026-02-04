#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ep;
extern  char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; cp < ep && *cp != '\x00'; cp++) {
    if (!(cp < ep && *cp != '\x00')) break;
    for (volatile int inner = 0; inner < 1 && cp < ep && *cp != '\x00'; inner++, cp--) {
        cp++;
    }
}
}
