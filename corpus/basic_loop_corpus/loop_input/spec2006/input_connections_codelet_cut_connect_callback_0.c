#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};

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

int transformation[1369][8];
struct dragon_data dragon[400];
int anchor;
struct pattern *pattern;
int ll;
int k;
int first_dragon;
int second_dragon;

void init_vars() {
    anchor = 100;
    ll = 0;
    k = 0;
    first_dragon = 0;
    second_dragon = 0;

    for (int i = 0; i < 1369; ++i) {
        for (int j = 0; j < 8; ++j) {
            transformation[i][j] = (i * j) % 500;
        }
    }

    for (int i = 0; i < 400; ++i) {
        dragon[i].color = i % 3;
        dragon[i].id = i;
        dragon[i].origin = (i + 1) * 3;
        dragon[i].size = (i * 7) % 100;
        dragon[i].effective_size = (float)(i % 50);
        dragon[i].crude_status = i % 4;
        dragon[i].owl_threat_status = i % 2;
        dragon[i].owl_status = i % 3;
        dragon[i].owl_attack_point = i % 10;
        dragon[i].owl_attack_code = i % 5;
        dragon[i].owl_attack_certain = i % 2;
        dragon[i].owl_second_attack_point = i % 10;
        dragon[i].owl_defense_point = i % 10;
        dragon[i].owl_defense_code = i % 5;
        dragon[i].owl_defense_certain = i % 2;
        dragon[i].owl_second_defense_point = i % 10;
        dragon[i].status = i % 4;
        dragon[i].owl_attack_kworm = i % 2;
        dragon[i].owl_defense_kworm = i % 2;
    }

    struct patval *patn = (struct patval *)malloc(200 * sizeof(struct patval));
    for (int i = 0; i < 200; ++i) {
        patn[i].offset = i % 1369;
        patn[i].att = (i % 3) ? 2 : 0;
    }

    pattern = (struct pattern *)malloc(sizeof(struct pattern));
    pattern->patn = patn;
    pattern->patlen = 200;
    pattern->trfno = 0;
    pattern->name = "test_pattern";
    pattern->mini = 0;
    pattern->minj = 0;
    pattern->maxi = 19;
    pattern->maxj = 19;
    pattern->height = 20;
    pattern->width = 20;
    pattern->edge_constraints = 0;
    pattern->move_offset = 0;
    for (int i = 0; i < 8; ++i) {
        pattern->and_mask[i] = 0xFFFFFFFF;
        pattern->val_mask[i] = 0xAAAAAAAA;
    }
    pattern->class = 1;
    pattern->value = 1.0f;
    pattern->maxvalue = 2.0f;
    pattern->minterritory = 0.5f;
    pattern->maxterritory = 1.5f;
    pattern->shape = 1.2f;
    pattern->followup = 0.8f;
    pattern->reverse_followup = 0.7f;
    pattern->autohelper_flag = 0;
    pattern->helper = NULL;
    pattern->autohelper = NULL;
    pattern->anchored_at_X = -1;
    pattern->constraint_cost = 0.1f;
}