#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ret;
extern int i;
extern short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ret && ret > 5; i += 4) {
        if (ret - i > 4) {
            *p = ~*p;
        }
        p += 2;
    }
}
