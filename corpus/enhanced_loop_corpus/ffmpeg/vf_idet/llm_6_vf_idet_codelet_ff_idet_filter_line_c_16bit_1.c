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
    uint16_t temp_a, temp_b, temp_c;
    int v = 0;
    int local_ret = 0;
    for (x = 0; x < w; x++) {
        temp_a = a[x];
        temp_c = c[x];
        temp_b = b[x];
        v = (temp_a + temp_c) - 2 * temp_b;
        local_ret += ((v) >= 0 ? (v) : (-(v)));
    }
    ret += local_ret;
}
