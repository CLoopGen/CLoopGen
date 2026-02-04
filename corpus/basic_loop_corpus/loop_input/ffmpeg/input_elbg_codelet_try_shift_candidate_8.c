#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct cell_s {
    int index;
    struct cell_s *next;
} cell;

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct elbg_data {
    int error;
    int dim;
    int numCB;
    int *codebook;
    cell **cells;
    int *utility;
    int64_t *utility_inc;
    int *nearest_cb;
    int *points;
    AVLFG *rand_state;
    int *scratchbuf;
} elbg_data;

elbg_data *elbg;
int idx[3];
int j;
int k;
int cont;
int *newcentroid[3];
cell *tempcell;

void init_vars() {
    // Allocate and initialize elbg
    elbg = (elbg_data*)calloc(1, sizeof(elbg_data));
    
    // Set dimension to a moderate value for predictable computation
    elbg->dim = 64;
    
    // Number of codebook entries
    elbg->numCB = 1024;
    
    // Allocate codebook
    elbg->codebook = (int*)calloc(elbg->numCB * elbg->dim, sizeof(int));
    
    // Allocate points array: each point has 'dim' components
    int num_points = 16384;
    elbg->points = (int*)calloc(num_points * elbg->dim, sizeof(int));
    
    // Initialize points with some data to avoid zero-only access
    for (int i = 0; i < num_points * elbg->dim; i++) {
        elbg->points[i] = rand() % 256;
    }
    
    // Allocate cells array
    elbg->cells = (cell**)calloc(elbg->numCB, sizeof(cell*));
    
    // Set up indexes used in loop: idx[0], idx[2] are accessed via idx[2*k]
    idx[0] = 100;
    idx[1] = 200;
    idx[2] = 300;
    
    // Create two non-empty cell lists at indices used in loop
    for (int list_idx = 0; list_idx < 2; list_idx++) {
        int cell_count = 500 + list_idx * 300;  // ~500-800 cells per list
        cell* head = NULL;
        for (int i = 0; i < cell_count; i++) {
            cell* c = (cell*)malloc(sizeof(cell));
            // Ensure index stays within valid range for points array
            c->index = rand() % num_points;
            c->next = head;
            head = c;
        }
        elbg->cells[idx[2 * list_idx]] = head;
    }
    
    // Allocate and initialize newcentroid arrays
    for (int i = 0; i < 3; i++) {
        newcentroid[i] = (int*)calloc(elbg->dim, sizeof(int));
    }
    
    // Initialize counters
    cont = 0;
    j = 0;
    k = 0;
    tempcell = NULL;
}

// Define elbg and other externs as weak symbols so they can be overridden if needed
__attribute__((weak)) elbg_data *elbg = NULL;
__attribute__((weak)) int idx[3] = {0};
__attribute__((weak)) int j = 0;
__attribute__((weak)) int k = 0;
__attribute__((weak)) int cont = 0;
__attribute__((weak)) int *newcentroid[3] = {NULL, NULL, NULL};
__attribute__((weak)) cell *tempcell = NULL;