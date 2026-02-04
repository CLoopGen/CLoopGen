#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int var;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    for (j = 0; j < 8; j++) {
        var += (((a[j] - a[j + s]) ^ ((a[j] - a[j + s]) >> 31)) - ((a[j] - a[j + s]) >> 31));
    }
    a += s;
}
}
