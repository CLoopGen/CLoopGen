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
for (k = 0; k < pattern->patlen; ++k) {
    int blocking_color;
    int ii;
    for (int inner = 0; inner < 1; ++inner) {
        if (pattern->patn[k].att != 5 && (!q->is_territorial_influence || pattern->patn[k].att != 7))
            break;
        ii = (transformation[pattern->patn[k].offset][ll] + anchor);
        if (pattern->class & 64)
            blocking_color = color;
        else
            blocking_color = (1 + 2 - (color));
        if ((blocking_color == 1 && q->black_permeability[ii] != 0.) || (blocking_color == 2 && q->white_permeability[ii] != 0.)) {
            something_to_do = 1;
            break;
        }
    }
}
}
