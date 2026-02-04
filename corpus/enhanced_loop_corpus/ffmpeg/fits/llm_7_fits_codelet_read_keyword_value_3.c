#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i = i;
    for (; local_i < 80; local_i++) {
        if (ptr8[local_i] == ' ' || ptr8[local_i] == '/') break;
        *(value + (local_i - i)) = ptr8[local_i];
    }
    i = local_i;
}
