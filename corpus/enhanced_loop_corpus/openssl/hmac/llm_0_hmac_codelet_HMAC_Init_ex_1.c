#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 12; i++)
    for (j = 0; j < 12; j++)
        pad[i * 12 + j] = 92 ^ keytmp[i * 12 + j];
}
