#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_i = 0;
    for (; temp_i < len; temp_i++) {
        if (!s[temp_i]) break;
    }
    i = temp_i;
}
