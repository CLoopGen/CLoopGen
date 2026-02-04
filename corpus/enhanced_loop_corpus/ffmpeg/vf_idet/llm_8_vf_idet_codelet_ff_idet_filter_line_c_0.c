#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern  uint8_t *c;
extern int w;
extern int x;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w; x += 2) {
        int v1 = (*a++ + *c++) - 2 * *b++;
        int v2 = (x + 1 < w) ? (*a++ + *c++) - 2 * *b++ : 0;
        ret += ((v1) >= 0 ? (v1) : (-(v1)));
        if (x + 1 < w) {
            ret += ((v2) >= 0 ? (v2) : (-(v2)));
        }
    }
}
