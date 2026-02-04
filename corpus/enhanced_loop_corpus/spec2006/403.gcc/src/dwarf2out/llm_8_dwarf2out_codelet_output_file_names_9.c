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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled-like effect
    int limit = (int)file_table.in_use;
    for (i = 1; i < limit; i += 2) {
        // Process two iterations per loop body to increase arithmetic density
        int idx1 = files[i].file_idx;
        int dir_idx1 = files[i].dir_idx;
        backmap[idx1] = i;
        dirs[dirs[dir_idx1].dir_idx].used = 1;

        if (i + 1 < limit) {
            int idx2 = files[i+1].file_idx;
            int dir_idx2 = files[i+1].dir_idx;
            backmap[idx2] = i + 1;
            dirs[dirs[dir_idx2].dir_idx].used = 1;
        }
    }
}
