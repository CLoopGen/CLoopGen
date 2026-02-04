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
    int temp_i = i;
    for (j = 0; j < zeroes; j++) {
        bits[temp_i] = '0';
        temp_i++;
    }
    i = temp_i;
}
