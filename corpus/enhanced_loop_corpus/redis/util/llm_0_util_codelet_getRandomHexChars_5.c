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
    size_t outer_j;
    for (outer_j = 0; outer_j < len; outer_j++) {
        for (j = outer_j; j < outer_j + 1; j++) {
            p[j] = charset[p[j] & 15];
        }
    }
}
