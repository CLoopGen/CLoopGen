#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int *tbck;
int *matassign;
int first;

#define DATA_SIZE (1 << 20)  // Approximately 1MB of data for ~0.01 sec runtime

static int tbck_storage[DATA_SIZE];
static int matassign_storage[DATA_SIZE];

void init_vars() {
    // Initialize all storage arrays
    memset(tbck_storage, 0, sizeof(tbck_storage));
    memset(matassign_storage, 0, sizeof(matassign_storage));

    // Set up a linked list structure in tbck: 1->2->3->...->n->0
    for (int idx = 1; idx < DATA_SIZE - 1; ++idx) {
        tbck_storage[idx] = idx + 1;
    }
    tbck_storage[DATA_SIZE - 1] = 0;  // Terminate the list

    // Initialize first to point to the start of the list
    first = 1;

    // Initialize pointers
    tbck = tbck_storage;
    matassign = matassign_storage;

    // Give initial values to matassign entries to make bitwise ops meaningful
    for (int idx = 1; idx < DATA_SIZE; ++idx) {
        matassign[idx] = 0xFFFF & ~(1 << 0);  // Ensure bit 0 is clear initially, others may be set
    }
}