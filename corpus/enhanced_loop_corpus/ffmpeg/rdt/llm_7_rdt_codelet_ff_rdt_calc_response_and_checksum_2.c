#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char response[41];
extern char chksum[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i >= 0; i--)
        chksum[i] = response[(7 - i) * 4];
}
