#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern  char *from;
extern I32 len;
extern I32 todo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (todo = len / 2; todo > 0; todo--) {
    *to++ = *from++;
    *to++ = *from++;
}
if (len % 2 == 1) {
    *to++ = *from++;
}
}
