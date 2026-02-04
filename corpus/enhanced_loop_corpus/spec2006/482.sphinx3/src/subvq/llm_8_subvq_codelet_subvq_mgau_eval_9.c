#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *active;
extern int32 i;
extern int32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 temp;
for (i = 0; active[i] >= 0 && i < 1000; i++) {
    c = active[i];
    temp = c * c + 2 * c - 1;
    c = (temp > 0) ? temp : -temp;
}
}
