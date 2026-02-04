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


extern int board_size;
extern struct pattern *pattern;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index map (simulating irregular memory access)
    // Assume we have a precomputed array of indices that point into valid patterns
    // For realism, we simulate a small lookup table of active pattern indices
    int indices[256];  // Simulated precomputed index list
    int count = 0;
    struct pattern *temp = pattern;

    // Build indirect index list (in practice this could be cached or preprocessed)
    while (temp->patn && count < 255) {
        indices[count++] = temp - pattern;
        temp++;
    }
    indices[count] = -1;  // Sentinel

    // Now iterate using indirect addressing
    for (int i = 0; indices[i] != -1; ++i) {
        struct pattern *p = &pattern[indices[i]];
        if (p->edge_constraints != 0) {
            unsigned int ec = p->edge_constraints;
            int bs_minus_1 = board_size - 1;

            if (ec & 1) {
                p->maxi = p->mini + p->height;
                if (p->maxi < bs_minus_1 + p->mini)
                    p->maxi = bs_minus_1 + p->mini;
            }
            if (ec & 2) {
                p->mini = p->maxi - p->height;
                if (p->mini > p->maxi - bs_minus_1)
                    p->mini = p->maxi - bs_minus_1;
            }
            if (ec & 8) {
                p->maxj = p->minj + p->width;
                if (p->maxj < bs_minus_1 + p->minj)
                    p->maxj = bs_minus_1 + p->minj;
            }
            if (ec & 4) {
                p->minj = p->maxj - p->width;
                if (p->minj > p->maxj - bs_minus_1)
                    p->minj = p->maxj - bs_minus_1;
            }
        }
    }
}
