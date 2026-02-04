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

#define NUMBER_OF_MATCHES 100000

struct patval global_patvals[NUMBER_OF_MATCHES];
struct pattern global_patterns[NUMBER_OF_MATCHES];
struct handicap_match handicap_matches[40];
int number_of_matches;
int r;
int k;
int least_value;

void init_vars() {
    number_of_matches = 40;
    r = 0;
    k = 0;
    least_value = 1000000;

    for (int i = 0; i < 40; i++) {
        handicap_matches[i].value = 1000000 - i * 25000;
        handicap_matches[i].anchor = i;
        handicap_matches[i].ll = i * 10;
        
        global_patterns[i].patn = &global_patvals[i];
        global_patterns[i].patlen = 10;
        global_patterns[i].trfno = i % 8;
        global_patterns[i].name = "test_pattern";
        global_patterns[i].mini = 0;
        global_patterns[i].minj = 0;
        global_patterns[i].maxi = 5;
        global_patterns[i].maxj = 5;
        global_patterns[i].height = 6;
        global_patterns[i].width = 6;
        global_patterns[i].edge_constraints = 0;
        global_patterns[i].move_offset = 0;
        for (int j = 0; j < 8; j++) {
            global_patterns[i].and_mask[j] = 0xFF;
            global_patterns[i].val_mask[j] = 0x55 + j;
        }
        global_patterns[i].class = 1;
        global_patterns[i].value = 1.0f;
        global_patterns[i].maxvalue = 2.0f;
        global_patterns[i].minterritory = 0.5f;
        global_patterns[i].maxterritory = 1.5f;
        global_patterns[i].shape = 1.0f;
        global_patterns[i].followup = 0.8f;
        global_patterns[i].reverse_followup = 0.7f;
        global_patterns[i].autohelper_flag = 0;
        global_patterns[i].helper = NULL;
        global_patterns[i].autohelper = NULL;
        global_patterns[i].anchored_at_X = -1;
        global_patterns[i].constraint_cost = 0.1f;

        handicap_matches[i].pattern = &global_patterns[i];

        global_patvals[i].offset = i * 4;
        global_patvals[i].att = i % 3;
    }

    // Ensure the loop runs about 0.01 seconds by making it do ~40 iterations
    // Our data size is fixed at 40 matches as per the array size
}