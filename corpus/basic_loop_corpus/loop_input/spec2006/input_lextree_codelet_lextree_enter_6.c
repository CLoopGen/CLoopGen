#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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
s3cipid_t lc = 42;
int32 i;

void init_vars() {
    const int target_time_ns = 10000000; // ~10ms in nanoseconds
    const long long iterations_per_ns = 1; // Approximate assumption for modern CPU
    int n_lc_val = (target_time_ns * iterations_per_ns) / 1;

    if (n_lc_val < 1000) n_lc_val = 1000;
    if (n_lc_val > 1000000) n_lc_val = 1000000;

    lextree_lcroot_t *lcroots = (lextree_lcroot_t *)calloc(n_lc_val, sizeof(lextree_lcroot_t));
    for (int j = 0; j < n_lc_val - 1; ++j) {
        lcroots[j].lc = j + 1;
    }
    lcroots[n_lc_val - 1].lc = lc;

    lextree = (lextree_t *)malloc(sizeof(lextree_t));
    lextree->lcroot = lcroots;
    lextree->n_lc = n_lc_val;
    lextree->n_node = 0;
    lextree->active = NULL;
    lextree->next_active = NULL;
    lextree->n_active = 0;
    lextree->n_next_active = 0;
    lextree->best = 0;
    lextree->wbest = 0;
    lextree->type = 0;
    lextree->root = NULL;
}