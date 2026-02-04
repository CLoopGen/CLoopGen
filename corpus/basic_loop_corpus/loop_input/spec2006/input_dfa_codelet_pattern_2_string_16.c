#include <stdio.h>
#include <stdlib.h>
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
int m = 0;
int i;
int j;

void init_vars() {
    pat = (struct pattern *)malloc(sizeof(struct pattern));
    if (!pat) return;

    pat->patn = NULL;
    pat->patlen = 0;
    pat->trfno = 0;
    pat->name = "test_pattern";
    pat->mini = 0;
    pat->minj = 0;
    pat->maxi = 20;
    pat->maxj = 20;
    pat->height = 21;
    pat->width = 21;
    pat->edge_constraints = 0;
    pat->move_offset = 0;
    for (int idx = 0; idx < 8; idx++) {
        pat->and_mask[idx] = 0xFFFFFFFF;
        pat->val_mask[idx] = 0x00000000;
    }
    pat->class = 0;
    pat->value = 0.0f;
    pat->maxvalue = 1.0f;
    pat->minterritory = 0.0f;
    pat->maxterritory = 1.0f;
    pat->shape = 0.5f;
    pat->followup = 0.3f;
    pat->reverse_followup = 0.2f;
    pat->autohelper_flag = 0;
    pat->helper = NULL;
    pat->autohelper = NULL;
    pat->anchored_at_X = 0;
    pat->constraint_cost = 0.1f;

    m = 1;

    for (int ii = 0; ii < 84; ii++)
        for (int jj = 0; jj < 84; jj++)
            work_space[ii][jj] = ' ';
}