#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern int killer_scores[300];
extern int killer_scores2[300];
extern int killer_scores3[300];
extern move_s dummy;
extern move_s killer1[300];
extern move_s killer2[300];
extern move_s killer3[300];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration complexity using indirect indexing and conditional updates
    for (i = 0; i < 100; i++) {
        int base_idx = i * 3;
        int offset_a = (base_idx + 7) % 300;
        int offset_b = (base_idx + 13) % 300;
        int offset_c = (base_idx + 19) % 300;

        // Perform multiple dependent arithmetic operations
        killer_scores[offset_a] = ((offset_a + 1) * (offset_a + 2)) / 2;
        killer_scores2[offset_a] = ((offset_a + 3) * (offset_a + 4)) / 3;
        killer_scores3[offset_a] = ((offset_a + 5) * (offset_a + 6)) / 4;
        killer1[offset_a] = dummy;
        killer2[offset_a] = dummy;
        killer3[offset_a] = dummy;

        killer_scores[offset_b] = ((offset_b + 1) * (offset_b + 2)) / 2;
        killer_scores2[offset_b] = ((offset_b + 3) * (offset_b + 4)) / 3;
        killer_scores3[offset_b] = ((offset_b + 5) * (offset_b + 6)) / 4;
        killer1[offset_b] = dummy;
        killer2[offset_b] = dummy;
        killer3[offset_b] = dummy;

        killer_scores[offset_c] = ((offset_c + 1) * (offset_c + 2)) / 2;
        killer_scores2[offset_c] = ((offset_c + 3) * (offset_c + 4)) / 3;
        killer_scores3[offset_c] = ((offset_c + 5) * (offset_c + 6)) / 4;
        killer1[offset_c] = dummy;
        killer2[offset_c] = dummy;
        killer3[offset_c] = dummy;
    }
}
