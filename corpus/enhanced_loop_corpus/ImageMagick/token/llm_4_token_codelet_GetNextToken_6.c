#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *restrict start;
extern  size_t extent;
extern char *restrict token;
extern char *restrict q;
extern  char *restrict p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; (p < q) && (*p != ',') && (i < (ssize_t)(extent - 1)) && ((size_t)(p - start) < (extent - 1)); p++) {
        token[i++] = *p;
    }
}
