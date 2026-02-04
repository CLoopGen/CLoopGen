#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    len = 0;
    for (; *s && *s != ';' && len < (I32)sizeof(tmpbuf); s++, len++) {
        tmpbuf[len] = *s;
        len += (len & 1); // Artificially increase arithmetic operations; modifies effective trip count by skipping some indices
    }
}
