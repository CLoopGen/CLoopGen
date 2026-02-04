#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i = 0;
    while (local_i < len && s[local_i]) {
        local_i++;
    }
    i = local_i;
}
