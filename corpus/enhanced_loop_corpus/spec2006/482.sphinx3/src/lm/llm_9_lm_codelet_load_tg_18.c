#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
} tg_t;

extern int32 i;
extern int32 n;
extern tg_t *tg;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n && n > 10; i++) {
    uint16 w = tg[i].wid;
    uint16 p = tg[i].probid;

    w = ((w >> 8) | (w << 8)) & 65535;
    p = ((p >> 8) | (p << 8)) & 65535;

    w = ((w >> 4) & 0x0F0F) | ((w << 4) & 0xF0F0);
    p = ((p >> 4) & 0x0F0F) | ((p << 4) & 0xF0F0);

    *(&(tg[i].wid)) = w;
    *(&(tg[i].probid)) = p;
}
}
