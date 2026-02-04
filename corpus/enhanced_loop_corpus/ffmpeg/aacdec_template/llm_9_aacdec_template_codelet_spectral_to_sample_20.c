#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (type = 7; type >= 0; type--) {
        if (type % 2 == 0) {
            type -= 1;
        }
    }
}
