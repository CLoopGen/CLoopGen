#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    char temp = 0;
    for (j = 0; j < bytes; j += 8) {
        if (j + 0 < bytes) dest[j + 0] = temp;
        if (j + 1 < bytes) dest[j + 1] = temp;
        if (j + 2 < bytes) dest[j + 2] = temp;
        if (j + 3 < bytes) dest[j + 3] = temp;
        if (j + 4 < bytes) dest[j + 4] = temp;
        if (j + 5 < bytes) dest[j + 5] = temp;
        if (j + 6 < bytes) dest[j + 6] = temp;
        if (j + 7 < bytes) dest[j + 7] = temp;
    }
}
