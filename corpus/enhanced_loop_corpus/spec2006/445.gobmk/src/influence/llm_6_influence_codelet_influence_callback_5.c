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
    int local_something_to_do = 0;
    int temp_offset[256];  // Assuming patlen <= 256 for stack allocation
    int temp_att[256];
    int blocking_color_cached[256];
    float permeability_value;

    // Pre-load pattern data to eliminate repeated memory access (WAW and RAW dependency introduced)
    for (k = 0; k < pattern->patlen; ++k) {
        temp_offset[k] = pattern->patn[k].offset;
        temp_att[k] = pattern->patn[k].att;
    }

    for (k = 0; k < pattern->patlen; ++k) {
        int att_val = temp_att[k];
        if (att_val != 5 && (!q->is_territorial_influence || att_val != 7)) {
            break;
        }

        int ii = transformation[temp_offset[k]][ll] + anchor;

        // Cache blocking_color computation to create loop-carried dependence on prior iterations
        if (k == 0) {
            if (pattern->class & 64)
                blocking_color_cached[k] = color;
            else
                blocking_color_cached[k] = 3 - color;  // Equivalent to (1 + 2 - color)
        } else {
            // Introduce WAR dependency: current blocking_color depends on previous iteration's result
            blocking_color_cached[k] = 3 - blocking_color_cached[k - 1];
        }

        int bc = blocking_color_cached[k];

        // Load permeability once per iteration to reduce redundant access (eliminate RAW within body)
        if (bc == 1)
            permeability_value = q->black_permeability[ii];
        else
            permeability_value = q->white_permeability[ii];

        if (permeability_value != 0.0f) {
            local_something_to_do = 1;
            break;
        }
    }

    // Final write to global only after loop completes (convert loop-carried WAW into single write)
    if (local_something_to_do)
        something_to_do = 1;
}
