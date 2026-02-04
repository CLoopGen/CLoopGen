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

int transformation[1369][8];
int anchor;
struct pattern *pattern;
int ll;
int defense_pos;
int k;

void init_vars() {
    anchor = 42;
    ll = 0;
    defense_pos = 0;
    k = 0;

    static struct patval patn_data[1000000];
    for (int i = 0; i < 1000000; i++) {
        patn_data[i].offset = i % 1369;
        patn_data[i].att = (i % 10 == 7) ? 7 : (i % 8);
    }

    static struct pattern pattern_instance;
    pattern_instance.patn = patn_data;
    pattern_instance.patlen = 1000000;
    pattern_instance.trfno = 0;
    pattern_instance.name = "test_pattern";
    pattern_instance.mini = 0;
    pattern_instance.minj = 0;
    pattern_instance.maxi = 19;
    pattern_instance.maxj = 19;
    pattern_instance.height = 19;
    pattern_instance.width = 19;
    pattern_instance.edge_constraints = 0;
    pattern_instance.move_offset = 0;
    for (int i = 0; i < 8; i++) {
        pattern_instance.and_mask[i] = 0xFFFFFFFF;
        pattern_instance.val_mask[i] = 0;
    }
    pattern_instance.class = 0;
    pattern_instance.value = 0.0f;
    pattern_instance.maxvalue = 1.0f;
    pattern_instance.minterritory = 0.0f;
    pattern_instance.maxterritory = 1.0f;
    pattern_instance.shape = 0.5f;
    pattern_instance.followup = 0.3f;
    pattern_instance.reverse_followup = 0.2f;
    pattern_instance.autohelper_flag = 0;
    pattern_instance.helper = NULL;
    pattern_instance.autohelper = NULL;
    pattern_instance.anchored_at_X = -1;
    pattern_instance.constraint_cost = 0.0f;

    pattern = &pattern_instance;

    for (int i = 0; i < 1369; i++) {
        for (int j = 0; j < 8; j++) {
            transformation[i][j] = (i + j) * 17;
        }
    }
}