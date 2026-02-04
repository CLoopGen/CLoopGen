#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;
typedef int32 s3wid_t;
typedef short int16;
typedef int16 s3frmid_t;
typedef unsigned short uint16;
typedef uint16 s3lmwid_t;

struct {
    s3lmwid_t lwid[2];
};

typedef union {
    struct {
        s3lmwid_t lwid[2];
    } lm3g;
} vh_lmstate_t;

typedef struct {
    s3wid_t wid;
    s3frmid_t sf;
    s3frmid_t ef;
    int32 ascr;
    int32 lscr;
    int32 score;
    int32 pred;
    int32 type;
    int32 valid;
    vh_lmstate_t lmstate;
} vithist_entry_t;

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
    int32 state;
    int32 vhid;
    vithist_entry_t *ve;
    glist_t children;
} vh_lms2vh_t;

typedef struct {
    vithist_entry_t **entry;
    int32 *frame_start;
    int32 n_entry;
    int32 n_frm;
    int32 bghist;
    int32 wbeam;
    int32 *bestscore;
    int32 *bestvh;
    vh_lms2vh_t **lms2vh_root;
    glist_t lwidlist;
} vithist_t;

typedef struct {
    s3wid_t wid;
    int32 fef;
    int32 lef;
    int32 seqid;
    glist_t velist;
} dagnode_t;

vithist_t *vh;
glist_t *sfwid;
gnode_t *gn;
dagnode_t *dn;
int32 f;
int32 i;

static const int NUM_FRAMES = 50000;
static const int AVG_NODES_PER_FRAME = 5;
static const int TOTAL_NODES = NUM_FRAMES * AVG_NODES_PER_FRAME;

static vithist_t vh_instance;
static glist_t sfwid_array[50000];
static gnode_t* node_pool;
static dagnode_t* dnode_pool;

void init_vars() {
    i = 0;

    node_pool = (gnode_t*)calloc(TOTAL_NODES, sizeof(gnode_t));
    dnode_pool = (dagnode_t*)calloc(TOTAL_NODES, sizeof(dagnode_t));

    if (!node_pool || !dnode_pool) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    int node_idx = 0;
    for (int frame = 0; frame < NUM_FRAMES; ++frame) {
        glist_t head = NULL;
        int count = AVG_NODES_PER_FRAME + (rand() % 3) - 1;
        count = (count < 1) ? 1 : count;

        for (int j = 0; j < count; ++j) {
            if (node_idx >= TOTAL_NODES) break;

            gnode_t* new_node = &node_pool[node_idx];
            dagnode_t* dn = &dnode_pool[node_idx];

            dn->wid = rand() % 1000;
            dn->fef = rand() % 100;
            dn->lef = dn->fef + (rand() % 10);
            dn->seqid = -2;
            dn->velist = NULL;

            new_node->data.ptr = dn;
            new_node->next = head;
            head = new_node;
            node_idx++;
        }
        sfwid_array[frame] = head;
    }

    vh_instance.n_frm = NUM_FRAMES - 1;
    vh_instance.entry = NULL;
    vh_instance.frame_start = NULL;
    vh_instance.n_entry = 0;
    vh_instance.bghist = 0;
    vh_instance.wbeam = 0;
    vh_instance.bestscore = NULL;
    vh_instance.bestvh = NULL;
    vh_instance.lms2vh_root = NULL;
    vh_instance.lwidlist = NULL;

    vh = &vh_instance;
    sfwid = sfwid_array;
    gn = NULL;
    dn = NULL;
    f = 0;
}