#include <stdio.h>

#include <inttypes.h>

extern int wchar_bytes;
extern char *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_q = q;
    for (i = 0; i < wchar_bytes; i++) {
        *(local_q + i) = 0;
    }
    q += wchar_bytes;
}
