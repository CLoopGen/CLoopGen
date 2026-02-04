#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern  char *string;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = len;
    for (i = 0; i < temp_len; i++) {
        size_t index = (unsigned char)string[i];
        size_t value = temp_len - i - 1;
        table[index] = value;
    }
}
