#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t list[256];
extern uint8_t list_inv[256];
extern int counttab[256];
extern int (*counttab2)[256];
extern int i;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    int bestscore = 0;
    int bestv = 0;
    for (x = 0; x < 256; x += 2) {
        int scorev = 0;
        if (list[x])
            continue;
        scorev += counttab2[0][x];
        for (y = 0; y < 128; y++) {
            scorev += list[y] * counttab2[y + 1][x];
        }
        if (scorev) {
            int score = (1024 * scorev) / (counttab[x] + 1);
            if (score > bestscore) {
                bestscore = score;
                bestv = x;
            }
        }
    }
    if (!bestscore)
        break;
    list[bestv] = 1;
    list_inv[i] = bestv;
}
}
