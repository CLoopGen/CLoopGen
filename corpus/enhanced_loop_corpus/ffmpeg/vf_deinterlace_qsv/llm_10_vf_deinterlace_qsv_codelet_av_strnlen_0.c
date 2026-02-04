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
    size_t limit = len - (len % 2);
    for (; i < limit; i += 2) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++;
            break;
        }
    }
    // Handle remaining single element without while
    for (; i < len && s[i]; i++)
        ;
}
