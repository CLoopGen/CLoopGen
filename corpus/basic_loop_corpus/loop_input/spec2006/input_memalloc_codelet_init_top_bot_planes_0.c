#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short **imgFrame;
int rows;
unsigned short ***imgTopField;
unsigned short ***imgBotField;
int i;

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(unsigned short)
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

void init_vars() {
    rows = (TOTAL_ELEMENTS / 2) & ~1; 

    imgFrame = (unsigned short **)calloc(rows, sizeof(unsigned short *));
    if (!imgFrame) exit(1);

    for (int r = 0; r < rows; r++) {
        imgFrame[r] = (unsigned short *)calloc(1, ELEMENT_SIZE);
        if (!imgFrame[r]) exit(1);
    }

    imgTopField = (unsigned short ***)malloc(sizeof(unsigned short **));
    if (!imgTopField) exit(1);
    *imgTopField = (unsigned short **)calloc(rows / 2, sizeof(unsigned short *));
    if (!(*imgTopField)) exit(1);

    imgBotField = (unsigned short ***)malloc(sizeof(unsigned short **));
    if (!imgBotField) exit(1);
    *imgBotField = (unsigned short **)calloc(rows / 2, sizeof(unsigned short *));
    if (!(*imgBotField)) exit(1);
}