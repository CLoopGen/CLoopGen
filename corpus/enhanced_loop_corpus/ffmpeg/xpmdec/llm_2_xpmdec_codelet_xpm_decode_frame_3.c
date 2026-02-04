#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int cpp;
extern int i;
extern int64_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp_size = size;
    for (i = 0; i < cpp; i += 1) {
        temp_size *= (254 - ' ' + 1);
    }
    size = temp_size;
}
