#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern  char *string;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        table[(unsigned char)string[0]] = len - 1;
        for (i = 1; i < len; i++) {
            size_t prev_index = (unsigned char)string[i - 1];
            size_t curr_index = (unsigned char)string[i];
            table[curr_index] = len - i - 1;
            table[prev_index] = len - i; // Re-write previous to create WAW dependency
        }
    }
}
