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
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — traverse columns with a fixed stride, unrolling by accessing every 3rd column
    int start_i = m + pat->maxi + 1;
    int end_i = 21 * 3;
    int end_j = 21 * 3;
    for (i = start_i; i < end_i; i++) {
        for (j = 0; j < end_j; j += 3) {  // Stride of 3 in j dimension
            work_space[i][j] = '-';
            if (j + 1 < end_j) work_space[i][j + 1] = '-';
            if (j + 2 < end_j) work_space[i][j + 2] = '-';
        }
    }
}
