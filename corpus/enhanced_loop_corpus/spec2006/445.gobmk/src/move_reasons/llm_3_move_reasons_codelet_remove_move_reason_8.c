#include <stdio.h>

#include <inttypes.h>

struct move_data {
    float value;
    float final_value;
    float additional_ko_value;
    float territorial_value;
    float strategical_value;
    float maxpos_shape;
    float maxneg_shape;
    int numpos_shape;
    int numneg_shape;
    float followup_value;
    float influence_followup_value;
    float reverse_followup_value;
    float secondary_value;
    float min_value;
    float max_value;
    float min_territory;
    float max_territory;
    float randomness_scaling;
    int reason[120];
    int move_safety;
    int worthwhile_threat;
    float random_number;
};


struct move_reason {
    int type;
    int what;
    int status;
};


extern struct move_data move[400];
extern struct move_reason move_reasons[1000];
extern int pos;
extern int type;
extern int what;
extern int k;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index remapping for irregular memory access
    // Simulate a strided or indirect pattern via a virtual stride of 3 (modulo to stay in bounds)
    n = -1;
    int indices[120];
    // Precompute indirect access pattern: pseudo-strided index sequence
    for (int i = 0; i < 120; i++) {
        indices[i] = (i * 3) % 120; // Stride-like indirect indexing
    }
    for (k = 0; k < 120; k++) {
        int idx = indices[k]; // Use indirect index
        int r = move[pos].reason[idx];
        if (r < 0)
            break;
        if (move_reasons[r].type == type && move_reasons[r].what == what)
            n = idx; // Store original logical index (idx), not loop counter
    }
}
