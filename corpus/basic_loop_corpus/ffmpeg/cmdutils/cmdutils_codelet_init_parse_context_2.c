#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct OptionGroupDef {
    const char *name;
    const char *sep;
    int flags;
} OptionGroupDef;

union {
    void *dst_ptr;
    int (*func_arg)(void *, const char *, const char *);
    size_t off;
};


typedef struct OptionDef {
    const char *name;
    int flags;
    union {
        void *dst_ptr;
        int (*func_arg)(void *, const char *, const char *);
        size_t off;
    } u;
    const char *help;
    const char *argname;
} OptionDef;

typedef struct Option {
    const OptionDef *opt;
    const char *key;
    const char *val;
} Option;

typedef struct AVDictionary AVDictionary;

typedef struct OptionGroup {
    const OptionGroupDef *group_def;
    const char *arg;
    Option *opts;
    int nb_opts;
    AVDictionary *codec_opts;
    AVDictionary *format_opts;
    AVDictionary *resample_opts;
    AVDictionary *sws_dict;
    AVDictionary *swr_opts;
} OptionGroup;

typedef struct OptionGroupList {
    const OptionGroupDef *group_def;
    OptionGroup *groups;
    int nb_groups;
} OptionGroupList;

typedef struct OptionParseContext {
    OptionGroup global_opts;
    OptionGroupList *groups;
    int nb_groups;
    OptionGroup cur_group;
} OptionParseContext;

extern OptionParseContext *octx;
extern  OptionGroupDef *groups;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < octx->nb_groups; i++)
    octx->groups[i].group_def = &groups[i];

}
