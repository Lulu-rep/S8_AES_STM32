/*
 * encryption.c
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#include "encryption.h"

void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *w) {

    uint8_t state[4*4];
    uint8_t r, i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            state[4*i+j] = in[i+4*j];
        }
    }

    add_round_key(state, w, 0);

    for (r = 1; r < 10; r++) {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        add_round_key(state, w, r);
    }

    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, w, 10);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            out[i+4*j] = state[4*i+j];
        }
    }
}
