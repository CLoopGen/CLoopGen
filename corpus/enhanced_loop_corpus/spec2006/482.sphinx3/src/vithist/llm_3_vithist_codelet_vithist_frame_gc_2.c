#include <stdio.h>

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

extern vithist_t *vh;
extern vithist_entry_t *ve;
extern vithist_entry_t *tve;
extern int32 se;
extern int32 fe;
extern int32 te;
extern int32 bs;
extern int32 bv;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access elements with a fixed stride (e.g., every 2nd valid entry) to simulate non-unit stride traversal.
    // This variant precomputes indices into a temporary list (simulated via simple modulo-based selection)
    // to create a strided access pattern across frames.

    const int32 STRIDE = 2; // Access every second index in logical order
    int32 count = 0;
    int32 total_elements = fe - se + 1;
    int32 local_bs = bs;
    int32 local_bv = bv;
    int32 local_te = te;

    // Simulate indirect indexing with stride using direct computation
    for (int32 step = 0; step < total_elements; step += STRIDE) {
        int32 idx = se + step;
        ve = vh->entry[(idx >> 14)] + (idx & 16383);

        if (ve->valid) {
            tve = vh->entry[(te >> 14)] + (te & 16383);
            if (idx != te) {
                *tve = *ve;
            }
            if (ve->score > local_bs) {
                local_bs = ve->score;
                local_bv = local_te;
            }
            local_te++;
        }
    }

    // Update globals
    te = local_te;
    bs = local_bs;
    bv = local_bv;
}
