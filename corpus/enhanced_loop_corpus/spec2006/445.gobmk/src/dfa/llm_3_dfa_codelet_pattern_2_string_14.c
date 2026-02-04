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
    // Variant 2: Strided memory access with column-major traversal (j varies faster, but outer loop on j)
    // This changes access pattern to stride through rows per fixed column, altering cache behavior
    int start_i = pat->mini + m;
    int end_i = pat->maxi + m + 1;
    int start_j = pat->minj + n;
    int end_j = pat->maxj + n + 1;
    
    for (j = start_j; j != end_j; j++)
        for (i = start_i; i != end_i; i++)
            work_space[i][j] = '?';
}
