#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short ***imgUV_org_frm;
int org_size_x_cr;
int org_size_y_cr;
int img_size_x_cr;
int x;
int y;

void init_vars() {
    org_size_y_cr = 512;
    org_size_x_cr = 512;
    img_size_x_cr = 1024;

    imgUV_org_frm = (unsigned short ***)calloc(2, sizeof(unsigned short **));
    for (int c = 0; c < 2; c++) {
        imgUV_org_frm[c] = (unsigned short **)calloc(org_size_y_cr, sizeof(unsigned short *));
        for (int i = 0; i < org_size_y_cr; i++) {
            imgUV_org_frm[c][i] = (unsigned short *)calloc(img_size_x_cr, sizeof(unsigned short));
            for (int j = 0; j < org_size_x_cr; j++) {
                imgUV_org_frm[c][i][j] = rand() & 0xFFFF;
            }
        }
    }
}