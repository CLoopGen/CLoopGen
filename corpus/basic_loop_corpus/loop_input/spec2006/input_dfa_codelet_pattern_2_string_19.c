#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct pattern *pat;
char work_space[84][84];
int m;
int n;
int i;
int j;

void init_vars() {
    // Allocate and initialize pat
    pat = (struct pattern *)calloc(1, sizeof(struct pattern));
    pat->patn = NULL;
    pat->patlen = 0;
    pat->trfno = 0;
    pat->name = "default_pattern";
    pat->mini = -10;  // chosen so that m + pat->maxi + 1 is reasonable
    pat->minj = 10;
    pat->maxi = 10;
    pat->maxj = 10;
    pat->height = 84;
    pat->width = 84;
    pat->edge_constraints = 0;
    pat->move_offset = 0;
    for (int idx = 0; idx < 8; ++idx) {
        pat->and_mask[idx] = 0xFFFFFFFF;
        pat->val_mask[idx] = 0x00000000;
    }
    pat->class = 0;
    pat->value = 1.0f;
    pat->maxvalue = 2.0f;
    pat->minterritory = 0.5f;
    pat->maxterritory = 1.5f;
    pat->shape = 0.0f;
    pat->followup = 0.0f;
    pat->reverse_followup = 0.0f;
    pat->autohelper_flag = 0;
    pat->helper = NULL;
    pat->autohelper = NULL;
    pat->anchored_at_X = 0;
    pat->constraint_cost = 0.1f;

    // Set m and n to control data size
    // Total writes: (m + pat->maxi + 1) * (n + pat->minj)
    // We want ~84*84 = 7056 max, but we set m and n such that bounds are safe
    // Since work_space is [84][84], ensure i < 84 and j < 84
    m = 73; // because 73 + 10 + 1 = 84
    n = 74; // because 74 + 10 = 84

    // Initialize work_space to avoid undefined behavior
    memset(work_space, 0, sizeof(work_space));

    // Initialize loop indices
    i = 0;
    j = 0;
}