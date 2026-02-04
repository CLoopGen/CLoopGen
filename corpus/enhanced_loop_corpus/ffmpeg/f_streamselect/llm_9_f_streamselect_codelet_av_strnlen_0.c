#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && i + 8 <= len; i += 8) {
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
        if (!s[i+2]) { i+=2; break; }
        if (!s[i+3]) { i+=3; break; }
        if (!s[i+4]) { i+=4; break; }
        if (!s[i+5]) { i+=5; break; }
        if (!s[i+6]) { i+=6; break; }
        if (!s[i+7]) { i+=7; break; }
    }
    // Handle remaining elements if exited unrolled loop without null found
    for (; i < len && s[i]; i++)
        ;
}
