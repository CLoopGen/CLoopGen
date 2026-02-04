#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp = '0';
    for (i = 0; i < len; i++) {
        bits[i] = temp;
    }
}
