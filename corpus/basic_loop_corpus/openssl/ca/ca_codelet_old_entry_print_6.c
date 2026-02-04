#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 22 - j; j > 0; j--)
    *(pbuf++) = ' ';

}
