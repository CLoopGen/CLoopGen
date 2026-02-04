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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing reason[0], reason[1], ..., access with a stride of 2
    // This changes the memory access pattern to non-consecutive, potentially improving cache behavior for certain workloads
    for (k = 0; k < 120; k += 2) {
        int r1 = move[pos].reason[k];
        if (r1 >= 0 && move_reasons[r1].type == type && move_reasons[r1].what == what)
            return;
        if (k + 1 < 120) {
            int r2 = move[pos].reason[k + 1];
            if (r2 >= 0 && move_reasons[r2].type == type && move_reasons[r2].what == what)
                return;
            if (r1 < 0 && r2 < 0)
                break;
        } else if (r1 < 0) {
            break;
        }
    }
}
