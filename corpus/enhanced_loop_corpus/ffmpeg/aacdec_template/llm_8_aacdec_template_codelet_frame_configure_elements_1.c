#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int sum = 0;
    for (type = 0; type < 16; type += 2) {
        sum += type * type + 3 * type - 5;
    }
}
