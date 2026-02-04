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

extern uint32_t val;
extern PixelModel3 n;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int limit = (size > 256) ? 256 : size;
    for (i = 0; i < limit; i += step) {
        n.cnts[i] = (val == n.symbols[i]) ? (n.freqs[i] = 100, n.maxpos = i, n.cntsum += 1) : (n.freqs[i] = 50, n.cntsum += 0);
        if (i + 1 < limit) {
            n.cnts[i+1] = (val == n.symbols[i+1]) ? (n.freqs[i+1] = 100, n.maxpos = i+1, n.cntsum += 1) : (n.freqs[i+1] = 50, n.cntsum += 0);
        }
    }
    // Final pass for any remaining element if size is odd and step caused undercount
    if (limit % 2 == 1 && limit < 256) {
        i = limit;
        n.freqs[i] = (val == n.symbols[i]) ? 100 : 50;
        if (val == n.symbols[i]) n.maxpos = i;
    }
}
