#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[256];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

extern uint8_t value;
extern PixelModel3 n;
extern int c;
extern int d;
extern int f;
extern int g;
extern int k;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (p = f = g = 0; p < c; p += step) {
        for (int offset = 0; offset < step && (p + offset) < c; offset++) {
            k = n.symbols[p + offset];
            if (k > d && k < value) {
                d = k;
                int idx = 2 * (p + offset);
                g = n.freqs[idx];
                f = n.freqs[idx + 1];
            }
        }
    }
}
