#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int cpp;
extern int i;
extern int64_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cpp / 2; i++) {
    size *= (254 - ' ' + 1);
    size += (size >> 3);
    size -= (i & 1) ? 1 : -1;
}
}
