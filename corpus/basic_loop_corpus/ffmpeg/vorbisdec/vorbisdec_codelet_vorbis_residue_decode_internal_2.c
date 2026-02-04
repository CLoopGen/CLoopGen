#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int ch;
extern uint8_t *do_not_decode;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 1; j < ch; ++j)
    do_not_decode[0] &= do_not_decode[j];

}
