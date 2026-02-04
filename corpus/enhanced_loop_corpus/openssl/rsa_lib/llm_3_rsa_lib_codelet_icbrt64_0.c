#include <stdio.h>

#include <inttypes.h>

extern uint64_t x;
extern uint64_t r;
extern uint64_t b;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t access_map[22];
    int idx = 0;
    for (s = 63; s >= 0; s -= 3) {
        access_map[idx++] = s;
    }
    for (int i = 0; i < 22; i++) {
        s = access_map[i];
        r <<= 1;
        b = 3 * r * (r + 1) + 1;
        if ((x >> s) >= b) {
            x -= b << s;
            r++;
        }
    }
}
