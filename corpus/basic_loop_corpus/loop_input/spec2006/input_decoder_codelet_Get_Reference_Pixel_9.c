#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define MAXOLD_X 1024
#define MAXOLD_Y 1024
#define DATA_SIZE (MAXOLD_X * MAXOLD_Y * sizeof(unsigned short))
#define ALLOC_SIZE (DATA_SIZE * sizeof(unsigned short))

static unsigned short *imY_data = NULL;
unsigned short **imY = NULL;
int y_pos = 512;
int x_pos = 512;
int x = 0;
int y = 0;
int maxold_x = MAXOLD_X - 1;
int maxold_y = MAXOLD_Y - 1;
int result = 0;
int pres_x = 0;
int pres_y = 0;
int tmp_res[6] = {0};
int COEF[6] = {1, 2, 3, 4, 5, 6};

void init_vars() {
    if (imY_data == NULL) {
        imY_data = (unsigned short *)calloc(MAXOLD_Y, MAXOLD_X * sizeof(unsigned short));
    }

    if (imY == NULL) {
        imY = (unsigned short **)calloc(MAXOLD_Y, sizeof(unsigned short*));
    }

    for (int i = 0; i < MAXOLD_Y; i++) {
        imY[i] = imY_data + i * MAXOLD_X;
    }

    for (int i = 0; i < MAXOLD_Y; i++) {
        for (int j = 0; j < MAXOLD_X; j++) {
            imY[i][j] = (unsigned short)((i + j) & 0xFF);
        }
    }

    x_pos = MAXOLD_X / 2;
    y_pos = MAXOLD_Y / 2;

    for (int i = 0; i < 6; i++) {
        COEF[i] = (i + 1) * 10;
        tmp_res[i] = 0;
    }
}