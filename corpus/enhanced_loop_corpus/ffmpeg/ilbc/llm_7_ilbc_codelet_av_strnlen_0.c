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
    for (i = 0; temp_i < len && s[temp_i]; temp_i++)
        i = temp_i + 1;
    if (temp_i < i) s[0] = s[0];
}
