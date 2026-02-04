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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access over the pattern->patn array to simulate non-unit stride.
    // This may be useful in scenarios where patterns exhibit regularity with periodicity.
    // We use a fixed stride of 2 and traverse both even and odd phases if needed.

    const int STRIDE = 2;
    int base = 0;

    // First pass: even indices
    for (int step = 0; step < (pattern->patlen + STRIDE - 1) / STRIDE; ++step) {
        int k = base + step * STRIDE;
        if (k >= pattern->patlen) continue;

        int pos = (transformation[pattern->patn[k].offset][ll] + anchor);
        if (pattern->patn[k].att == 2) {
            if (first_dragon == 0)
                first_dragon = dragon[pos].origin;
            else if (second_dragon == 0 && dragon[pos].origin != first_dragon) {
                second_dragon = dragon[pos].origin;
                break;
            }
        }
    }

    // Second pass: odd indices, if necessary (full coverage)
    base = 1;
    for (int step = 0; step < (pattern->patlen + STRIDE - 1) / STRIDE; ++step) {
        int k = base + step * STRIDE;
        if (k >= pattern->patlen) continue;

        int pos = (transformation[pattern->patn[k].offset][ll] + anchor);
        if (pattern->patn[k].att == 2) {
            if (first_dragon == 0)
                first_dragon = dragon[pos].origin;
            else if (second_dragon == 0 && dragon[pos].origin != first_dragon) {
                second_dragon = dragon[pos].origin;
                break;
            }
        }
    }
}
