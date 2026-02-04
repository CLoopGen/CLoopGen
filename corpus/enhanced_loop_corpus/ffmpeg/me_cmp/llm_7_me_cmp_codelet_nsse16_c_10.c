#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score1;
extern int score2;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_s1 = s1;
    uint8_t *local_s2 = s2;
    int local_score1 = score1;
    int local_score2 = score2;

    for (y = 0; y < h; y++) {
        for (x = 0; x < 16; x++) {
            int diff = local_s1[x] - local_s2[x];
            local_score1 += diff * diff;
        }
        if (y + 1 < h) {
            for (x = 0; x < 15; x += 3) { // Change stride of x to create different access pattern and reduce dependencies
                int val1 = 0, val2 = 0;
                // Unroll and combine three terms to introduce intra-iteration dependencies
                for (int k = 0; k < 3 && (x + k) < 15; k++) {
                    int g1 = local_s1[x+k] - local_s1[x+k+stride] - local_s1[x+k+1] + local_s1[x+k+stride+1];
                    int g2 = local_s2[x+k] - local_s2[x+k+stride] - local_s2[x+k+1] + local_s2[x+k+stride+1];
                    val1 += (g1 >= 0 ? g1 : -g1);
                    val2 += (g2 >= 0 ? g2 : -g2);
                }
                local_score2 += val1 - val2;
            }
        }
        local_s1 += stride;
        local_s2 += stride;
    }
    // Write back accumulated results to break WAW and WAR conflicts with external state
    score1 = local_score1;
    score2 = local_score2;
}
