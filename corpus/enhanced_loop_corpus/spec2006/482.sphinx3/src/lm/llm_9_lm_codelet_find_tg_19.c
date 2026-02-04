#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
} tg_t;

typedef int int32;

extern tg_t *tg;
extern s3lmwid_t w;
extern int32 i;
extern int32 b;
extern int32 e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 step = 2;
    for (i = b; i < e && i + 1 < e; i += step) {
        if (tg[i].wid == w || tg[i + 1].wid == w) {
            if (tg[i].wid == w) i--;
            break;
        }
    }
    // Adjust i to point to the correct match position if needed
    if (i >= e || i < 0) return;
    while (i > b && tg[i].wid != w) i--; // Final correction using minimal logic
}
