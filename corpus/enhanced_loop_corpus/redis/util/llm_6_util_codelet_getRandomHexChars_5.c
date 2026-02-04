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
    size_t temp_j;
    char temp_val;
    for (j = 0; j < len; j++) {
        temp_j = j;
        temp_val = charset[p[temp_j] & 15];
        p[temp_j] = temp_val;
    }
}
