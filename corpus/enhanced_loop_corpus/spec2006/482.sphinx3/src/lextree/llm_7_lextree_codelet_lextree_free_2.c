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
    // Variant introducing artificial loop-carried data dependency via accumulator
    // and reordering update operations to create WAR hazard scenario.

    int32 running_composite_count = 0;

    for (gn = lextree->root; gn; gn = gn->next) {
        ln = (lextree_node_t *)((gn)->data.ptr);
        
        // Introduce loop-carried dependency using scalar `running_composite_count`
        // that feeds into next iteration — creates RAW hazard.
        running_composite_count += (ln->composite == -1) ? 1 : 0;

        for (gn2 = ln->children; gn2; gn2 = gn2->next) {
            ln2 = (lextree_node_t *)((gn2)->data.ptr);

            // Artificially create WAR (Write-After-Read) hazard:
            // Read ssid first, then conditionally write composite earlier than before
            int8 temp_comp = ln2->composite;

            // Use value before overwrite to preserve correctness, but schedule writes early
            if (temp_comp >= 0) {
                // Write to ssid depends on previous composite state — introduces intra-node dependency
                ln2->composite = -1;  // Early write may interfere if another path reads it (WAR)
                ln2->ssid = 1 + running_composite_count; // Introduce external dependency
            } else {
                // Update ssid using accumulated state from prior iterations (loop-carried)
                ln2->ssid = ln2->ssid + 1 + (running_composite_count & 1);
            }
        }

        // Modify running state after processing children — maintains RAW chain
        running_composite_count = (running_composite_count + 1) & 0x7FFFFFFF;
    }
}
