#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PullupBuffer {
    int lock[2];
    uint8_t *planes[4];
} PullupBuffer;

typedef struct PullupField {
    int parity;
    PullupBuffer *buffer;
    unsigned int flags;
    int breaks;
    int affinity;
    int *diffs;
    int *combs;
    int *vars;
    struct PullupField *prev;
    struct PullupField *next;
} PullupField;

PullupField *begin;
PullupField *end;
PullupField *f;
int count;

static PullupBuffer *buffers;
static PullupField *fields;
static int *diff_data;
static int *comb_data;
static int *var_data;
static uint8_t *plane_data;

void init_vars() {
    const size_t num_fields = 1 << 20; // ~1M fields, sufficient for ~0.01 sec runtime
    size_t i;

    buffers = calloc(num_fields, sizeof(PullupBuffer));
    fields = calloc(num_fields, sizeof(PullupField));
    diff_data = calloc(num_fields, 32 * sizeof(int));
    comb_data = calloc(num_fields, 32 * sizeof(int));
    var_data = calloc(num_fields, 32 * sizeof(int));
    plane_data = calloc(num_fields, 4 * 64 * sizeof(uint8_t));

    if (!buffers || !fields || !diff_data || !comb_data || !var_data || !plane_data) {
        exit(1);
    }

    for (i = 0; i < num_fields; i++) {
        buffers[i].lock[0] = 0;
        buffers[i].lock[1] = 0;
        for (int p = 0; p < 4; p++) {
            buffers[i].planes[p] = plane_data + i * 4 * 64 + p * 64;
        }

        fields[i].parity = i % 2;
        fields[i].buffer = &buffers[i];
        fields[i].flags = 0;
        fields[i].breaks = 0;
        fields[i].affinity = 0;
        fields[i].diffs = diff_data + i * 32;
        fields[i].combs = comb_data + i * 32;
        fields[i].vars = var_data + i * 32;
        fields[i].prev = (i == 0) ? NULL : &fields[i - 1];
        fields[i].next = (i == num_fields - 1) ? NULL : &fields[i + 1];
    }

    begin = &fields[0];
    end = NULL;
    f = NULL;
    count = 0;
}