#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

typedef int32 s3wid_t;

typedef struct {
    s3wid_t wid;
    int32 fef;
    int32 lef;
    int32 seqid;
    glist_t velist;
} dagnode_t;

typedef struct {
    int32 id;
    int32 vhid;
    int32 sf;
    int32 ef;
    int32 ascr;
    int32 lscr;
    int32 type;
} hyp_t;

glist_t hyp = NULL;
glist_t *sfwid = NULL;
gnode_t *gn = NULL;
gnode_t *gn2 = NULL;
dagnode_t *dn = NULL;
hyp_t *h = NULL;

#define HYP_COUNT 20000
#define SF_PER_HYP 10
#define TOTAL_DAGNODES (HYP_COUNT * SF_PER_HYP)
#define MAX_SF_ID 500

void init_vars() {
    // Allocate and initialize hyp list
    gnode_t *prev_gn = NULL;
    for (int i = 0; i < HYP_COUNT; i++) {
        gnode_t *node = (gnode_t*)calloc(1, sizeof(gnode_t));
        hyp_t *hyp_data = (hyp_t*)calloc(1, sizeof(hyp_t));
        
        hyp_data->id = rand() % (MAX_SF_ID * 2);
        hyp_data->vhid = i;
        hyp_data->sf = rand() % MAX_SF_ID;
        hyp_data->ef = hyp_data->sf + (rand() % 5) + 1;
        hyp_data->ascr = rand();
        hyp_data->lscr = rand();
        hyp_data->type = rand() % 3;

        node->data.ptr = hyp_data;
        node->next = NULL;

        if (prev_gn) {
            prev_gn->next = node;
        } else {
            hyp = node;
        }
        prev_gn = node;
    }

    // Allocate sfwid array of lists
    sfwid = (glist_t*)calloc(MAX_SF_ID, sizeof(glist_t));

    // Allocate and distribute dagnodes across sfwid buckets
    for (int i = 0; i < TOTAL_DAGNODES; i++) {
        int sf_idx = i % MAX_SF_ID;
        gnode_t *node = (gnode_t*)calloc(1, sizeof(gnode_t));
        dagnode_t *dn_data = (dagnode_t*)calloc(1, sizeof(dagnode_t));
        
        dn_data->wid = rand() % (MAX_SF_ID * 2);
        dn_data->fef = i * 2;
        dn_data->lef = i * 2 + 1;
        dn_data->seqid = i + 1;
        dn_data->velist = NULL;

        node->data.ptr = dn_data;
        node->next = sfwid[sf_idx];
        sfwid[sf_idx] = node;
    }
}