#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **imgY_org_frm;
int org_size_x;
int org_size_y;
int img_size_x;
int x;
int y;

void init_vars() {
    org_size_x = 512;
    org_size_y = 512;
    img_size_x = 1024;

    imgY_org_frm = (unsigned short**)calloc(org_size_y, sizeof(unsigned short*));
    for (int i = 0; i < org_size_y; i++) {
        imgY_org_frm[i] = (unsigned short*)calloc(img_size_x, sizeof(unsigned short));
        for (int j = 0; j < org_size_x; j++) {
            imgY_org_frm[i][j] = (unsigned short)(j + i);
        }
        for (int j = org_size_x; j < img_size_x; j++) {
            imgY_org_frm[i][j] = 0;
        }
    }
}