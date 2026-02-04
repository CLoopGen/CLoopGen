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
    while (*s && *s != ';') {  // Additional loop to simulate deeper nesting effect via sequential structure
        s++;
        if (len >= sizeof tmpbuf) break;
    }
}
