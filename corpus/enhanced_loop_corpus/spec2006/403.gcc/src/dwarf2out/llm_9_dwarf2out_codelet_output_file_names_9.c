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
    // Variant 2: Reduced trip count with stride scaling and added lightweight computation
    int step = 3;
    int limit = (int)file_table.in_use;
    for (i = 1; i < limit; i += step) {
        // Perform main operations only on a subset of elements
        backmap[files[i].file_idx] = i;
        int parent_dir = dirs[files[i].dir_idx].dir_idx;
        // Add light computation to simulate work per iteration
        dirs[parent_dir].used += (dirs[parent_dir].used == 0) ? 1 : 0;
    }
}
