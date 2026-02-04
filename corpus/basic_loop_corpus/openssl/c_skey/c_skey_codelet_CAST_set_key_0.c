#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 16; i++)
    x[i] = 0;

}
