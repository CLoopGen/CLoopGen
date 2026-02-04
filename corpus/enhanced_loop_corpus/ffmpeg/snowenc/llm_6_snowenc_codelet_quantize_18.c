#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

typedef short IDWTELEM;

extern DWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern int x;
extern int y;
extern IDWTELEM *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w <= 0 || h <= 0) return;
    DWTELEM *s = src;
    IDWTELEM *d = dst;
    int s_stride = stride;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            d[j] = (IDWTELEM)s[j]; // Remove loop-carried dependency by using local pointers and direct indexing
        }
        s += s_stride;
        d += s_stride;
    }
}
