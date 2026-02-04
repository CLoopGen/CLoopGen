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
    int stride = 2;
    int limit_i = (m + pat->maxi + 1 + stride - 1) / stride;
    int limit_j = (n + pat->minj + stride - 1) / stride;
    for (i = 0; i < limit_i; i++) {
        for (j = 0; j < limit_j; j++) {
            int real_i = i * stride;
            int real_j = j * stride;
            if (real_i < 84 && real_j < 84) {
                work_space[real_i][real_j] = '|';
            }
            // Unrolled adjacent elements with bounds check
            if (real_i + 1 < 84 && real_j < 84) {
                work_space[real_i + 1][real_j] = '|';
            }
            if (real_i < 84 && real_j + 1 < 84) {
                work_space[real_i][real_j + 1] = '|';
            }
            if (real_i + 1 < 84 && real_j + 1 < 84) {
                work_space[real_i + 1][real_j + 1] = '|';
            }
        }
    }
}
