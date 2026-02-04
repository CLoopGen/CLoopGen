#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
    uint16 bowtid;
    uint16 firsttg;
} bg_t;

extern int32 i;
extern int32 n;
extern bg_t *bg;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i <= n; i++) {
    *(&(bg[i].wid)) = ((255 & (*(&(bg[i].wid))) >> 8) | (65280 & (*(&(bg[i].wid))) << 8));
    *(&(bg[i].probid)) = ((255 & (*(&(bg[i].probid))) >> 8) | (65280 & (*(&(bg[i].probid))) << 8));
    *(&(bg[i].bowtid)) = ((255 & (*(&(bg[i].bowtid))) >> 8) | (65280 & (*(&(bg[i].bowtid))) << 8));
    *(&(bg[i].firsttg)) = ((255 & (*(&(bg[i].firsttg))) >> 8) | (65280 & (*(&(bg[i].firsttg))) << 8));
}

}
