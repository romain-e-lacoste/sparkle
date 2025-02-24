// Author : Romain E. Lacoste
// License : BSD-3-Clause

#ifndef MODEL_HAWKES_EXP_LOG_LIKELIHOOD_SINGLE_H_
#define MODEL_HAWKES_EXP_LOG_LIKELIHOOD_SINGLE_H_

#include "sparkle/array/array.h"
#include "sparkle/array/array2D.h"
#include "sparkle/array/sharedarray.h"
#include "sparkle/array/sharedarray2D.h"

class ModelHawkesExpLogLikelihoodSingle{

	private:

	size_t n_components;
	ArrayInt1D N;
	ArrayDouble1D H;
	ListArrayDouble2D D;
	bool weights_computed;

	void count_n_jumps_per_node(const ListSharedArrayDouble1D &jump_times);

	void compute_weights(const ListSharedArrayDouble1D &jump_times, const double end_time, const double decay);

	double compute_loss_i(const size_t i, const ListSharedArrayDouble1D &jump_times, const double end_time, const double decay, const SharedArrayDouble2D &theta, const bool neg);

	void compute_grad_i(const size_t i, const ListSharedArrayDouble1D &jump_times, const double end_time, const double decay, const SharedArrayDouble2D &theta, SharedArrayDouble2D &grad, const bool neg);

	public:

	ModelHawkesExpLogLikelihoodSingle();

	ModelHawkesExpLogLikelihoodSingle(size_t n);

	size_t get_n_components();

	double compute_loss(const ListSharedArrayDouble1D &jump_times, const double end_time, const double decay, const SharedArrayDouble2D &theta, const bool neg);

	SharedArrayDouble2D compute_grad(const ListSharedArrayDouble1D &jump_times, const double end_time, const double decay, const SharedArrayDouble2D &theta, const bool neg);

	friend class ModelHawkesExpLogLikelihood;
};


#endif /* MODEL_HAWKES_EXP_LOG_LIKELIHOOD_SINGLE_H_ */
