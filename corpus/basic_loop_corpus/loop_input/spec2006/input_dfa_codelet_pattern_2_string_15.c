#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct patval_b {
    int x;
    int y;
    int att;
};

char att2val[8] = {1, 2, 4, 8, 16, 32, 64, -128};
struct pattern *pat;
struct patval_b *elements;
int ci = 42;
int cj = 42;
char work_space[84][84];
int m = 42;
int n = 42;
int k;
char c;

void init_vars() {
    int patlen = 1000000;
    pat = (struct pattern*)malloc(sizeof(struct pattern));
    if (!pat) exit(1);

    pat->patlen = patlen;
    pat->mini = 0;
    pat->minj = 0;
    pat->maxi = 83;
    pat->maxj = 83;
    pat->height = 84;
    pat->width = 84;
    pat->move_offset = 0;
    pat->edge_constraints = 0;
    pat->class = 0;
    pat->value = 1.0f;
    pat->maxvalue = 2.0f;
    pat->minterritory = 0.5f;
    pat->maxterritory = 1.5f;
    pat->shape = 1.0f;
    pat->followup = 0.8f;
    pat->reverse_followup = 0.7f;
    pat->autohelper_flag = 0;
    pat->helper = NULL;
    pat->autohelper = NULL;
    pat->anchored_at_X = -1;
    pat->constraint_cost = 0.1f;

    for (int i = 0; i < 8; i++) {
        pat->and_mask[i] = 0xFF;
        pat->val_mask[i] = 0x55;
    }

    elements = (struct patval_b*)malloc(patlen * sizeof(struct patval_b));
    if (!elements) exit(1);

    for (int i = 0; i < patlen; i++) {
        elements[i].x = (i * 17) % 40;  
        elements[i].y = (i * 19) % 40;  
        elements[i].att = i % 8;
    }

    memset(work_space, 0, sizeof(work_space));
    m = 42;
    n = 42;
    ci = 42;
    cj = 42;
}