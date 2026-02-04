#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

s3wid_t *wid;
vithist_entry_t *ve;
int32 i;

static const size_t DATA_SIZE = 64 * 1024 * 1024 / sizeof(s3wid_t); // ~64MB of data

void init_vars() {
    // Allocate and initialize wid array
    wid = (s3wid_t*)aligned_alloc(64, DATA_SIZE * sizeof(s3wid_t));
    for (size_t idx = 0; idx < DATA_SIZE - 1; ++idx) {
        wid[idx] = idx + 1;  // Ensure positive values
    }
    wid[DATA_SIZE - 1] = -1; // Terminate with -1 to prevent infinite loop

    // Allocate and initialize ve
    ve = (vithist_entry_t*)aligned_alloc(64, sizeof(vithist_entry_t));
    ve->wid = DATA_SIZE - 2; // Set target value that will be found before -1
    ve->sf = 0;
    ve->ef = 0;
    ve->ascr = 0;
    ve->lscr = 0;
    ve->score = 0;
    ve->pred = 0;
    ve->type = 0;
    ve->valid = 1;
    ve->lmstate.lm3g.lwid[0] = 0;
    ve->lmstate.lm3g.lwid[1] = 0;
}