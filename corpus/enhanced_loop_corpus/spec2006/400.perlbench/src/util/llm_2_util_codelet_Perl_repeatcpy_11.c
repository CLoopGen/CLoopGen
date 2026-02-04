#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern  char *from;
extern I32 len;
extern I32 todo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    todo = len;
    for (I32 i = 0; i < len; i += 2) {
        *to++ = from[i];
        if (i + 1 < len) *to++ = from[i + 1];
    }
    todo = 0;
}
