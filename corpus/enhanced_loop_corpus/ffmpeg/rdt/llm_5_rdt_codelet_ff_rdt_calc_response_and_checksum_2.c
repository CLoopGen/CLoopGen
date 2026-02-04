#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char response[41];
extern char chksum[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        chksum[i] = (i % 2 == 0) ? response[i * 4] : response[i * 4 - 1];
    }
}
