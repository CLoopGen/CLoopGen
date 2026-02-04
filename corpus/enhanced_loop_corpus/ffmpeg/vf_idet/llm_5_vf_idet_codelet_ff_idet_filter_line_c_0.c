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
    for (x = 0; x < w; x++) {
        int v = (*a++ + *c++) - 2 * *b++;
        ret += (v < 0) ? -v : v;
        if (ret > 1000) {
            break;
        }
    }
}
