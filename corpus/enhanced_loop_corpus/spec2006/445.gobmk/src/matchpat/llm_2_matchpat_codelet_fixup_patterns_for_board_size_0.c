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
    // Variant 1: Use strided access through an index variable with fixed stride of 1 (simulating potential future extension)
    // This changes the direct pointer arithmetic on 'pattern' to indexed-based strided access
    int idx = 0;
    struct pattern *base_pattern = pattern;
    for (; base_pattern[idx].patn; ++idx) {
        struct pattern *p = &base_pattern[idx];
        if (p->edge_constraints != 0) {
            if (p->edge_constraints & 1)
                p->maxi = p->mini + p->height;
            if (p->edge_constraints & 2)
                p->mini = p->maxi - p->height;
            if (p->edge_constraints & 8)
                p->maxj = p->minj + p->width;
            if (p->edge_constraints & 4)
                p->minj = p->maxj - p->width;
            if (p->edge_constraints & 1)
                if (p->maxi < (board_size - 1) + p->mini)
                    p->maxi = (board_size - 1) + p->mini;
            if (p->edge_constraints & 2)
                if (p->mini > p->maxi - (board_size - 1))
                    p->mini = p->maxi - (board_size - 1);
            if (p->edge_constraints & 8)
                if (p->maxj < (board_size - 1) + p->minj)
                    p->maxj = (board_size - 1) + p->minj;
            if (p->edge_constraints & 4)
                if (p->minj > p->maxj - (board_size - 1))
                    p->minj = p->maxj - (board_size - 1);
        }
    }
}
