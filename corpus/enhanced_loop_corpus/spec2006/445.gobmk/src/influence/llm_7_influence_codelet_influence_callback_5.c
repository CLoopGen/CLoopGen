#include <stdio.h>

#include <inttypes.h>

struct patval {
    int offset;
    int att;
};


typedef int (*pattern_helper_fn_ptr)(struct pattern *, int, int, int);

typedef int (*autohelper_fn_ptr)(int, int, int, int);

struct pattern {
    struct patval *patn;
    int patlen;
    int trfno;
    const char *name;
    int mini;
    int minj;
    int maxi;
    int maxj;
    int height;
    int width;
    unsigned int edge_constraints;
    int move_offset;
    unsigned int and_mask[8];
    unsigned int val_mask[8];
    unsigned int class;
    float value;
    float maxvalue;
    float minterritory;
    float maxterritory;
    float shape;
    float followup;
    float reverse_followup;
    int autohelper_flag;
    pattern_helper_fn_ptr helper;
    autohelper_fn_ptr autohelper;
    int anchored_at_X;
    float constraint_cost;
};


struct intrusion_data {
    int source_pos;
    int strength_pos;
    float strength;
    float attenuation;
};


struct influence_data {
    char safe[400];
    float white_influence[400];
    float black_influence[400];
    float white_strength[400];
    float black_strength[400];
    float white_attenuation[400];
    float black_attenuation[400];
    float white_permeability[400];
    float black_permeability[400];
    int territory_segmentation[400];
    int moyo_segmentation[400];
    int area_segmentation[400];
    int region_type[1084];
    int region_size[1084];
    float region_territorial_value[1084];
    int number_of_regions;
    int is_territorial_influence;
    float territory_value[400];
    int non_territory[400];
    int captured;
    int color_to_move;
    int queue[361];
    int intrusion_counter;
    struct intrusion_data intrusions[722];
};


extern int transformation[1369][8];
extern int anchor;
extern int color;
extern struct pattern *pattern;
extern int ll;
extern int k;
extern struct influence_data *q;
extern int something_to_do;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int found_intrusion = 0;
    int base_anchor = anchor;  // Introduce loop-invariant copy to modify access pattern

    // Eliminate loop-carried dependencies entirely; make each iteration independent
    // Unroll assumption: small patlen, e.g., up to 4; we simulate partial unrolling effect via manual restructuring

    for (k = 0; k < pattern->patlen && !found_intrusion; ++k) {
        struct patval current_pat = pattern->patn[k];  // Full copy introduces RAW within iteration only

        // Independent computation of condition without side effects
        int att_cond = (current_pat.att == 5) || (q->is_territorial_influence && current_pat.att == 7);
        if (!att_cond) continue;

        // Compute transformed index independently
        int xform_index = transformation[current_pat.offset][ll];
        int ii = xform_index + base_anchor;  // Base anchor is invariant

        // Determine blocking color without data race or dependency
        int blocking_color = (pattern->class & 64) ? color : (3 - color);

        // Direct read with no intermediate storage — eliminates artificial dependencies
        float perm = (blocking_color == 1) ?
                     q->black_permeability[ii] :
                     q->white_permeability[ii];

        // Immediate update with early exit (minimal WAW: only one write possible)
        if (perm != 0.0f) {
            something_to_do = 1;
            found_intrusion = 1;  // Local flag to control loop (not shared)
        }
    }

    // No further action: side effect already written
}
