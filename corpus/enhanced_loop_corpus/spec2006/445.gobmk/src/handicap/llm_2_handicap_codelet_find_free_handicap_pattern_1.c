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
extern int k;
extern int highest_value;
extern int sum_values;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (process every second element first, then the others)
    // This changes the access pattern to non-consecutive, creating two phases with stride 2
    sum_values = 0;  // Reset sum_values as in original logic

    // First pass: even indices
    for (k = 0; k < number_of_matches; k += 2) {
        if (handicap_matches[k].value < highest_value - 10)
            handicap_matches[k].value = 0;
        else
            handicap_matches[k].value = 1 << (handicap_matches[k].value - highest_value + 10);
        sum_values += handicap_matches[k].value;
    }

    // Second pass: odd indices
    for (k = 1; k < number_of_matches; k += 2) {
        if (handicap_matches[k].value < highest_value - 10)
            handicap_matches[k].value = 0;
        else
            handicap_matches[k].value = 1 << (handicap_matches[k].value - highest_value + 10);
        sum_values += handicap_matches[k].value;
    }
}
