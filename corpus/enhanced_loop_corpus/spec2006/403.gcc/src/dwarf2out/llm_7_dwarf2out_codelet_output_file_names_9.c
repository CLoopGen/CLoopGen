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
    int k = 1;
    if (file_table.in_use > 1) {
        do {
            backmap[files[k].file_idx] = k;
            dirs[dirs[files[k].dir_idx].dir_idx].used = 1;
            k++;
        } while (k < (int)file_table.in_use);
    }
}
