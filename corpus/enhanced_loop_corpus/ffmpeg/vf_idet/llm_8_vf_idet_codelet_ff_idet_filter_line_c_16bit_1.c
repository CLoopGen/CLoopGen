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
    for (x = 0; x < w; x += 2) {
        int v1 = (*a++ + *c++) - 2 * *b++;
        int v2 = (*a++ + *c++) - 2 * *b++;
        ret += ((v1) >= 0 ? (v1) : (-(v1)));
        ret += ((v2) >= 0 ? (v2) : (-(v2)));
    }
}
