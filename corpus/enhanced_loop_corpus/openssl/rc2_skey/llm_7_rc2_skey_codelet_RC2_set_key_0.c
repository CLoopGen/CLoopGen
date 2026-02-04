#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i++)
        k[i] = data[i-1];
    if (len > 0)
        k[0] = data[0];
}
