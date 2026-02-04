#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < sizeof (inbuf); i++)
    inbuf[i] = (unsigned char)(255 & i);

}
