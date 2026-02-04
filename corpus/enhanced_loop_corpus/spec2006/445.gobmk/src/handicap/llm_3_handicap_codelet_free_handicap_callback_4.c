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
    // Variant 2: Indirect (Index-Array Based) Memory Access Pattern
    // Use an auxiliary index array to access handicap_matches indirectly
    // Simulates non-contiguous or reordered memory access

    // Assume we precomputed an indirect access order (e.g., sorted by value, or scrambled)
    // Here we simulate it via modulo-based permutation without extra setup
    int indices[40];
    int n = number_of_matches;
    if (n > 40) n = 40; // Bound check based on known size

    // Create a pseudo-random but deterministic indirect access pattern using linear congruential map
    for (int i = 0; i < n; i++) {
        indices[i] = (i * 17 + 13) % n;  // Strided permutation for indirect access
    }

    least_value = __INT32_MAX__;
    r = -1;

    for (int idx = 0; idx < n; idx++) {
        int k_index = indices[idx];  // Indirect access index
        if (handicap_matches[k_index].value < least_value) {
            r = k_index;
            least_value = handicap_matches[k_index].value;
        }
    }

    k = r; // Maintain original output in `k`
}
