// Author : Romain E. Lacoste
// License : BSD-3-Clause

#ifndef LIB_INCLUDE_SPARKLE_PROX_PROX_L1_H_
#define LIB_INCLUDE_SPARKLE_PROX_PROX_L1_H_

#include "sparkle/array/sharedarray.h"
#include "sparkle/array/sharedarray2D.h"

class ProxL1{

	private:

	double penalization_const;
	size_t start;
	size_t end;
	bool positive;

	double apply_single(const double coeff, const double step_size);

	public:

	ProxL1(double pen_const, size_t st, size_t ed, bool pos);

	void apply(SharedArrayDouble2D &x, const double step_size);
};

#endif /* LIB_INCLUDE_SPARKLE_PROX_PROX_L1_H_ */
