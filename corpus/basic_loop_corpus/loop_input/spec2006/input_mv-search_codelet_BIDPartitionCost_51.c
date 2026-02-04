#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int *mvbits;
int blocktype = 1;
int block8x8 = 0;
short fw_ref = 0;
short bw_ref = 0;
int bx0[5][4];
int by0[5][4];
int v;
int h;
int mvd_bits;
int parttype = 0;
int step_h0;
int step_v0;
int step_h = 1;
int step_v = 1;

short ******all_mv;
short ******p_mv;

void init_vars() {
    mvbits = (int*)calloc(65536, sizeof(int));
    for (int i = 0; i < 65536; ++i) {
        mvbits[i] = i % 256;
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            bx0[i][j] = 0;
            by0[i][j] = 0;
        }
    }

    step_h0 = 32;
    step_v0 = 32;
    bx0[0][0] = 0;
    by0[0][0] = 0;

    all_mv = (short******)calloc(64, sizeof(short*****));
    p_mv = (short******)calloc(64, sizeof(short*****));

    for (int h_idx = 0; h_idx < 64; ++h_idx) {
        all_mv[h_idx] = (short*****)calloc(64, sizeof(short****));
        p_mv[h_idx] = (short*****)calloc(64, sizeof(short****));

        for (int v_idx = 0; v_idx < 64; ++v_idx) {
            all_mv[h_idx][v_idx] = (short****)calloc(2, sizeof(short***));
            p_mv[h_idx][v_idx] = (short****)calloc(2, sizeof(short***));

            for (int list = 0; list < 2; ++list) {
                int ref = (list == 0) ? fw_ref : bw_ref;
                ref = ref >= 0 ? ref : -ref;
                ref %= 4;

                all_mv[h_idx][v_idx][list] = (short***)calloc(4, sizeof(short**));
                p_mv[h_idx][v_idx][list] = (short***)calloc(4, sizeof(short**));

                for (int ref_idx = 0; ref_idx < 4; ++ref_idx) {
                    all_mv[h_idx][v_idx][list][ref_idx] = (short**)calloc(2, sizeof(short*));
                    p_mv[h_idx][v_idx][list][ref_idx] = (short**)calloc(2, sizeof(short*));

                    for (int bt = 0; bt < 2; ++bt) {
                        all_mv[h_idx][v_idx][list][ref_idx][bt] = (short*)calloc(2, sizeof(short));
                        p_mv[h_idx][v_idx][list][ref_idx][bt] = (short*)calloc(2, sizeof(short));

                        for (int comp = 0; comp < 2; ++comp) {
                            all_mv[h_idx][v_idx][list][ref_idx][bt][comp] = 100 + comp;
                            p_mv[h_idx][v_idx][list][ref_idx][bt][comp] = 99 + comp;
                        }
                    }
                }
            }
        }
    }

    blocktype = 1;
    parttype = 0;
    block8x8 = 0;
}