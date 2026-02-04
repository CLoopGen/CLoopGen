#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define index _usr_index

// Forward declarations
extern int ***wp_weight;
extern int ***wp_offset;
extern int luma_log_weight_denom;
extern int chroma_log_weight_denom;
extern int listXsize[6];
extern int _usr_index;
extern int list_offset;
extern int clist;

// Definitions
int luma_log_weight_denom = 5;
int chroma_log_weight_denom = 5;
int listXsize[6] = {0};
int _usr_index;
int list_offset = 1; // so clist goes from 0 to 2
int clist;

int ***wp_weight;
int ***wp_offset;

void init_vars() {
    // Target data size: aim for ~64MB total to ensure loop runtime around 0.01s
    const size_t target_total_bytes = 64 * 1024 * 1024;
    const size_t bytes_per_element = sizeof(int) * 3; // 3 components per pixel
    const size_t total_elements = target_total_bytes / bytes_per_element;
    
    // Distribute across clist (3 iterations: 0,1,2 due to list_offset=1 => 2+1=3)
    int num_clist = 2 + list_offset; // 3
    int avg_per_list = total_elements / num_clist;

    wp_weight = (int***)calloc(num_clist, sizeof(int**));
    wp_offset = (int***)calloc(num_clist, sizeof(int**));

    if (!wp_weight || !wp_offset) {
        abort();
    }

    for (int clist_idx = 0; clist_idx < num_clist; clist_idx++) {
        int size = avg_per_list / 1000; // Reduce density to avoid over-allocation
        if (size < 10) size = 10;
        listXsize[clist_idx] = size;

        wp_weight[clist_idx] = (int**)calloc(size, sizeof(int*));
        wp_offset[clist_idx] = (int**)calloc(size, sizeof(int*));

        if (!wp_weight[clist_idx] || !wp_offset[clist_idx]) {
            abort();
        }

        for (int idx = 0; idx < size; idx++) {
            wp_weight[clist_idx][idx] = (int*)calloc(3, sizeof(int));
            wp_offset[clist_idx][idx] = (int*)calloc(3, sizeof(int));

            if (!wp_weight[clist_idx][idx] || !wp_offset[clist_idx][idx]) {
                abort();
            }
        }
    }
}