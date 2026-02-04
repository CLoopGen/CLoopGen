#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int code;
extern char to[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i >= 0; i--) {
        if ((code & 31) != 0) {
            to[i] = 96 + (code & 31);
        } else {
            to[i] = 96;
        }
        code >>= 5;
    }
}
