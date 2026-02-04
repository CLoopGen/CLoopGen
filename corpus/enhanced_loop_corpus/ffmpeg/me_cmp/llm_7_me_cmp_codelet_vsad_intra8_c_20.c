#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_score = score;
    ptrdiff_t offset = stride;
    uint8_t *local_s = s;

    for (y = 1; y < h; y++) {
        for (x = 0; x < 8; x += 4) {
            int diff1 = local_s[x] - local_s[x + offset];
            int diff2 = local_s[x + 1] - local_s[x + 1 + offset];
            int diff3 = local_s[x + 2] - local_s[x + 2 + offset];
            int diff4 = local_s[x + 3] - local_s[x + 3 + offset];

            local_score += (diff1 >= 0 ? diff1 : -diff1) +
                           (diff2 >= 0 ? diff2 : -diff2) +
                           (diff3 >= 0 ? diff3 : -diff3) +
                           (diff4 >= 0 ? diff4 : -diff4);
        }
        local_s += offset;
    }

    s = local_s;
    score = local_score;
}
