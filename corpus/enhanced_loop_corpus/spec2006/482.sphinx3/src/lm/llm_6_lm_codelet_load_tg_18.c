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
    for (i = 0; i < n; i++) {
        s3lmwid_t temp_wid = tg[i].wid;
        uint16 temp_probid = tg[i].probid;

        tg[i].wid = ((255 & (temp_wid >> 8)) | (65280 & (temp_wid << 8)));
        tg[i].probid = ((255 & (temp_probid >> 8)) | (65280 & (temp_probid << 8)));
    }
}
