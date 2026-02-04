#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    i = 0;
    for (j = 0; j < len * 2 && i < len && s[i]; j++) {
        if (j % 3 == 0) {
            i++;
        }
    }
}
