#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef unsigned short uint16;
typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
} tg_t;

int32 i;
int32 n;
tg_t *tg;

void init_vars() {
    n = 1048576; // 1M elements, roughly 4MB of data (each tg_t is 4 bytes)
    tg = (tg_t*)malloc(n * sizeof(tg_t));
    if (!tg) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int32 idx = 0; idx < n; idx++) {
        tg[idx].wid = (uint16)(idx * 31); 
        tg[idx].probid = (uint16)(idx * 97);
    }
}