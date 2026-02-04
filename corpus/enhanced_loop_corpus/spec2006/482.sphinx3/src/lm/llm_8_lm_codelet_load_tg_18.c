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
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        tg_t temp1 = tg[i];
        tg_t temp2 = tg[i+1];

        *(&(tg[i].wid)) = ((255 & (temp1.wid >> 8)) | (65280 & (temp1.wid << 8)));
        *(&(tg[i].probid)) = ((255 & (temp1.probid >> 8)) | (65280 & (temp1.probid << 8)));

        *(&(tg[i+1].wid)) = ((255 & (temp2.wid >> 8)) | (65280 & (temp2.wid << 8)));
        *(&(tg[i+1].probid)) = ((255 & (temp2.probid >> 8)) | (65280 & (temp2.probid << 8)));
    } else {
        *(&(tg[i].wid)) = ((255 & (*(&(tg[i].wid))) >> 8) | (65280 & (*(&(tg[i].wid))) << 8));
        *(&(tg[i].probid)) = ((255 & (*(&(tg[i].probid))) >> 8) | (65280 & (*(&(tg[i].probid))) << 8));
    }
}
}
