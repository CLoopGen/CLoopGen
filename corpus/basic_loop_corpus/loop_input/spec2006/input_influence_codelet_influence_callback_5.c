#include <stdio.h>
#include <stdlib.h>
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
    int is_territorial_influence;  // Added missing field
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
    float white_permeability_padding[24];  // Padding to align to 424 bytes if needed
    float black_permeability_padding[24];
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

int transformation[1369][8];
int anchor = 100;
int color = 1;
struct pattern *pattern;
int ll = 0;
int k = 0;
struct influence_data *q;
int something_to_do = 0;

void init_vars() {
    // Allocate and initialize pattern structure
    int patlen = 50;
    struct patval *patn_array = (struct patval *)calloc(patlen, sizeof(struct patval));
    for (int i = 0; i < patlen; ++i) {
        patn_array[i].offset = i * 10;
        patn_array[i].att = (i % 3 == 0) ? 5 : ((i % 7 == 0) ? 7 : 0);
    }

    pattern = (struct pattern *)malloc(sizeof(struct pattern));
    pattern->patn = patn_array;
    pattern->patlen = patlen;
    pattern->trfno = 0;
    pattern->name = "test_pattern";
    pattern->mini = 0;
    pattern->minj = 0;
    pattern->maxi = 19;
    pattern->maxj = 19;
    pattern->height = 19;
    pattern->width = 19;
    pattern->edge_constraints = 0;
    pattern->move_offset = 0;
    for (int i = 0; i < 8; ++i) {
        pattern->and_mask[i] = 0xFFFFFFFF;
        pattern->val_mask[i] = 0x00000000;
    }
    pattern->class = 64;
    pattern->value = 1.0f;
    pattern->maxvalue = 1.0f;
    pattern->minterritory = 0.0f;
    pattern->maxterritory = 1.0f;
    pattern->shape = 0.5f;
    pattern->followup = 0.3f;
    pattern->reverse_followup = 0.2f;
    pattern->autohelper_flag = 0;
    pattern->helper = NULL;
    pattern->autohelper = NULL;
    pattern->anchored_at_X = 0;
    pattern->constraint_cost = 0.1f;
    pattern->is_territorial_influence = 1;

    // Initialize influence_data
    q = (struct influence_data *)malloc(sizeof(struct influence_data));
    for (int i = 0; i < 400; ++i) {
        q->safe[i] = 0;
        q->white_influence[i] = 0.0f;
        q->black_influence[i] = 0.0f;
        q->white_strength[i] = 0.1f + i * 0.001f;
        q->black_strength[i] = 0.1f + i * 0.001f;
        q->white_attenuation[i] = 0.9f;
        q->black_attenuation[i] = 0.9f;
        q->white_permeability[i] = (i % 50 == 0) ? 0.0f : 0.5f;
        q->black_permeability[i] = (i % 50 == 0) ? 0.0f : 0.5f;
    }
    for (int i = 0; i < 400; ++i) {
        q->territory_segmentation[i] = i % 10;
        q->moyo_segmentation[i] = i % 8;
        q->area_segmentation[i] = i % 5;
    }
    for (int i = 0; i < 1084; ++i) {
        q->region_type[i] = i % 4;
        q->region_size[i] = 10 + (i % 100);
        q->region_territorial_value[i] = 0.2f + (i % 10) * 0.1f;
    }
    q->number_of_regions = 100;
    q->is_territorial_influence = 1;
    for (int i = 0; i < 400; ++i) {
        q->territory_value[i] = 0.3f;
        q->non_territory[i] = 0;
    }
    q->captured = 0;
    q->color_to_move = 1;
    for (int i = 0; i < 361; ++i) {
        q->queue[i] = i;
    }
    q->intrusion_counter = 0;
    for (int i = 0; i < 722; ++i) {
        q->intrusions[i].source_pos = i;
        q->intrusions[i].strength_pos = i % 400;
        q->intrusions[i].strength = 1.0f;
        q->intrusions[i].attenuation = 0.5f;
    }

    // Initialize transformation array
    for (int i = 0; i < 1369; ++i) {
        for (int j = 0; j < 8; ++j) {
            transformation[i][j] = (i + j) % 100;
        }
    }

    // Set global variables
    anchor = 100;
    color = 1;
    ll = 0;
    something_to_do = 0;
}