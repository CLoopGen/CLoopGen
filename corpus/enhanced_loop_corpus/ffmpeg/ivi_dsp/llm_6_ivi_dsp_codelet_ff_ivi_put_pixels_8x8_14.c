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
    int32_t temp[8];
    for (y = 0; y < 8; out += pitch, in += 8, y++) {
        for (x = 0; x < 8; x++)
            temp[x] = in[x];  // Introduce temporary storage: break WAW and WAR on 'out'
        for (x = 0; x < 8; x++)
            out[x] = (int16_t)temp[x];  // Write to output only after full read: eliminate RAW between reads and writes to 'out'
    }
}
