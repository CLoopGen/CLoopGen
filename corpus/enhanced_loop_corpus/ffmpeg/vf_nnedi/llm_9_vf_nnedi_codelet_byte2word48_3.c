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
for (y = 0; y < 4; y++)
    for (x = 0; x < 12; x += 3)
        for (int z = 0; z < 3; z++)
            if (x + z < 12)
                p[y * 12 + x + z] = t[y * pitch * 2 + x + z];
}
