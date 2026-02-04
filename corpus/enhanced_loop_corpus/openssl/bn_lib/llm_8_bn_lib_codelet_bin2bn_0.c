#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < len && *(s2 + i * inc2) == xor; i++)
        ; // Empty body, just advance index
    len -= i;
    s2 += i * inc2;
}
