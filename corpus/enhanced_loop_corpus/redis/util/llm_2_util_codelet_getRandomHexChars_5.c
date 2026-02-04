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
    char *temp = malloc(len * sizeof(char));
    if (!temp) return;
    for (i = 0; i < len; i++) {
        temp[i] = charset[p[i] & 15];
    }
    for (i = 0; i < len; i++) {
        p[i] = temp[i];
    }
    free(temp);
}
