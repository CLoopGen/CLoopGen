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
gnode_t *gn;
gnode_t *gn2;
lextree_node_t *ln;
lextree_node_t *ln2;

void init_vars() {
    const int num_nodes = 800;
    const int avg_children = 80;

    lextree = (lextree_t*)calloc(1, sizeof(lextree_t));
    lextree->root = NULL;
    lextree->n_node = num_nodes;
    lextree->n_lc = 0;
    lextree->lcroot = NULL;
    lextree->active = NULL;
    lextree->next_active = NULL;
    lextree->n_active = 0;
    lextree->n_next_active = 0;
    lextree->best = 0;
    lextree->wbest = 0;

    gnode_t **node_tail = &(lextree->root);
    lextree_node_t **nodes = (lextree_node_t**)calloc(num_nodes, sizeof(lextree_node_t*));

    for (int i = 0; i < num_nodes; ++i) {
        nodes[i] = (lextree_node_t*)calloc(1, sizeof(lextree_node_t));
        nodes[i]->wid = i;
        nodes[i]->prob = rand();
        nodes[i]->ssid = 1;
        nodes[i]->ci = 0;
        nodes[i]->composite = (i % 2 == 0) ? -1 : -2;
        nodes[i]->frame = 0;
        nodes[i]->hmm.bestscore = 0;
        nodes[i]->hmm.tp = NULL;
        nodes[i]->hmm.state = NULL;
        nodes[i]->ssid_lc = NULL;
        nodes[i]->children = NULL;

        gnode_t *child_root = NULL;
        gnode_t **child_tail = &child_root;
        int num_children = avg_children;
        for (int j = 0; j < num_children; ++j) {
            gnode_t *child_node = (gnode_t*)calloc(1, sizeof(gnode_t));
            lextree_node_t *child_data = (lextree_node_t*)calloc(1, sizeof(lextree_node_t));
            child_data->composite = (j % 2 == 0) ? (int8)0 : -1;
            child_data->ssid = 1;
            child_node->data.ptr = child_data;
            child_node->next = NULL;
            *child_tail = child_node;
            child_tail = &(child_node->next);
        }
        nodes[i]->children = child_root;
        
        gnode_t *new_node = (gnode_t*)calloc(1, sizeof(gnode_t));
        new_node->data.ptr = nodes[i];
        new_node->next = NULL;
        *node_tail = new_node;
        node_tail = &(new_node->next);
    }
}