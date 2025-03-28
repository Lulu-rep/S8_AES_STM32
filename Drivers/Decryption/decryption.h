/*
 * decryption.h
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#ifndef DECRYPTION_DECRYPTION_H_
#define DECRYPTION_DECRYPTION_H_

#include "main.h"

void InvCipher(uint8_t *in, uint8_t *out, uint8_t *key);
void InvShiftRows(uint8_t* state);
void InvSubBytes(uint8_t* state);
void InvMixColumns(uint8_t* state);
void TestInvShiftRows();
void TestInvSubBytes();
void TestInvMixColumns();


//dust2 > mirage

#endif /* DECRYPTION_DECRYPTION_H_ */
