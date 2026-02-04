#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define SIZE_Y 128
#define SIZE_X 128
#define REF_FRAMES 5

static unsigned short inY_data[SIZE_Y][SIZE_X];
static unsigned short refY_data[REF_FRAMES][SIZE_Y][SIZE_X];

unsigned short **inY;
unsigned short ***refY;
int i;
int j;
int ref_inx;
int pos_y;
int pos_x;

void init_vars() {
    // Allocate and initialize inY as array of pointers to rows
    static unsigned short *inY_rows[SIZE_Y];
    for (int idx = 0; idx < SIZE_Y; idx++) {
        inY_rows[idx] = inY_data[idx];
    }
    inY = (unsigned short **)inY_rows;

    // Allocate memory for refY: array of pointers to frame pointer arrays
    static unsigned short **refY_frames[REF_FRAMES];
    static unsigned short *refY_rows[REF_FRAMES][SIZE_Y];

    for (int f = 0; f < REF_FRAMES; f++) {
        for (int idx = 0; idx < SIZE_Y; idx++) {
            refY_rows[f][idx] = refY_data[f][idx];
        }
        refY_frames[f] = refY_rows[f];
    }
    refY = (unsigned short ***)refY_frames;

    // Initialize loop indices and positions
    i = 0;
    j = 0;
    ref_inx = 0;  // Choose first reference frame
    pos_y = 0;
    pos_x = 0;

    // Ensure data is accessed within bounds: pos_y+15 < SIZE_Y, pos_x+15 < SIZE_X
    // With current values (pos_y=0, pos_x=0), access goes up to index 15, which is safe
}