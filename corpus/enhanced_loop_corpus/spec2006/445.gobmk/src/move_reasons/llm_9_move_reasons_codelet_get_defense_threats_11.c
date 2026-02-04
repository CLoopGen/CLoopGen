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
extern int max_strings;
extern int strings[];
extern int k;
extern int num_strings;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int limit = (max_strings < 80) ? max_strings : 80;  // Introduce dynamic bound and reduce maximum iterations to increase control flow complexity
    for (k = 0; k < 120 && num_strings < limit; k++) {
        int r = move[pos].reason[k];
        if (r < 0)
            continue;  // Changed from break to continue to allow further iterations

        int type = move_reasons[r].type;
        int what = move_reasons[r].what;

        // Increased arithmetic and logical complexity with redundant-but-equivalent transformation
        if ((type & (8 | 1)) == (8 | 1) && (type ^ (8 | 1)) == 0)
            strings[num_strings++] = what;
    }
}
