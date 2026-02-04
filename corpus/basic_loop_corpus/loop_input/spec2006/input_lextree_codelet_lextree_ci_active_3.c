#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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

typedef uint32 *bitvec_t;

lextree_t *lextree;
bitvec_t ci_active;
lextree_node_t **list;
lextree_node_t *ln;
int32 i;

void init_vars() {
    const int total_data_size = 16 * 1024 * 1024;
    const int n_active = total_data_size / sizeof(lextree_node_t);
    
    lextree = (lextree_t*)calloc(1, sizeof(lextree_t));
    if (!lextree) exit(1);
    
    lextree->n_active = n_active;
    
    list = (lextree_node_t**)calloc(n_active, sizeof(lextree_node_t*));
    if (!list) exit(1);
    
    for (int idx = 0; idx < n_active; idx++) {
        list[idx] = (lextree_node_t*)calloc(1, sizeof(lextree_node_t));
        if (!list[idx]) exit(1);
        list[idx]->ci = idx % 256;
    }
    
    int num_words = 256;
    int vec_size = (num_words + 31) / 32;
    ci_active = (uint32*)calloc(vec_size, sizeof(uint32));
    if (!ci_active) exit(1);
}