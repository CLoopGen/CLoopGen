#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DenseLayer {
    const float *bias;
    const float *input_weights;
    int nb_inputs;
    int nb_neurons;
    int activation;
} DenseLayer;

typedef struct GRULayer {
    const float *bias;
    const float *input_weights;
    const float *recurrent_weights;
    int nb_inputs;
    int nb_neurons;
    int activation;
} GRULayer;

typedef struct RNNModel {
    int input_dense_size;
    const DenseLayer *input_dense;
    int vad_gru_size;
    const GRULayer *vad_gru;
    int noise_gru_size;
    const GRULayer *noise_gru;
    int denoise_gru_size;
    const GRULayer *denoise_gru;
    int denoise_output_size;
    const DenseLayer *denoise_output;
    int vad_output_size;
    const DenseLayer *vad_output;
} RNNModel;

typedef struct RNNState {
    float *vad_gru_state;
    float *noise_gru_state;
    float *denoise_gru_state;
    RNNModel *model;
} RNNState;

typedef struct AVTXContext AVTXContext;

typedef void (*av_tx_fn)(AVTXContext *, void *, void *, ptrdiff_t);

typedef struct DenoiseState {
    float analysis_mem[480];
    float cepstral_mem[8][22];
    int memid;
    float synthesis_mem[480] __attribute__((aligned(32)));
    float pitch_buf[1728];
    float pitch_enh_buf[1728];
    float last_gain;
    int last_period;
    float mem_hp_x[2];
    float lastg[22];
    RNNState rnn;
    AVTXContext *tx;
    AVTXContext *txi;
    av_tx_fn tx_fn;
    av_tx_fn txi_fn;
} DenoiseState;

extern DenoiseState *st;
extern float (*p);
extern int pitch_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_loop_end = 2;
    int inner_loop_end = (120 << 2);
    for (int j = 0; j < outer_loop_end; j++) {
        for (int i = 0; i < inner_loop_end; i++) {
            int index = j * inner_loop_end + i;
            p[index] = st->pitch_buf[(768 + 960) - (2 * (120 << 2)) - pitch_index + index];
        }
    }
}
