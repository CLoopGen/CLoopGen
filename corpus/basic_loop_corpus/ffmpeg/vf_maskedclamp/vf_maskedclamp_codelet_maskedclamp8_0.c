#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint8_t *bsrc;
extern  uint8_t *darksrc;
extern  uint8_t *brightsrc;
extern uint8_t *dst;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int x = 0; x < w; x++) {
    dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
    dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
}

}
