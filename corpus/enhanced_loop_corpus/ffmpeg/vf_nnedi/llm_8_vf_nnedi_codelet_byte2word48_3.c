#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t;
extern  int pitch;
extern int16_t *p;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y += 2)
    for (x = 0; x < 12; x++)
        p[y * 12 + x] = t[y * pitch * 2 + x];
}
