#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 1; k++)
        for (j = 0; j < zeroes; j++)
            bits[i++] = '0';
}
