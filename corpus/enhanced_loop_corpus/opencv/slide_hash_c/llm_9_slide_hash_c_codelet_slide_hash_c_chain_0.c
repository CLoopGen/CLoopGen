#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint16_t Pos;

extern uint32_t entries;
extern uint16_t wsize;
extern unsigned int i;
extern Pos *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (entries + 3) / 4; i++) {
        Pos t = (Pos)wsize;
        Pos m;
        m = *q; *q++ = (Pos)(m >= t && m - t >= t ? m - t - t : (m >= t ? m - t : 0));
        m = *q; *q++ = (Pos)(m >= t && m - t >= t ? m - t - t : (m >= t ? m - t : 0));
        m = *q; *q++ = (Pos)(m >= t && m - t >= t ? m - t - t : (m >= t ? m - t : 0));
        m = *q; *q++ = (Pos)(m >= t && m - t >= t ? m - t - t : (m >= t ? m - t : 0));
    }
}
