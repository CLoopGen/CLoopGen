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
    uint16 temp_wid = bg[i].wid;
    uint16 temp_prob = bg[i].probid;
    uint16 temp_bow = bg[i].bowtid;
    uint16 temp_first = bg[i].firsttg;

    bg[i].wid = (temp_wid >> 8) | (temp_wid << 8);
    bg[i].probid = (temp_prob >> 8) | (temp_prob << 8);
    bg[i].bowtid = (temp_bow >> 8) | (temp_bow << 8);
    bg[i].firsttg = (temp_first >> 8) | (temp_first << 8);
}
}
