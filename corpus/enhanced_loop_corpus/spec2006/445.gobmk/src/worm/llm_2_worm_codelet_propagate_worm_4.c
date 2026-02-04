#include <stdio.h>

#include <inttypes.h>

struct worm_data {
    int color;
    int size;
    float effective_size;
    int origin;
    int liberties;
    int liberties2;
    int liberties3;
    int liberties4;
    int lunch;
    int cutstone;
    int cutstone2;
    int genus;
    int inessential;
    int invincible;
    int unconditional_status;
    int attack_points[10];
    int attack_codes[10];
    int defense_points[10];
    int defense_codes[10];
    int attack_threat_points[10];
    int attack_threat_codes[10];
    int defense_threat_points[10];
    int defense_threat_codes[10];
};


extern struct worm_data worm[400];
extern int pos;
extern int k;
extern int num_stones;
extern int stones[361];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the stones array with a stride of 2,
    // processing even indices first, then odd indices in a second pass to maintain correctness.
    for (int stride = 0; stride < 2; stride++) {
        for (k = stride; k < num_stones; k += 2) {
            if (stones[k] != pos)
                worm[stones[k]] = worm[pos];
        }
    }
}
