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
    if (n > 0) {
        *(&(tg[0].wid)) = ((255 & (*(&(tg[0].wid))) >> 8) | (65280 & (*(&(tg[0].wid))) << 8));
        *(&(tg[0].probid)) = ((255 & (*(&(tg[0].probid))) >> 8) | (65280 & (*(&(tg[0].probid))) << 8));
    }
    for (i = 1; i < n; i++) {
        *(&(tg[i].wid)) = ((255 & (*(&(tg[i-1].wid))) >> 8) | (65280 & (*(&(tg[i-1].wid))) << 8));
        *(&(tg[i].probid)) = ((255 & (*(&(tg[i-1].probid))) >> 8) | (65280 & (*(&(tg[i-1].probid))) << 8));
    }
}
