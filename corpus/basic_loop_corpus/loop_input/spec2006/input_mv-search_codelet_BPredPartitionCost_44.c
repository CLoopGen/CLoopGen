#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *mvbits;
int blocktype = 1;
int block8x8 = 0;
short fw_ref = 0;
short bw_ref = 0;
int bx0[5][4] = {{0}};
int by0[5][4] = {{0}};
int v;
int h;
int mvd_bits = 0;
int parttype = 0;
int step_h0 = 16;
int step_v0 = 16;
int step_h = 1;
int step_v = 1;

short ******all_mv;
short ******p_mv;

void init_vars() {
    mvbits = (int*)calloc(1024, sizeof(int));
    for (int i = 0; i < 1024; ++i) {
        mvbits[i] = i & 0xF;
    }

    bx0[0][0] = 0;
    by0[0][0] = 0;
    parttype = 0;
    block8x8 = 0;
    step_h0 = 16;
    step_v0 = 16;
    step_h = 1;
    step_v = 1;
    blocktype = 1;
    fw_ref = 0;
    bw_ref = 0;

    int size_h = 32;
    int size_v = 32;

    all_mv = (short******)calloc(size_h, sizeof(short*****));
    p_mv = (short******)calloc(size_h, sizeof(short*****));

    for (h = 0; h < size_h; ++h) {
        all_mv[h] = (short*****)calloc(size_v, sizeof(short****));
        p_mv[h] = (short*****)calloc(size_v, sizeof(short****));
        for (v = 0; v < size_v; ++v) {
            all_mv[h][v] = (short****)calloc(2, sizeof(short***));
            p_mv[h][v] = (short****)calloc(2, sizeof(short***));
            for (int dir = 0; dir < 2; ++dir) {
                all_mv[h][v][dir] = (short***)calloc(2, sizeof(short**));
                p_mv[h][v][dir] = (short***)calloc(2, sizeof(short**));
                for (int ref = 0; ref < 2; ++ref) {
                    all_mv[h][v][dir][ref] = (short**)calloc(2, sizeof(short*));
                    p_mv[h][v][dir][ref] = (short**)calloc(2, sizeof(short*));
                    for (int bt = 0; bt < 2; ++bt) {
                        all_mv[h][v][dir][ref][bt] = (short*)calloc(2, sizeof(short));
                        p_mv[h][v][dir][ref][bt] = (short*)calloc(2, sizeof(short));
                        all_mv[h][v][dir][ref][bt][0] = 100;
                        all_mv[h][v][dir][ref][bt][1] = 100;
                        p_mv[h][v][dir][ref][bt][0] = 90;
                        p_mv[h][v][dir][ref][bt][1] = 90;
                    }
                }
            }
        }
    }

    bx0[parttype][block8x8] = 0;
    by0[parttype][block8x8] = 0;
}