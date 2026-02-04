#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *d;
extern I32 i;
extern I32 min;
extern I32 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = min; i <= max; i++) {
    if (i < 0)
        continue;
    *d++ = (char)i;
}
}
