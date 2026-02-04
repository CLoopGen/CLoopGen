#include <stdio.h>
#include <stdlib.h>
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

struct file_table file_table;
struct file_info *files;
struct dir_info *dirs;
int *backmap;
int i;

void init_vars() {
    const int num_files = 200000;
    const int num_dirs = 50000;
    
    file_table.allocated = num_files;
    file_table.in_use = num_files;
    file_table.last_lookup_index = 0;
    file_table.table = NULL;

    files = (struct file_info *)calloc(num_files, sizeof(struct file_info));
    dirs = (struct dir_info *)calloc(num_dirs, sizeof(struct dir_info));
    backmap = (int *)calloc(num_files, sizeof(int));

    for (int idx = 0; idx < num_files; idx++) {
        files[idx].file_idx = idx;
        files[idx].dir_idx = rand() % num_dirs;
    }

    for (int idx = 0; idx < num_dirs; idx++) {
        dirs[idx].dir_idx = rand() % num_dirs;
        dirs[idx].used = 0;
    }

    for (int idx = 0; idx < num_files; idx++) {
        backmap[idx] = -1;
    }
}