#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t len;
extern  char *from;
extern  char *to;
extern size_t setlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (setlen == 0) return;
    for (size_t j = 0; j < len; j++) {
        char c = s[j];
        size_t i = 0;
        do {
            if (c == from[i]) {
                s[j] = to[i];
                break;
            }
            i++;
        } while (i < setlen);
    }
}
