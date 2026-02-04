#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char response[41];
extern char chksum[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        chksum[i] = response[i * 4];
        if (i + 1 < 8) {
            chksum[i + 1] = response[(i + 1) * 4];
        }
    }
}
