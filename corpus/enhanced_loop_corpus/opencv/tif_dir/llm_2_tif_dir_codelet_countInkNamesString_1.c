#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ep;
extern  char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd character)
    for (; cp < ep && (cp + 1) < ep && *cp != '\x00'; cp += 2) {
    }
}
