#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *s = src;
uint8_t *d = dst;
int32_t s_stride = src_stride;
int32_t d_stride = dst_stride;
int32_t h = height;

for (cnt = (h >> 2); cnt--;) {
    d[0] = s[0];
    d[d_stride] = s[s_stride];
    d[2*d_stride] = s[2*s_stride];
    d[3*d_stride] = s[3*s_stride];

    // Introduce WAW and WAR dependencies via artificial ordering constraints
    // using dummy computations that modify local state
    int dummy = 0;
    dummy += s[0] + s[s_stride];
    dummy ^= d[0];
    d[0] = dummy & 0xFF;  // Write after write (WAW) on d[0]

    s += 4 * s_stride;
    d += 4 * d_stride;
}

// Ensure outputs are updated
src = s;
dst = d;
}
