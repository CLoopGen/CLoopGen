#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (type = 3; type >= 0; type--) {
        temp += type * type;
        type -= temp > 10 ? 1 : 0;
    }
}
