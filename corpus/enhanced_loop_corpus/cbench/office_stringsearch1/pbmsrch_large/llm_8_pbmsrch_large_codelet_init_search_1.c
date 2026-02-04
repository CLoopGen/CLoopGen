#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern  char *string;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && len > 0; i += 2) {
        size_t index1 = (unsigned char)string[i];
        table[index1] = len - i - 1;
        if (i + 1 < len) {
            size_t index2 = (unsigned char)string[i + 1];
            table[index2] = len - (i + 1) - 1;
        }
    }
}
