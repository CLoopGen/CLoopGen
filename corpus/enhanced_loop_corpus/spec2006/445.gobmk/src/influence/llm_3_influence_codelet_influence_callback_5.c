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
    // Variant 2: Strided Memory Access Pattern
    // We modify the access to patn array with a fixed stride (e.g., every 2nd element) to simulate cache line skipping,
    // then handle remaining elements in a second pass if needed, though here we keep logic correct by adjusting bounds.
    // This variant assumes stride-2 access for performance testing under strided memory behavior.

    int base_blocking_color = (pattern->class & 64) ? color : (3 - color);
    int effective_patlen = pattern->patlen;

    // First pass: strided access by 2 (even indices)
    for (k = 0; k < effective_patlen; k += 2) {
        int att = pattern->patn[k].att;
        if (att != 5 && (!q->is_territorial_influence || att != 7))
            continue;  // Skip but don't break on invalid att

        int ii = transformation[pattern->patn[k].offset][ll] + anchor;
        int perm_check = (base_blocking_color == 1 && q->black_permeability[ii] != 0.) ||
                         (base_blocking_color == 2 && q->white_permeability[ii] != 0.);
        if (perm_check) {
            something_to_do = 1;
            break;
        }
    }

    // Second pass: odd indices, only if something_to_do is still unset
    if (!something_to_do) {
        for (k = 1; k < effective_patlen; k += 2) {
            int att = pattern->patn[k].att;
            if (att != 5 && (!q->is_territorial_influence || att != 7))
                continue;

            int ii = transformation[pattern->patn[k].offset][ll] + anchor;
            int perm_check = (base_blocking_color == 1 && q->black_permeability[ii] != 0.) ||
                             (base_blocking_color == 2 && q->white_permeability[ii] != 0.);
            if (perm_check) {
                something_to_do = 1;
                break;
            }
        }
    }
}
