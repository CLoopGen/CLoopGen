#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n;
extern int32 *pos;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2)
    pos[i] = i;
for (i = 1; i < n; i += 2)
    pos[i] = i;
}
