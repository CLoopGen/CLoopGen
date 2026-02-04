#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; *s && *s != ';' && len + 2 < sizeof tmpbuf; len += 2, s++) {
        tmpbuf[len]     = *s;
        tmpbuf[len + 1] = (len + 1 < sizeof tmpbuf - 1) ? *(s + 1) : '\0';
        if (*(s + 1) == ';' || *(s + 1) == '\0') break;
        s++;
    }
}
