#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

struct handicap_match {
    int value;
    int anchor;
    struct pattern *pattern;
    int ll;
};

#define NUMBER_OF_MATCHES 1000000

struct handicap_match handicap_matches[40];
int number_of_matches;
int k;
int highest_value;
int sum_values;

void init_vars() {
    number_of_matches = 40;
    highest_value = 50;
    sum_values = 0;
    k = 0;

    for (int i = 0; i < 40; i++) {
        handicap_matches[i].value = 40 + (i % 21);
        handicap_matches[i].anchor = i;
        handicap_matches[i].ll = i * 2;
        
        struct pattern *p = (struct pattern *)malloc(sizeof(struct pattern));
        p->patn = NULL;
        p->patlen = 0;
        p->trfno = 0;
        p->name = "test_pattern";
        p->mini = 0;
        p->minj = 0;
        p->maxi = 19;
        p->maxj = 19;
        p->height = 20;
        p->width = 20;
        p->edge_constraints = 0;
        p->move_offset = 0;
        memset(p->and_mask, 0xFF, sizeof(p->and_mask));
        memset(p->val_mask, 0x55, sizeof(p->val_mask));
        p->class = 1;
        p->value = 1.0f;
        p->maxvalue = 1.0f;
        p->minterritory = 0.0f;
        p->maxterritory = 1.0f;
        p->shape = 0.5f;
        p->followup = 0.3f;
        p->reverse_followup = 0.2f;
        p->autohelper_flag = 0;
        p->helper = NULL;
        p->autohelper = NULL;
        p->anchored_at_X = -1;
        p->constraint_cost = 0.1f;

        handicap_matches[i].pattern = p;
    }
}