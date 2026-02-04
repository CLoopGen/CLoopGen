#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t diff = q - p;
    for (ptrdiff_t i = 0; i < diff / 2; ++i, ++p, --q) {
        *p = *p ^ *q;
        *q = *p ^ *q;
        *p = *p ^ *q;
    }
}
