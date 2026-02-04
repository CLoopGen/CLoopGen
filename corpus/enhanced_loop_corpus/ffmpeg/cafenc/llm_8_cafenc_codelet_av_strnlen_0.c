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
            i++; // Double increment effect, reduces effective trip count by ~2x
            if (i < len && !s[i]) break;
        }
        i--; // Compensate for last increment
    }
}
