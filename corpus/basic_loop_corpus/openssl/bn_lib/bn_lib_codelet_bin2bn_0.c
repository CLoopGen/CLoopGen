#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; len > 0 && *s2 == xor; s2 += inc2 , len--)
    continue;

}
