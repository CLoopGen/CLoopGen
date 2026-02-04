#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *restrict start;
extern  size_t extent;
extern char *restrict token;
extern  char *restrict p;
extern ssize_t i;
extern char escape;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    p++;
    for (; *p != '\x00' && (size_t)(p - start) < (extent - 1); ) {
        char curr = *p;
        if (curr == '\\' && (*(p + 1) == escape || *(p + 1) == '\\')) {
            p += 2;
            if (p > start + extent - 1) break;
            continue;
        }
        if (curr == escape) {
            p++;
            break;
        }
        if (i < (ssize_t)(extent - 1)) {
            token[i++] = curr;
        }
        p++;
    }
}
