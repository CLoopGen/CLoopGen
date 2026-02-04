#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
int16_t *coef;
int linesize;
uint16_t *in_lines_cur[4];
int i;

static uint16_t *in_buffer0;
static uint16_t *in_buffer1;
static uint16_t *in_buffer2;
static uint16_t *in_buffer3;
static int32_t *work_buffer;

void init_vars() {
    linesize = 65536; 

    coef = (int16_t*)malloc(4 * sizeof(int16_t));
    coef[0] = 1;
    coef[1] = 2;
    coef[2] = 3;
    coef[3] = 4;

    in_buffer0 = (uint16_t*)malloc(linesize * sizeof(uint16_t));
    in_buffer1 = (uint16_t*)malloc(linesize * sizeof(uint16_t));
    in_buffer2 = (uint16_t*)malloc(linesize * sizeof(uint16_t));
    in_buffer3 = (uint16_t*)malloc(linesize * sizeof(uint16_t));
    work_buffer = (int32_t*)malloc(linesize * sizeof(int32_t));

    for (int j = 0; j < linesize; j++) {
        in_buffer0[j] = (uint16_t)(j & 0xFFFF);
        in_buffer1[j] = (uint16_t)((j + 100) & 0xFFFF);
        in_buffer2[j] = (uint16_t)((j + 200) & 0xFFFF);
        in_buffer3[j] = (uint16_t)((j + 300) & 0xFFFF);
        work_buffer[j] = 0;
    }

    in_lines_cur[0] = in_buffer0;
    in_lines_cur[1] = in_buffer1;
    in_lines_cur[2] = in_buffer2;
    in_lines_cur[3] = in_buffer3;
    work_line = work_buffer;
}