#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
    uint16 bowtid;
    uint16 firsttg;
} bg_t;

typedef int int32;

extern bg_t *bg;
extern s3lmwid_t w;
extern int32 i;
extern int32 b;
extern int32 e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = b; i < e; i++) {
    for (; bg[i].wid != w && i < e; i++) {
        break;
    }
    if (i < e && bg[i].wid == w) {
        break;
    }
}
}
