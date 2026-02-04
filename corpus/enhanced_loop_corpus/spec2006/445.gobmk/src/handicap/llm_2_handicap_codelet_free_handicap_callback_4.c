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


struct handicap_match {
    int value;
    int anchor;
    struct pattern *pattern;
    int ll;
};


extern struct handicap_match handicap_matches[40];
extern int number_of_matches;
extern int r;
extern int k;
extern int least_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the array with a stride of 2, then handle remainder
    int k1;
    least_value = __INT32_MAX__;  // Ensure initialization for correctness
    r = -1;

    // Stride by 2 forward pass
    for (k1 = 0; k1 < number_of_matches; k1 += 2) {
        if (handicap_matches[k1].value < least_value) {
            r = k1;
            least_value = handicap_matches[k1].value;
        }
    }
    // Handle odd-sized array by checking last element if needed
    if (number_of_matches > 0 && (number_of_matches % 2) == 1) {
        int last_idx = number_of_matches - 1;
        if (handicap_matches[last_idx].value < least_value) {
            r = last_idx;
            least_value = handicap_matches[last_idx].value;
        }
    }

    // Secondary pass with reverse strided access to simulate different memory behavior
    for (k1 = number_of_matches - 2; k1 >= 0; k1 -= 2) {
        if (handicap_matches[k1].value < least_value) {
            r = k1;
            least_value = handicap_matches[k1].value;
        }
    }

    k = r; // Preserve original semantics where `k` holds final index
}
