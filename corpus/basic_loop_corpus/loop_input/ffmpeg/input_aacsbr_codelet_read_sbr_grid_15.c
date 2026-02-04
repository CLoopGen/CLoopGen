#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int AAC_SIGNE;
typedef float INTFLOAT;
typedef float AAC_FLOAT;

typedef struct SBRData {
    unsigned int bs_frame_class;
    unsigned int bs_add_harmonic_flag;
    AAC_SIGNE bs_num_env;
    uint8_t bs_freq_res[7];
    AAC_SIGNE bs_num_noise;
    uint8_t bs_df_env[5];
    uint8_t bs_df_noise[2];
    uint8_t bs_invf_mode[2][5];
    uint8_t bs_add_harmonic[48];
    unsigned int bs_amp_res;
    INTFLOAT synthesis_filterbank_samples[2304] __attribute__((aligned(32)));
    INTFLOAT analysis_filterbank_samples[1312] __attribute__((aligned(32)));
    int synthesis_filterbank_samples_offset;
    int e_a[2];
    INTFLOAT bw_array[5];
    INTFLOAT W[2][32][32][2];
    int Ypos;
    INTFLOAT Y[2][38][64][2] __attribute__((aligned(16)));
    AAC_FLOAT g_temp[42][48] __attribute__((aligned(16)));
    AAC_FLOAT q_temp[42][48];
    uint8_t s_indexmapped[8][48];
    uint8_t env_facs_q[6][48];
    AAC_FLOAT env_facs[6][48];
    uint8_t noise_facs_q[3][5];
    AAC_FLOAT noise_facs[3][5];
    uint8_t t_env[8];
    uint8_t t_env_num_env_old;
    uint8_t t_q[3];
    unsigned int f_indexnoise;
    unsigned int f_indexsine;
} SBRData;

SBRData *ch_data;
int i;

void init_vars() {
    ch_data = (SBRData*)aligned_alloc(32, sizeof(SBRData));
    
    ch_data->bs_frame_class = 0;
    ch_data->bs_add_harmonic_flag = 0;
    ch_data->bs_num_env = 6; 
    for (int j = 0; j < 7; j++) {
        ch_data->bs_freq_res[j] = (uint8_t)(j * 17);
    }
    ch_data->bs_num_noise = 0;
    for (int j = 0; j < 5; j++) {
        ch_data->bs_df_env[j] = 0;
    }
    for (int j = 0; j < 2; j++) {
        ch_data->bs_df_noise[j] = 0;
    }
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 5; k++) {
            ch_data->bs_invf_mode[j][k] = 0;
        }
    }
    for (int j = 0; j < 48; j++) {
        ch_data->bs_add_harmonic[j] = 0;
    }
    ch_data->bs_amp_res = 0;
    for (int j = 0; j < 2304; j++) {
        ch_data->synthesis_filterbank_samples[j] = 0.0f;
    }
    for (int j = 0; j < 1312; j++) {
        ch_data->analysis_filterbank_samples[j] = 0.0f;
    }
    ch_data->synthesis_filterbank_samples_offset = 0;
    ch_data->e_a[0] = 0;
    ch_data->e_a[1] = 0;
    for (int j = 0; j < 5; j++) {
        ch_data->bw_array[j] = 1.0f;
    }
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 32; b++)
            for (int c = 0; c < 32; c++)
                for (int d = 0; d < 2; d++)
                    ch_data->W[a][b][c][d] = 0.0f;
    ch_data->Ypos = 0;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 38; b++)
            for (int c = 0; c < 64; c++)
                for (int d = 0; d < 2; d++)
                    ch_data->Y[a][b][c][d] = 0.0f;
    for (int a = 0; a < 42; a++)
        for (int b = 0; b < 48; b++)
            ch_data->g_temp[a][b] = 0.0f;
    for (int a = 0; a < 42; a++)
        for (int b = 0; b < 48; b++)
            ch_data->q_temp[a][b] = 0.0f;
    for (int a = 0; a < 8; a++)
        for (int b = 0; b < 48; b++)
            ch_data->s_indexmapped[a][b] = 0;
    for (int a = 0; a < 6; a++)
        for (int b = 0; b < 48; b++)
            ch_data->env_facs_q[a][b] = 0;
    for (int a = 0; a < 6; a++)
        for (int b = 0; b < 48; b++)
            ch_data->env_facs[a][b] = 0.0f;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 5; b++)
            ch_data->noise_facs_q[a][b] = 0;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 5; b++)
            ch_data->noise_facs[a][b] = 0.0f;
    for (int j = 0; j < 8; j++) {
        ch_data->t_env[j] = 0;
    }
    ch_data->t_env_num_env_old = 0;
    for (int j = 0; j < 3; j++) {
        ch_data->t_q[j] = 0;
    }
    ch_data->f_indexnoise = 0;
    ch_data->f_indexsine = 0;
}