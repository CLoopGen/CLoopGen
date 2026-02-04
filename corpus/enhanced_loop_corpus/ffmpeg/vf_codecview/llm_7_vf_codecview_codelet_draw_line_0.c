#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ex;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_buf[256]; // Local accumulation to break write-after-write (WAW) on buf
    for (x = 0; x <= ex && x < 256; x++) {
        y = (x * f) >> 16;
        fr = (x * f) & 65535;
        int contribution = (color * (65536 - fr)) >> 16;
        local_buf[x] = contribution; // Remove direct write to buf, eliminate WAR/WAW across iterations
    }
    // Finalize writes in reverse order to alter data flow
    for (x = ex < 255 ? ex : 255; x >= 0; x--) {
        y = (x * f) >> 16;
        buf[y * stride + x] += local_buf[x];
        fr = (x * f) & 65535;
        if (fr)
            buf[(y + 1) * stride + x] += (color * fr) >> 16;
    }
}
