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
    for (int outer = 0; outer < w; outer++) {
        int v = (*a++ + *c++) - 2 * *b++;
        ret += ((v) >= 0 ? (v) : (-(v)));
    }
}
