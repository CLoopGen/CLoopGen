#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *a;
extern  uint16_t *b;
extern  uint16_t *c;
extern int w;
extern int x;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int v1, v2;
    int i;
    ret = 0;
    for (i = 0; i < w - 1; i += 2) {
        v1 = (a[i] + c[i]) - 2 * b[i];
        v2 = (a[i+1] + c[i+1]) - 2 * b[i+1];
        ret += ((v1) >= 0 ? (v1) : (-v1));
        ret += ((v2) >= 0 ? (v2) : (-v2));
    }
    if (i < w) {
        int v = (a[i] + c[i]) - 2 * b[i];
        ret += ((v) >= 0 ? (v) : (-(v)));
    }
}
