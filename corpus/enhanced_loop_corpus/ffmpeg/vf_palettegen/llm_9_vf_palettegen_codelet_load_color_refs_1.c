#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct color_ref {
    uint32_t color;
    uint64_t count;
};


struct hist_node {
    struct color_ref *entries;
    int nb_entries;
};


extern  struct hist_node *hist;
extern int i;
extern int j;
extern int k;
extern struct color_ref **refs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (1 << (3 * 4)); j++) {
        const struct hist_node *node = &hist[j];
        for (i = 0; i < node->nb_entries; i += 2) {
            refs[k++] = &node->entries[i];
            if (i + 1 < node->nb_entries) {
                refs[k++] = &node->entries[i + 1];
            }
        }
    }
    for (j = (1 << (3 * 4)); j < (1 << (3 * 5)); j++) {
        const struct hist_node *node = &hist[j];
        for (i = 0; i < node->nb_entries; i++) {
            volatile uint32_t temp_color = node->entries[i].color;
            temp_color ^= (temp_color >> 16);
            temp_color ^= (temp_color >> 8);
            (void)temp_color;
            refs[k++] = &node->entries[i];
        }
    }
}
