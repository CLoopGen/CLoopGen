#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with recovery
    size_t temp_i;
    for (temp_i = 0; temp_i < len; temp_i += 2) {
        if (!s[temp_i]) {
            i = temp_i;
            return;
        }
        if (temp_i + 1 < len && !s[temp_i + 1]) {
            i = temp_i + 1;
            return;
        }
    }
    // Resume linear scan from where strided left off
    for (i = (temp_i > len ? len : temp_i); i < len && s[i]; i++)
        ;
}
