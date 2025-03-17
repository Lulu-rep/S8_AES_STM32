/*
 * encryption.h
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#ifndef ENCRYPTION_ENCRYPTION_H_
#define ENCRYPTION_ENCRYPTION_H_

#include <stdint.h>
#include "aes_key.h"

void sub_bytes(uint8_t* state);
void shift_rows(uint8_t* state);
void mix_columns(uint8_t *state);
void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *w);

#endif /* ENCRYPTION_ENCRYPTION_H_ */
