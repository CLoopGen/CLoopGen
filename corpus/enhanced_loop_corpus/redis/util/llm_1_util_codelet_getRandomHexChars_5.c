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
    if (len > 0) {
        for (j = 0; j < len; j += 2) {
            p[j] = charset[p[j] & 15];
            if (j + 1 < len) {
                p[j + 1] = charset[p[j + 1] & 15];
            }
        }
    }
}
