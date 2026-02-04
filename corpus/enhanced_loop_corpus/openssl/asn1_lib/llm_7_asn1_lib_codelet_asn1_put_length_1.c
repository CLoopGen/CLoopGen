#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = 0;
    for (i = 0; len > 0; i++, j++) {
        len >>= 8;
        i = j; // Create WAR dependency: write to 'i' after read in loop increment; also introduces loop-carried dependency via 'j'
    }
}
