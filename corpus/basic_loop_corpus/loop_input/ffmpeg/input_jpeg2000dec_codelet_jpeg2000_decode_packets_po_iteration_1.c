#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

typedef struct Jpeg2000Pass {
    uint16_t rate;
    int64_t disto;
    uint8_t flushed[4];
    int flushed_len;
} Jpeg2000Pass;

typedef struct Jpeg2000Cblk {
    uint8_t npasses;
    uint8_t ninclpasses;
    uint8_t nonzerobits;
    uint16_t length;
    uint16_t *lengthinc;
    uint8_t nb_lengthinc;
    uint8_t lblock;
    uint8_t *data;
    size_t data_allocated;
    int nb_terminations;
    int nb_terminationsinc;
    int *data_start;
    Jpeg2000Pass *passes;
    int coord[2][2];
} Jpeg2000Cblk;

typedef struct Jpeg2000Prec {
    int nb_codeblocks_width;
    int nb_codeblocks_height;
    Jpeg2000TgtNode *zerobits;
    Jpeg2000TgtNode *cblkincl;
    Jpeg2000Cblk *cblk;
    int decoded_layers;
    int coord[2][2];
} Jpeg2000Prec;

typedef struct Jpeg2000Band {
    int coord[2][2];
    uint16_t log2_cblk_width;
    uint16_t log2_cblk_height;
    int i_stepsize;
    float f_stepsize;
    Jpeg2000Prec *prec;
} Jpeg2000Band;

typedef struct Jpeg2000ResLevel {
    uint8_t nbands;
    int coord[2][2];
    int num_precincts_x;
    int num_precincts_y;
    uint8_t log2_prec_width;
    uint8_t log2_prec_height;
    Jpeg2000Band *band;
} Jpeg2000ResLevel;

typedef struct DWTContext {
    int linelen[32][2];
    uint8_t mod[32][2];
    uint8_t ndeclevels;
    uint8_t type;
    int32_t *i_linebuf;
    float *f_linebuf;
} DWTContext;

typedef struct Jpeg2000Component {
    Jpeg2000ResLevel *reslevel;
    DWTContext dwt;
    float *f_data;
    int *i_data;
    int coord[2][2];
    int coord_o[2][2];
    uint8_t roi_shift;
} Jpeg2000Component;

typedef struct Jpeg2000CodingStyle {
    int nreslevels;
    int nreslevels2decode;
    uint8_t log2_cblk_width;
    uint8_t log2_cblk_height;
    uint8_t transform;
    uint8_t csty;
    uint8_t nlayers;
    uint8_t mct;
    uint8_t cblk_style;
    uint8_t prog_order;
    uint8_t log2_prec_widths[34];
    uint8_t log2_prec_heights[34];
} Jpeg2000CodingStyle;

typedef struct Jpeg2000QuantStyle {
    uint8_t expn[99];
    uint16_t mant[99];
    uint8_t quantsty;
    uint8_t nguardbits;
} Jpeg2000QuantStyle;

typedef struct Jpeg2000POCEntry {
    uint16_t LYEpoc;
    uint16_t CSpoc;
    uint16_t CEpoc;
    uint8_t RSpoc;
    uint8_t REpoc;
    uint8_t Ppoc;
} Jpeg2000POCEntry;

typedef struct Jpeg2000POC {
    Jpeg2000POCEntry poc[32];
    int nb_poc;
    int is_default;
} Jpeg2000POC;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct Jpeg2000TilePart {
    uint8_t tile_index;
    const uint8_t *tp_end;
    GetByteContext tpg;
} Jpeg2000TilePart;

typedef struct Jpeg2000Tile {
    Jpeg2000Component *comp;
    uint8_t properties[4];
    Jpeg2000CodingStyle codsty[4];
    Jpeg2000QuantStyle qntsty[4];
    Jpeg2000POC poc;
    Jpeg2000TilePart tile_part[32];
    uint8_t has_ppt;
    uint8_t *packed_headers;
    int packed_headers_size;
    GetByteContext packed_headers_stream;
    uint16_t tp_idx;
    int coord[2][2];
} Jpeg2000Tile;

Jpeg2000Tile *tile;
int RSpoc = 0;
int CSpoc = 0;
int REpoc = 2;
int CEpoc = 2;
int reslevelno = 0;
int compno = 0;
int step_x = 10;
int step_y = 10;

void init_vars() {
    tile = (Jpeg2000Tile*)calloc(1, sizeof(Jpeg2000Tile));
    
    tile->comp = (Jpeg2000Component*)calloc(4, sizeof(Jpeg2000Component));
    for (int i = 0; i < 4; i++) {
        tile->codsty[i].nreslevels = 3;
        tile->codsty[i].nreslevels2decode = 3;
        for (int j = 0; j < 34; j++) {
            tile->codsty[i].log2_prec_widths[j] = 3;
            tile->codsty[i].log2_prec_heights[j] = 3;
        }
    }

    for (int i = 0; i < 2; i++) {
        tile->coord[0][i] = 0;
        tile->coord[1][i] = 1024;
    }

    for (int c = CSpoc; c < CEpoc; c++) {
        Jpeg2000Component *comp = &tile->comp[c];
        comp->reslevel = (Jpeg2000ResLevel*)calloc(tile->codsty[c].nreslevels, sizeof(Jpeg2000ResLevel));
        
        for (int r = 0; r < tile->codsty[c].nreslevels; r++) {
            Jpeg2000ResLevel *rlevel = &comp->reslevel[r];
            rlevel->nbands = 1;
            rlevel->coord[0][0] = 0; rlevel->coord[0][1] = 512 >> r;
            rlevel->coord[1][0] = 0; rlevel->coord[1][1] = 512 >> r;
            rlevel->num_precincts_x = 1 << (tile->codsty[c].log2_prec_widths[r]);
            rlevel->num_precincts_y = 1 << (tile->codsty[c].log2_prec_heights[r]);
            rlevel->log2_prec_width = tile->codsty[c].log2_prec_widths[r];
            rlevel->log2_prec_height = tile->codsty[c].log2_prec_heights[r];
            
            rlevel->band = (Jpeg2000Band*)calloc(1, sizeof(Jpeg2000Band));
            rlevel->band[0].log2_cblk_width = 3;
            rlevel->band[0].log2_cblk_height = 3;
            rlevel->band[0].prec = (Jpeg2000Prec*)calloc(rlevel->num_precincts_x * rlevel->num_precincts_y, sizeof(Jpeg2000Prec));
            
            for (int p = 0; p < rlevel->num_precincts_x * rlevel->num_precincts_y; p++) {
                Jpeg2000Prec *prec = &rlevel->band[0].prec[p];
                prec->nb_codeblocks_width = 8;
                prec->nb_codeblocks_height = 8;
                prec->cblk = (Jpeg2000Cblk*)calloc(64, sizeof(Jpeg2000Cblk));
                prec->decoded_layers = 1;
                prec->coord[0][0] = 0; prec->coord[0][1] = 64;
                prec->coord[1][0] = 0; prec->coord[1][1] = 64;
                
                for (int cb = 0; cb < 64; cb++) {
                    Jpeg2000Cblk *cblk = &prec->cblk[cb];
                    cblk->npasses = 5;
                    cblk->ninclpasses = 0;
                    cblk->nonzerobits = 1;
                    cblk->length = 100;
                    cblk->nb_lengthinc = 4;
                    cblk->lblock = 3;
                    cblk->nb_terminations = 1;
                    cblk->nb_terminationsinc = 1;
                    cblk->passes = (Jpeg2000Pass*)calloc(5, sizeof(Jpeg2000Pass));
                    cblk->data_start = (int*)calloc(5, sizeof(int));
                    cblk->lengthinc = (uint16_t*)calloc(4, sizeof(uint16_t));
                    cblk->data = (uint8_t*)calloc(200, sizeof(uint8_t));
                    cblk->data_allocated = 200;
                    
                    for (int psg = 0; psg < 5; psg++) {
                        cblk->passes[psg].rate = 20;
                        cblk->passes[psg].disto = 1000000;
                        cblk->passes[psg].flushed_len = 0;
                    }
                    
                    for (int li = 0; li < 4; li++) {
                        cblk->lengthinc[li] = 25;
                    }
                }
            }
        }
    }

    tile->poc.nb_poc = 0;
    tile->poc.is_default = 1;

    for (int tp = 0; tp < 32; tp++) {
        tile->tile_part[tp].tile_index = tp;
        tile->tile_part[tp].tp_end = NULL;
        tile->tile_part[tp].tpg.buffer = NULL;
        tile->tile_part[tp].tpg.buffer_end = NULL;
        tile->tile_part[tp].tpg.buffer_start = NULL;
    }

    tile->has_ppt = 0;
    tile->packed_headers = NULL;
    tile->packed_headers_size = 0;
    tile->packed_headers_stream.buffer = NULL;
    tile->packed_headers_stream.buffer_end = NULL;
    tile->packed_headers_stream.buffer_start = NULL;
    tile->tp_idx = 0;
}