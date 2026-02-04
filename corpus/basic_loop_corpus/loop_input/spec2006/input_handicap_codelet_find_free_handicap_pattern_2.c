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

struct patval dummy_patval = {0, 0};
struct pattern dummy_pattern = {
    &dummy_patval,
    1, 0, "dummy",
    0, 0, 0, 0,
    1, 1, 0, 0,
    {0}, {0},
    0,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0, NULL, NULL,
    0, 0.0f
};

#define HANDICAP_MATCHES_SIZE 2000000

struct handicap_match handicap_matches[40] = {{0}};
int number_of_matches = 0;
int k = 0;
int r = 0;

void init_vars() {
    for (int i = 0; i < 40; i++) {
        handicap_matches[i].value = 1;
        handicap_matches[i].anchor = i;
        handicap_matches[i].pattern = &dummy_pattern;
        handicap_matches[i].ll = i * 2;
    }
    number_of_matches = 40;
    r = 20;
}