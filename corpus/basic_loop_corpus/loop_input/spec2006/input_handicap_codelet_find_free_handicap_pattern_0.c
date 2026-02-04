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

struct handicap_match {
    int value;
    int anchor;
    struct pattern *pattern;
    int ll;
};

#define NUMBER_OF_MATCHES 1000000

struct handicap_match handicap_matches[40];
int number_of_matches = 40;
int k;
int highest_value;

void init_vars() {
    for (int i = 0; i < 40; i++) {
        handicap_matches[i].value = (i * 29) % 1000;
        handicap_matches[i].anchor = i;
        handicap_matches[i].ll = i * 10;
        handicap_matches[i].pattern = NULL;
    }
    number_of_matches = 40;
    k = 0;
    highest_value = -1;
}