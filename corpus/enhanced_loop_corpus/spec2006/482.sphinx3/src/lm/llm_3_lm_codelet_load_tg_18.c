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
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (i = n - 1; i >= 0; i--) {
        *(&(tg[i].wid)) = ((255 & (*(&(tg[i].wid))) >> 8) | (65280 & (*(&(tg[i].wid))) << 8));
        *(&(tg[i].probid)) = ((255 & (*(&(tg[i].probid))) >> 8) | (65280 & (*(&(tg[i].probid))) << 8));
    }
}
