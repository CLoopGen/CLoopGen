#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (len > 0) {
        for (; i < len && s[i] != '\0'; i += 2) {
            // Skip every other character to reduce effective trip count and increase stride
            if (i + 1 < len && s[i + 1] == '\0') {
                i++;
                break;
            }
        }
    }
}
