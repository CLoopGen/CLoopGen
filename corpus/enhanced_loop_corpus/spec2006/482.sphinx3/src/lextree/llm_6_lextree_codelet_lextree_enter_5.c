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
extern int32 inscore;
extern int32 inhist;
extern int32 thresh;
extern glist_t root;
extern gnode_t *gn;
extern lextree_node_t *ln;
extern int32 nf;
extern int32 scr;
extern int32 n;
extern hmm_t *hmm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_thresh = thresh;
    int32 local_inscore = inscore;
    int32 local_inhist = inhist;
    int32 local_nf = nf;
    lextree_t *local_lextree = lextree;
    gnode_t *local_gn = root;
    int32 local_n = 0;

    for (; local_gn; local_gn = local_gn->next) {
        lextree_node_t *local_ln = (lextree_node_t *)(local_gn->data.ptr);
        hmm_t *local_hmm = &(local_ln->hmm);
        int32 computed_score = local_inscore + local_ln->prob;

        if (computed_score >= local_thresh) {
            if (local_hmm->in.score < computed_score) {
                local_hmm->in.score = computed_score;
                local_hmm->in.history = local_inhist;
            }
            if (local_ln->frame != local_nf) {
                local_ln->frame = local_nf;
                local_lextree->next_active[local_n++] = local_ln;
            }
        }
    }
    n = local_n;
}
