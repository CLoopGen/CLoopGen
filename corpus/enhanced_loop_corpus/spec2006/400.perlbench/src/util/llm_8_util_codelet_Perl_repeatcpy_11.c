#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern  char *from;
extern I32 len;
extern I32 todo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (todo = len; todo > 0; todo -= 2) {
        *to++ = *from++;
        if (--todo > 0) {
            *to++ = *from++;
        }
    }
}
