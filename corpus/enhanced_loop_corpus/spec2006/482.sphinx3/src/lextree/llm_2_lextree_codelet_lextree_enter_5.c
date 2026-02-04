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
    // Variant 1: Consecutive array access with pointer arithmetic and loop unrolling (factor of 2)
    gnode_t *current = root;
    lextree_node_t **next_active_ptr = lextree->next_active;
    
    // Process nodes in pairs to enable consecutive memory access pattern
    while (current && current->next) {
        lextree_node_t *ln1 = (lextree_node_t *)current->data.ptr;
        lextree_node_t *ln2 = (lextree_node_t *)current->next->data.ptr;
        
        hmm_t *hmm1 = &(ln1->hmm);
        hmm_t *hmm2 = &(ln2->hmm);
        
        int32 scr1 = inscore + ln1->prob;
        int32 scr2 = inscore + ln2->prob;
        
        if (scr1 >= thresh) {
            if (hmm1->in.score < scr1) {
                hmm1->in.score = scr1;
                hmm1->in.history = inhist;
                if (ln1->frame != nf) {
                    ln1->frame = nf;
                    *next_active_ptr++ = ln1;
                }
            }
        }
        
        if (scr2 >= thresh) {
            if (hmm2->in.score < scr2) {
                hmm2->in.score = scr2;
                hmm2->in.history = inhist;
                if (ln2->frame != nf) {
                    ln2->frame = nf;
                    *next_active_ptr++ = ln2;
                }
            }
        }
        
        current = current->next->next;
    }
    
    // Handle remaining node if list has odd length
    if (current) {
        ln = (lextree_node_t *)current->data.ptr;
        hmm = &(ln->hmm);
        scr = inscore + ln->prob;
        if ((scr >= thresh) && (hmm->in.score < scr)) {
            hmm->in.score = scr;
            hmm->in.history = inhist;
            if (ln->frame != nf) {
                ln->frame = nf;
                *next_active_ptr++ = ln;
            }
        }
    }
    
    // Update n with total count using pointer arithmetic
    n = next_active_ptr - lextree->next_active;
}
