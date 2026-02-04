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
extern int32 *ssid;
extern int32 *comssid;
extern lextree_node_t **list;
extern lextree_node_t *ln;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the original loop into two levels.
    // The outer loop runs in chunks, and the inner loop processes elements within each chunk.
    int chunk_size = 16;
    int num_chunks = (lextree->n_active + chunk_size - 1) / chunk_size;

    for (int c = 0; c < num_chunks; c++) {
        int start = c * chunk_size;
        int end = (start + chunk_size < lextree->n_active) ? (start + chunk_size) : lextree->n_active;

        for (int i = start; i < end; i++) {
            ln = list[i];
            if (ln->composite)
                comssid[ln->ssid] = 1;
            else
                ssid[ln->ssid] = 1;
        }
    }
}
