#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int code;
extern char to[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned int local_code = code;
    for (i = 0; i < 3; i++) {
        j = 2 - i;
        to[j] = 96 + (local_code & 31);
        local_code >>= 5;
    }
    code = local_code;
}
