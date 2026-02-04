#include <stdio.h>

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

extern lextree_t *lextree;
extern gnode_t *gn;
extern gnode_t *gn2;
extern lextree_node_t *ln;
extern lextree_node_t *ln2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (gn = lextree->root; gn; gn = ((gn)->next)) {
        ln = (lextree_node_t *)((gn)->data.ptr);
        if (ln->prob < 0) continue;
        for (gn2 = ln->children; gn2; gn2 = ((gn2)->next)) {
            ln2 = (lextree_node_t *)((gn2)->data.ptr);
            if (ln2->composite >= 0) {
                ln2->composite = -1;
                ln2->ssid = (ln->wid + ln2->wid) % 3;
            } else {
                ln2->ssid += 2;
            }
            ln2->frame++;
            if (ln2->frame > 100) {
                ln2->frame = 0;
            }
        }
    }
}
