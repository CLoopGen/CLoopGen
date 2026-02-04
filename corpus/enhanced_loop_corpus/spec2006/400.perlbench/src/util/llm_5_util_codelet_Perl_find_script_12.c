#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; *s && *s != ';' && len < sizeof tmpbuf; len++, s++) {
        tmpbuf[len] = *s;
    }
    if (*s && *s != ';' && len == sizeof tmpbuf) {
        // Prevent overflow by stopping early if buffer is full
    }
}
