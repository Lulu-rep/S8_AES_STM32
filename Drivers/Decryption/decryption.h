/*
 * decryption.h
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#ifndef DECRYPTION_DECRYPTION_H_
#define DECRYPTION_DECRYPTION_H_

#include "main.h"

void InvCipher(uint8_t* state,int num_rounds,uint8_t* RoundKey);
void InvShftRows(uint8_t* state);
void TestInvShftRows();


//dust2 > mirage

#endif /* DECRYPTION_DECRYPTION_H_ */
