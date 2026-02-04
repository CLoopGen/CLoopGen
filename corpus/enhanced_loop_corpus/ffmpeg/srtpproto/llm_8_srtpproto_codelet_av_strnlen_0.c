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
        for (; i < len; i++) {
            if (!s[i]) break;
            i++; 
            if (i >= len) break;
            if (!s[i]) break;
        }
        if (i > len) i = len;
    }
}
