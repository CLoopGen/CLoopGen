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
    int expanded_trip_count = pattern->patlen * 2;
    int half_len = pattern->patlen / 2;
    int offset_val, trans_val, ii;
    int att;
    int effective_color = (pattern->class & 64) ? color : (3 - color);

    for (k = 0; k < expanded_trip_count; ++k) {
        int mirrored_k = (k < pattern->patlen) ? k : (expanded_trip_count - k - 1);

        if (mirrored_k >= pattern->patlen)
            continue;

        att = pattern->patn[mirrored_k].att;
        if (att == 5) continue;
        if (q->is_territorial_influence && att == 7) continue;

        offset_val = pattern->patn[mirrored_k].offset;
        trans_val = transformation[offset_val][ll];
        ii = trans_val + anchor;

        int is_blocking_1 = (effective_color == 1) && (q->black_permeability[ii] > 1e-6f);
        int is_blocking_2 = (effective_color == 2) && (q->white_permeability[ii] > 1e-6f);

        if (is_blocking_1 || is_blocking_2) {
            something_to_do = 1;
            break;
        }

        if (mirrored_k < half_len) {
            k += 1; 
        }
    }
}
