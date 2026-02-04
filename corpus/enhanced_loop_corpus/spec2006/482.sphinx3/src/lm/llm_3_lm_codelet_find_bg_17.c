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
    // Variant 2: Indirect memory access via index array (simulated using arithmetic)
    // Using an auxiliary indexing pattern: access bg[b + ((i-b)*3 % (e-b+1))] to create non-consecutive access
    int32 n = e - b + 1;
    for (i = b; (i < e) && (bg[b + ((i - b) * 3) % n].wid != w); i++)
        ;
}
