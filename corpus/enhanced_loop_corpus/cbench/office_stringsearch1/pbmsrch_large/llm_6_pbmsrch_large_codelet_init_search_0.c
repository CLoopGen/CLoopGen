#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = len;
    for (i = 0; i <= (127 * 2 + 1); i++)
        table[i] = temp_len;
}
