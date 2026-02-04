#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern size_t len;
extern char *charset;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < len; j += 2) {
        if (j + 1 < len) {
            p[j] = charset[p[j] & 15];
            p[j + 1] = charset[p[j + 1] & 15];
        } else {
            p[j] = charset[p[j] & 15];
        }
    }
}
