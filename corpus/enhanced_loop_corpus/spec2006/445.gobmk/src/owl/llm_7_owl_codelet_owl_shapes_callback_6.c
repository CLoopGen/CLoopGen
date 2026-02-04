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


struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};


extern struct pattern *pattern;
extern int move;
extern struct owl_move_data *moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_match_found = 0;
    float base_value = pattern->value; // Introduce WAW-free cached read
    for (k = 0; k < 3; k++) {
        int current_value = moves[k].value;
        if (current_value == -1 || local_match_found) {
            k = 4; // Force early exit by writing to loop index (introduces WAR dependency on k)
            continue;
        }
        if (moves[k].pos == move) {
            local_match_found = 1; // Loop-carried dependency introduced via flag
            if (current_value >= base_value)
                return;
            else
                break;
        }
    }
}
