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
for (i = b; (i < e) && (tg[i].wid != w); i++)
    ;

}
