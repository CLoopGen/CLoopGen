#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

int board_size;
struct pattern *pattern;

#define PATTERN_COUNT (1 << 20)

static struct patval *patval_array;
static struct pattern pattern_array[PATTERN_COUNT];

void init_vars() {
    board_size = 19;

    patval_array = calloc(PATTERN_COUNT, sizeof(struct patval));
    if (!patval_array) exit(1);

    for (int i = 0; i < PATTERN_COUNT; ++i) {
        pattern_array[i].patn = &patval_array[i];
        pattern_array[i].patlen = 1;
        pattern_array[i].trfno = 0;
        pattern_array[i].name = "test_pattern";
        pattern_array[i].mini = rand() % 10;
        pattern_array[i].minj = rand() % 10;
        pattern_array[i].height = rand() % 10 + 1;
        pattern_array[i].width = rand() % 10 + 1;
        pattern_array[i].edge_constraints = rand() & 15;
        pattern_array[i].maxi = pattern_array[i].mini + pattern_array[i].height;
        pattern_array[i].maxj = pattern_array[i].minj + pattern_array[i].width;
        pattern_array[i].move_offset = 0;
        for (int j = 0; j < 8; ++j) {
            pattern_array[i].and_mask[j] = 0xFFFFFFFFu;
            pattern_array[i].val_mask[j] = 0x00000000u;
        }
        pattern_array[i].class = 0;
        pattern_array[i].value = 0.0f;
        pattern_array[i].maxvalue = 1.0f;
        pattern_array[i].minterritory = 0.0f;
        pattern_array[i].maxterritory = 1.0f;
        pattern_array[i].shape = 0.5f;
        pattern_array[i].followup = 0.3f;
        pattern_array[i].reverse_followup = 0.3f;
        pattern_array[i].autohelper_flag = 0;
        pattern_array[i].helper = NULL;
        pattern_array[i].autohelper = NULL;
        pattern_array[i].anchored_at_X = -1;
        pattern_array[i].constraint_cost = 0.1f;
    }

    pattern = pattern_array;
}