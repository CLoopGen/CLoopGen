#include <stdio.h>
#include <inttypes.h>
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
int32 *ssid;
int32 *comssid;
lextree_node_t **list;
lextree_node_t *ln;
int32 i;

void init_vars() {
    const int32 total_nodes = 20000000; // ~20M nodes to target ~0.01 sec runtime

    lextree = (lextree_t*)calloc(1, sizeof(lextree_t));
    ssid = (int32*)calloc(total_nodes, sizeof(int32));
    comssid = (int32*)calloc(total_nodes, sizeof(int32));
    list = (lextree_node_t**)malloc(total_nodes * sizeof(lextree_node_t*));

    for (int32 idx = 0; idx < total_nodes; idx++) {
        lextree_node_t* node = (lextree_node_t*)malloc(sizeof(lextree_node_t));
        node->composite = (idx % 2);
        node->ssid = idx % 1000000;
        list[idx] = node;
    }

    lextree->n_active = total_nodes;
}