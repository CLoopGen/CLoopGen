#include <stdio.h>
#include <inttypes.h>
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

struct pattern *pattern;
int k;
int number_of_stones;

void init_vars() {
    const int data_size = 1 << 20; // ~1MB of input data: 2^20 elements
    struct patval *patn_data = (struct patval *)calloc(data_size, sizeof(struct patval));
    if (!patn_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < data_size; i++) {
        patn_data[i].offset = i;
        patn_data[i].att = (i % 16) == 7 ? 7 : (i % 8); 
    }

    pattern = (struct pattern *)malloc(sizeof(struct pattern));
    if (!pattern) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    pattern->patn = patn_data;
    pattern->patlen = data_size;
    pattern->trfno = 0;
    pattern->name = "test_pattern";
    pattern->mini = 0;
    pattern->minj = 0;
    pattern->maxi = 100;
    pattern->maxj = 100;
    pattern->height = 10;
    pattern->width = 10;
    pattern->edge_constraints = 0;
    pattern->move_offset = 0;
    for (int i = 0; i < 8; i++) {
        pattern->and_mask[i] = 0xFFFFFFFF;
        pattern->val_mask[i] = 0xAAAAAAAA;
    }
    pattern->class = 1;
    pattern->value = 1.0f;
    pattern->maxvalue = 2.0f;
    pattern->minterritory = 0.5f;
    pattern->maxterritory = 5.0f;
    pattern->shape = 1.2f;
    pattern->followup = 0.8f;
    pattern->reverse_followup = 0.6f;
    pattern->autohelper_flag = 0;
    pattern->helper = NULL;
    pattern->autohelper = NULL;
    pattern->anchored_at_X = -1;
    pattern->constraint_cost = 0.1f;

    k = 0;
    number_of_stones = 0;
}