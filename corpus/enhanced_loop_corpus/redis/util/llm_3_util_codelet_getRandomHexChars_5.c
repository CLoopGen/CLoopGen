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
    size_t i;
    for (i = len - 1; i != (size_t)-1; i--) {
        p[i] = charset[p[i] & 15];
    }
}
