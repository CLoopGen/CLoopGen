#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (p = 0; (p < num) && (bits[p] == 0); ++p)
    ;

}
