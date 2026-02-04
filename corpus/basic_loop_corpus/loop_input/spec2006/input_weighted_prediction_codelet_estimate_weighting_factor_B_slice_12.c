#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ***wp_weight;
int ***wp_offset;
int luma_log_weight_denom;
int chroma_log_weight_denom;
int listXsize[6];
int _usr_index;
int list_offset;
int clist;

#define index _usr_index

void init_vars() {
    luma_log_weight_denom = 5;
    chroma_log_weight_denom = 4;
    list_offset = 1;

    for (int i = 0; i < 6; i++) {
        listXsize[i] = 0;
    }

    int total_data_size = 16 * 1024 * 1024; // ~16 MB of data to target 0.01s runtime
    int num_clist = 2 + list_offset;
    int base_size = total_data_size / (num_clist * 3 * sizeof(int));
    int avg_elements_per_list = base_size / num_clist;

    wp_weight = (int***)calloc(num_clist, sizeof(int**));
    wp_offset = (int***)calloc(num_clist, sizeof(int**));

    for (clist = 0; clist < num_clist; clist++) {
        int elements_in_this_list = avg_elements_per_list / (8 * (clist + 1));
        if (elements_in_this_list < 1) elements_in_this_list = 1;
        listXsize[clist] = elements_in_this_list;

        wp_weight[clist] = (int**)calloc(elements_in_this_list, sizeof(int*));
        wp_offset[clist] = (int**)calloc(elements_in_this_list, sizeof(int*));

        for (index = 0; index < elements_in_this_list; index++) {
            wp_weight[clist][index] = (int*)calloc(3, sizeof(int));
            wp_offset[clist][index] = (int*)calloc(3, sizeof(int));
        }
    }
}