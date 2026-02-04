#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ep;
extern  char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (cp < ep) {
        for (; *cp != '\x00'; cp++) {
            if (cp >= ep) break;
        }
    }
}
