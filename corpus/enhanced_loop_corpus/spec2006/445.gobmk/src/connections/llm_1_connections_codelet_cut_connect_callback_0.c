#include <stdio.h>

#include <inttypes.h>

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};


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


extern int transformation[1369][8];
extern struct dragon_data dragon[400];
extern int anchor;
extern struct pattern *pattern;
extern int ll;
extern int k;
extern int first_dragon;
extern int second_dragon;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 1; ++outer) {
    for (int k = 0; k < pattern->patlen; ++k) {
        int pos = (transformation[pattern->patn[k].offset][ll] + anchor);
        if (pattern->patn[k].att == 2) {
            if (first_dragon == 0) {
                first_dragon = dragon[pos].origin;
            } else if (second_dragon == 0 && dragon[pos].origin != first_dragon) {
                second_dragon = dragon[pos].origin;
                break;
            }
        }
    }
}
}
