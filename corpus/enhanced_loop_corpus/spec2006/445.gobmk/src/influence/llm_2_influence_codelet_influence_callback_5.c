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



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing patn[k] with potential non-consecutive offsets, we restructure to iterate through a transformed array
    // assuming precomputed transformation results for better spatial locality.
    int *transformed_offsets = (int*)__builtin_alloca(pattern->patlen * sizeof(int));
    float *perm_values = (float*)__builtin_alloca(pattern->patlen * sizeof(float));
    
    for (int k = 0; k < pattern->patlen; ++k) {
        transformed_offsets[k] = transformation[pattern->patn[k].offset][ll] + anchor;
        int att = pattern->patn[k].att;
        if (att == 1)
            perm_values[k] = q->black_permeability[transformed_offsets[k]];
        else if (att == 2)
            perm_values[k] = q->white_permeability[transformed_offsets[k]];
        else
            perm_values[k] = 0.0f;
    }

    int blocking_color = (pattern->class & 64) ? color : (3 - color);
    int target_perm_idx = (blocking_color == 1) ? 1 : 2;

    for (k = 0; k < pattern->patlen; ++k) {
        int att = pattern->patn[k].att;
        if (att != 5 && (!q->is_territorial_influence || att != 7))
            break;
        if (target_perm_idx == 1 && perm_values[k] != 0.) {
            something_to_do = 1;
            break;
        }
        if (target_perm_idx == 2 && perm_values[k] != 0.) {
            something_to_do = 1;
            break;
        }
    }
}
