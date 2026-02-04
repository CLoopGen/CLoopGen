#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short ***imgUV_org_frm;
int org_size_y_cr;
int img_size_x_cr;
int img_size_y_cr;
int x;
int y;

void init_vars() {
    img_size_x_cr = 1024;
    img_size_y_cr = 512;
    org_size_y_cr = 256;

    imgUV_org_frm = (unsigned short ***)calloc(2, sizeof(unsigned short **));
    for (int c = 0; c < 2; c++) {
        imgUV_org_frm[c] = (unsigned short **)calloc(img_size_y_cr, sizeof(unsigned short *));
        for (int i = 0; i < img_size_y_cr; i++) {
            imgUV_org_frm[c][i] = (unsigned short *)calloc(img_size_x_cr, sizeof(unsigned short));
            for (int j = 0; j < img_size_x_cr; j++) {
                imgUV_org_frm[c][i][j] = (unsigned short)((i + j) & 0xFFFF);
            }
        }
    }
}