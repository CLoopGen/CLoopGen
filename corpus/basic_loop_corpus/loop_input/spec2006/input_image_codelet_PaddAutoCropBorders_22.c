#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short **imgY_org_frm;
int org_size_y;
int img_size_x;
int img_size_y;
int x;
int y;

void init_vars() {
    img_size_x = 1024;
    img_size_y = 65536;
    org_size_y = 32768;

    imgY_org_frm = (unsigned short**)calloc(img_size_y, sizeof(unsigned short*));
    for (int i = 0; i < img_size_y; i++) {
        imgY_org_frm[i] = (unsigned short*)calloc(img_size_x, sizeof(unsigned short));
    }

    for (int i = 0; i < org_size_y; i++) {
        for (int j = 0; j < img_size_x; j++) {
            imgY_org_frm[i][j] = (unsigned short)(i + j);
        }
    }

    for (int i = org_size_y; i < img_size_y; i++) {
        for (int j = 0; j < img_size_x; j++) {
            imgY_org_frm[i][j] = 0;
        }
    }

    x = 0;
    y = 0;
}