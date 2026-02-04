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
uint16 prev_wid = 0, prev_probid = 0;
for (i = 0; i <= n; i++) {
    uint16 current_wid = bg[i].wid;
    uint16 current_probid = bg[i].probid;

    *(&(bg[i].wid)) = ((255 & (current_wid >> 8)) | (65280 & (current_wid << 8)));
    *(&(bg[i].probid)) = ((255 & (prev_probid >> 8)) | (65280 & (prev_probid << 8)));

    prev_wid = current_wid;
    prev_probid = current_probid;
}

if (n >= 0) {
    *(&(bg[n].probid)) = ((255 & (prev_probid >> 8)) | (65280 & (prev_probid << 8)));
}
}
