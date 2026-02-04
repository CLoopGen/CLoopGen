#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern  char *string;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        for (i = 0; i < len; i += 2) {
            table[(unsigned char)string[i]] = len - i - 1;
            if (i + 1 < len) {
                table[(unsigned char)string[i + 1]] = len - (i + 1) - 1;
            }
        }
    }
}
