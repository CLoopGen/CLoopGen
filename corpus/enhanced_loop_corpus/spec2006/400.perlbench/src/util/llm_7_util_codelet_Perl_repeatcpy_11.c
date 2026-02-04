#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern  char *from;
extern I32 len;
extern I32 todo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 i;
    char temp;
    for (i = 0; i < len; i++) {
        temp = from[i];
        to[i] = temp;
    }
}
