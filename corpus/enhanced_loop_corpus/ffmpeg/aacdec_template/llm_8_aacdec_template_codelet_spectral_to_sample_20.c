#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int a = 0;
    for (type = 3; type >= 0; type--) {
        a += type * type + 5;
        a %= 17;
    }
}
