#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int16_t *out;
extern ptrdiff_t pitch;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; out += pitch * 2, in += 16, y++)
    for (x = 0; x < 4; x++) {
        out[x]         = in[x];
        out[x + 4]     = in[x + 8];
    }
}
