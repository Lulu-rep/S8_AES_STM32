/*
 * coef_function.h
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#ifndef COEF_FUNCTION_COEF_FUNCTION_H_
#define COEF_FUNCTION_COEF_FUNCTION_H_

#include "main.h"

void coef_add(uint8_t a[], uint8_t b[], uint8_t result[]);
void coef_mult(uint8_t a[], uint8_t b[], uint8_t result[]);
uint8_t gf_mult(uint8_t a, uint8_t b);

#endif /* COEF_FUNCTION_COEF_FUNCTION_H_ */
