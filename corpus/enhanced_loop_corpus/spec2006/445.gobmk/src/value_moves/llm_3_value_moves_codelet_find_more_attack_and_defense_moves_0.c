#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

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


extern int board_size;
extern Intersection board[421];
extern struct worm_data worm[400];
extern int unstable_worms[240];
extern int N;
extern int m;
extern int n;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Index Array-Based) Memory Access Pattern
    // Precompute valid indices into a lookup table, then iterate over that table
    // to access board and worm data indirectly. This changes access pattern from
    // regular row-major to data-dependent indirect access.
    int total_elements = board_size * board_size;
    int indices[400]; // Assuming board_size <= 20 -> max 400 elements
    int count = 0;

    // Precompute all linearized indices
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            indices[count++] = ((19 + 2) + m * (19 + 1) + n);
        }
    }

    N = 0; // Reset counter

    // Use indirect access via precomputed indices
    for (int idx = 0; idx < total_elements; idx++) {
        ii = indices[idx];
        if (board[ii] && worm[ii].origin == ii && worm[ii].attack_codes[0] != 0 && worm[ii].defense_codes[0] != 0) {
            unstable_worms[N] = ii;
            N++;
        }
    }
}
