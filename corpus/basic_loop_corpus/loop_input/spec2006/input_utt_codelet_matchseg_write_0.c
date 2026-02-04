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
gnode_t *gn = NULL;
hyp_t *h = NULL;
int32 ascr = 0;
int32 lscr = 0;

#define DATA_SIZE_MB 64
#define NUM_NODES (DATA_SIZE_MB * 1024 * 1024 / sizeof(hyp_t))

static gnode_t* node_pool = NULL;
static hyp_t* hyp_pool = NULL;

void init_vars() {
    hyp_pool = (hyp_t*)calloc(NUM_NODES, sizeof(hyp_t));
    if (!hyp_pool) exit(1);

    node_pool = (gnode_t*)calloc(NUM_NODES, sizeof(gnode_t));
    if (!node_pool) exit(1);

    for (int i = 0; i < NUM_NODES; i++) {
        hyp_pool[i].id = i;
        hyp_pool[i].vhid = i % 1000;
        hyp_pool[i].sf = i * 3;
        hyp_pool[i].ef = i * 7;
        hyp_pool[i].ascr = i * 5 + 1;
        hyp_pool[i].lscr = i * 11 + 13;
        hyp_pool[i].type = i % 5;

        node_pool[i].data.ptr = &hyp_pool[i];
        node_pool[i].next = (i == NUM_NODES - 1) ? NULL : &node_pool[i + 1];
    }

    hyp = &node_pool[0];
    gn = NULL;
    h = NULL;
    ascr = 0;
    lscr = 0;
}