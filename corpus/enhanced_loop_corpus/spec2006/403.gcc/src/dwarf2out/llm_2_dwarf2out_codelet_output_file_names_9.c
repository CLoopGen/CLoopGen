#include <stdio.h>

#include <inttypes.h>

struct file_table {
    char **table;
    unsigned int allocated;
    unsigned int in_use;
    unsigned int last_lookup_index;
};


struct file_info {
    char *path;
    char *fname;
    int length;
    int file_idx;
    int dir_idx;
};


struct dir_info {
    char *path;
    int length;
    int prefix;
    int count;
    int dir_idx;
    int used;
};


extern struct file_table file_table;
extern struct file_info *files;
extern struct dir_info *dirs;
extern int *backmap;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a forward stride of 2 (unrolled-like access)
    int n = (int)file_table.in_use;
    int i;
    // Handle odd in_use by ensuring we don't exceed bounds
    for (i = 1; i < n; i += 2) {
        // First element in stride
        backmap[files[i].file_idx] = i;
        dirs[dirs[files[i].dir_idx].dir_idx].used = 1;

        // Second element in stride, if within bounds
        if (i + 1 < n) {
            backmap[files[i + 1].file_idx] = i + 1;
            dirs[dirs[files[i + 1].dir_idx].dir_idx].used = 1;
        }
    }
}
