#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int MagickStatusType;

typedef struct PCDTable {
    unsigned int length;
    unsigned int sequence;
    MagickStatusType mask;
    unsigned char key;
} PCDTable;

PCDTable *pcd_table[3];
ssize_t i;
size_t pcd_length[3];

void init_vars() {
    for (int idx = 0; idx < 3; idx++) {
        pcd_table[idx] = NULL;
        pcd_length[idx] = 0;
    }
}