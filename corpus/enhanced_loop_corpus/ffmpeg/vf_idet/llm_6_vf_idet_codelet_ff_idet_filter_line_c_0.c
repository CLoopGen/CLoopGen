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
    int temp_ret = 0;
    uint8_t *a_local = a;
    uint8_t *b_local = b;
    uint8_t *c_local = c;
    for (x = 0; x < w; x++) {
        int v1 = *a_local++;
        int v2 = *b_local++;
        int v3 = *c_local++;
        int v = (v1 + v3) - 2 * v2;
        temp_ret += ((v) >= 0 ? (v) : (-(v)));
    }
    ret += temp_ret;
}
