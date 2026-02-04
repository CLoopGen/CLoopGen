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

struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};

struct pattern *pattern;
int move;
struct owl_move_data *moves;
int k;

void init_vars() {
    pattern = (struct pattern *)malloc(sizeof(struct pattern));
    if (!pattern) return;

    pattern->patn = NULL;
    pattern->patlen = 0;
    pattern->trfno = 0;
    pattern->name = "test_pattern";
    pattern->mini = 0;
    pattern->minj = 0;
    pattern->maxi = 0;
    pattern->maxj = 0;
    pattern->height = 1;
    pattern->width = 1;
    pattern->edge_constraints = 0;
    pattern->move_offset = 0;
    for (int i = 0; i < 8; i++) {
        pattern->and_mask[i] = 0xFFFFFFFF;
        pattern->val_mask[i] = 0x00000000;
    }
    pattern->class = 0;
    pattern->value = 50.0f;
    pattern->maxvalue = 100.0f;
    pattern->minterritory = 10.0f;
    pattern->maxterritory = 20.0f;
    pattern->shape = 15.0f;
    pattern->followup = 5.0f;
    pattern->reverse_followup = 3.0f;
    pattern->autohelper_flag = 0;
    pattern->helper = NULL;
    pattern->autohelper = NULL;
    pattern->anchored_at_X = -1;
    pattern->constraint_cost = 1.0f;

    move = 42;

    moves = (struct owl_move_data *)calloc(3, sizeof(struct owl_move_data));
    if (!moves) {
        free(pattern);
        return;
    }

    moves[0].pos = 10;
    moves[0].value = 40;
    moves[0].name = "moveA";
    moves[0].same_dragon = 1;
    moves[0].escape = 1;
    moves[0].defense_pos = -1;

    moves[1].pos = move;
    moves[1].value = 60;
    moves[1].name = "moveB";
    moves[1].same_dragon = 0;
    moves[1].escape = 2;
    moves[1].defense_pos = 1;

    moves[2].pos = 20;
    moves[2].value = -1;
    moves[2].name = "moveC";
    moves[2].same_dragon = 0;
    moves[2].escape = 3;
    moves[2].defense_pos = 2;
}