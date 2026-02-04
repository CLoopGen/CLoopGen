#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;
typedef unsigned int uint32;
typedef float float32;
typedef double float64;

typedef union anytype_s {
    void *ptr;
    int32 int32;
    uint32 uint32;
    float32 float32;
    float64 float64;
} anytype_t;

typedef struct gnode_s {
    anytype_t data;
    struct gnode_s *next;
} gnode_t;

typedef gnode_t *glist_t;

typedef char int8;
typedef int8 s3cipid_t;

typedef struct {
    s3cipid_t lc;
    glist_t root;
} lextree_lcroot_t;

typedef struct {
    int32 score;
    int32 history;
} hmm_state_t;

typedef struct {
    hmm_state_t *state;
    hmm_state_t in;
    hmm_state_t out;
    int32 **tp;
    int32 bestscore;
} hmm_t;

typedef int32 s3pid_t;
typedef s3pid_t s3ssid_t;
typedef short int16;
typedef int16 s3frmid_t;

typedef struct {
    hmm_t hmm;
    glist_t children;
    int32 wid;
    int32 prob;
    int32 ssid;
    s3ssid_t *ssid_lc;
    s3cipid_t ci;
    int8 composite;
    s3frmid_t frame;
} lextree_node_t;

typedef struct {
    int32 type;
    glist_t root;
    lextree_lcroot_t *lcroot;
    int32 n_lc;
    int32 n_node;
    lextree_node_t **active;
    lextree_node_t **next_active;
    int32 n_active;
    int32 n_next_active;
    int32 best;
    int32 wbest;
} lextree_t;

lextree_t *lextree;
int32 inscore;
int32 inhist;
int32 thresh;
glist_t root;
gnode_t *gn;
lextree_node_t *ln;
int32 nf;
int32 scr;
int32 n;
hmm_t *hmm;

static gnode_t *node_pool = NULL;
static lextree_node_t *ln_pool = NULL;
static int32 **tp_array = NULL;
static s3ssid_t *ssid_array = NULL;
static lextree_node_t **active_array = NULL;
static lextree_node_t **next_active_array = NULL;
static lextree_lcroot_t *lcroot_array = NULL;

void init_vars() {
    const int num_nodes = 500000;

    node_pool = (gnode_t *)calloc(num_nodes, sizeof(gnode_t));
    ln_pool = (lextree_node_t *)calloc(num_nodes, sizeof(lextree_node_t));
    tp_array = (int32 **)calloc(num_nodes, sizeof(int32 *));
    ssid_array = (s3ssid_t *)calloc(num_nodes, sizeof(s3ssid_t));
    active_array = (lextree_node_t **)calloc(num_nodes, sizeof(lextree_node_t *));
    next_active_array = (lextree_node_t **)calloc(num_nodes, sizeof(lextree_node_t *));
    lcroot_array = (lextree_lcroot_t *)calloc(1, sizeof(lextree_lcroot_t));

    if (!node_pool || !ln_pool || !tp_array || !ssid_array || !active_array || 
        !next_active_array || !lcroot_array) {
        exit(1);
    }

    for (int i = 0; i < num_nodes; ++i) {
        tp_array[i] = (int32 *)calloc(4, sizeof(int32));
        if (!tp_array[i]) {
            exit(1);
        }
        tp_array[i][0] = i * 3;
        tp_array[i][1] = i * 5;
        tp_array[i][2] = i * 7;
        tp_array[i][3] = i * 9;

        ln_pool[i].hmm.state = NULL;
        ln_pool[i].hmm.in.score = -1000000;
        ln_pool[i].hmm.in.history = 0;
        ln_pool[i].hmm.out.score = -1000000;
        ln_pool[i].hmm.out.history = 0;
        ln_pool[i].hmm.tp = tp_array + i;
        ln_pool[i].hmm.bestscore = -1000000;
        ln_pool[i].children = NULL;
        ln_pool[i].wid = i;
        ln_pool[i].prob = (i % 100) - 50;
        ln_pool[i].ssid = i % 1000;
        ln_pool[i].ssid_lc = ssid_array + i;
        ln_pool[i].ci = i % 128;
        ln_pool[i].composite = (i % 2 == 0) ? 1 : 0;
        ln_pool[i].frame = -1;

        node_pool[i].data.ptr = &ln_pool[i];
        if (i < num_nodes - 1) {
            node_pool[i].next = &node_pool[i+1];
        } else {
            node_pool[i].next = NULL;
        }

        active_array[i] = &ln_pool[i];
        next_active_array[i] = NULL;
    }

    lextree = (lextree_t *)calloc(1, sizeof(lextree_t));
    if (!lextree) exit(1);

    lextree->type = 1;
    lextree->root = node_pool;
    lextree->lcroot = lcroot_array;
    lextree->n_lc = 1;
    lextree->n_node = num_nodes;
    lextree->active = active_array;
    lextree->next_active = next_active_array;
    lextree->n_active = num_nodes;
    lextree->n_next_active = 0;
    lextree->best = -1000000;
    lextree->wbest = -1;

    lcroot_array[0].lc = 0;
    lcroot_array[0].root = node_pool;

    root = node_pool;
    inscore = 100;
    inhist = 42;
    thresh = 50;
    nf = 10;
    n = 0;
}