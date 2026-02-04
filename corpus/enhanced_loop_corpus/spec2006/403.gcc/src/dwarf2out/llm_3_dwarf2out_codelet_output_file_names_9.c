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
    // Variant 2: Indirect memory access via an index remapping array (simulating non-sequential access)
    // Assume we have an auxiliary array `perm` that defines a permutation of indices 1 to in_use-1
    // Since we cannot introduce new global variables, we simulate a simple indirect pattern: reverse access
    int n = (int)file_table.in_use;
    int j;
    for (j = 1; j < n; j++) {
        int i = n - j; // Reverse order: from in_use-1 down to 1
        backmap[files[i].file_idx] = i;
        dirs[dirs[files[i].dir_idx].dir_idx].used = 1;
    }
}
