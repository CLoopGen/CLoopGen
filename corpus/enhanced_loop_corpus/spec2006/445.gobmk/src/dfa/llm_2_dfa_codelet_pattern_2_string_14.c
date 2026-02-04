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


extern struct pattern *pat;
extern char work_space[84][84];
extern int m;
extern int n;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening 2D indices into a 1D traversal
    // This improves spatial locality by accessing memory in increasing order
    int start_i = pat->mini + m;
    int end_i = pat->maxi + m + 1;
    int start_j = pat->minj + n;
    int end_j = pat->maxj + n + 1;
    
    for (int idx = 0; idx < (end_i - start_i) * (end_j - start_j); idx++) {
        int i = start_i + idx / (end_j - start_j);
        int j = start_j + idx % (end_j - start_j);
        work_space[i][j] = '?';
    }
}
