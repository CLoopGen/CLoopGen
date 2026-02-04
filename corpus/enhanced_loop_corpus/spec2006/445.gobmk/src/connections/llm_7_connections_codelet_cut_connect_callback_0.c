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
    int local_first = first_dragon;
    int local_second = second_dragon;
    int updated_first = 0;
    int updated_second = 0;
    for (k = 0; k < pattern->patlen; ++k) {
        int offset_val = pattern->patn[k].offset;
        int att_val = pattern->patn[k].att;
        int trans_pos = transformation[offset_val][ll];
        int pos = trans_pos + anchor;
        if (att_val == 2) {
            if (!updated_first) {
                local_first = dragon[pos].origin;
                updated_first = 1;
            }
            else if (!updated_second && dragon[pos].origin != local_first) {
                local_second = dragon[pos].origin;
                updated_second = 1;
                break;
            }
        }
    }
    first_dragon = local_first;
    second_dragon = local_second;
}
