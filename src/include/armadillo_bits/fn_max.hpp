// Copyright (C) 2009 NICTA
// 
// Authors:
// - Conrad Sanderson (conradsand at ieee dot org)
// 
// This file is part of the Armadillo C++ library.
// It is provided without any warranty of fitness
// for any purpose. You can redistribute this file
// and/or modify it under the terms of the GNU
// Lesser General Public License (LGPL) as published
// by the Free Software Foundation, either version 3
// of the License or (at your option) any later version.
// (see http://www.opensource.org/licenses for more info)


//! \addtogroup fn_max
//! @{


//! \brief
//! Delayed 'maximum values' operation.
//! The dimension, along which the maxima are found, is set via 'dim'.
//! For dim = 0, the maximum value of each column is found.
//! For dim = 1, the maximum value of each row is found.
//! The default is dim = 0.
//! NOTE: This function works differently than in Matlab/Octave.

template<typename T1>
inline
const op_data<T1, op_max>
max(const arma_base<typename T1::elem_type,T1>& X, const u32 dim = 0)
  {
  arma_extra_debug_sigprint();

  return op_data<T1, op_max>(X.get_ref(), dim, 0);
  }


//! Immediate 'find the maximum value in a row vector' operation
template<typename eT>
inline
eT
max(const basic_rowvec<eT>& A)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "max(): given vector has no elements" );
  
  return op_max::direct_max(A.mem, A.n_elem);
  }



//! Immediate 'find the maximum value in a column vector' operation
template<typename eT>
inline
eT
max(const basic_colvec<eT>& A)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "max(): given vector has no elements" );
  
  return op_max::direct_max(A.mem, A.n_elem);
  }



//! \brief
//! Immediate 'find maximum value' operation,
//! invoked, for example, by: max(max(A))
template<typename T1>
inline
typename T1::elem_type
max(const op_data<T1, op_max>& in)
  {
  arma_extra_debug_sigprint();
  arma_extra_debug_print("max(): two consecutive max() calls detected");
  
  typedef typename T1::elem_type eT;
  
  const unwrap<T1> tmp1(in.m);
  const basic_mat<eT>& X = tmp1.M;
  
  arma_debug_check( (X.n_elem == 0), "max(): given matrix has no elements" );
  
  return op_max::direct_max(X.mem, X.n_elem);
  }



template<typename T1>
inline
const op_data< op_data<T1, op_max>, op_max>
max(const op_data<T1, op_max>& in, const u32 dim)
  {
  arma_extra_debug_sigprint();
  
  return op_data< op_data<T1, op_max>, op_max>(in, dim, 0);
  }



template<typename eT>
inline
eT
max(const subview_row<eT>& A)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "max(): given vector has no elements" );
  
  return op_max::direct_max(A);
  }



template<typename eT>
inline
eT
max(const subview_col<eT>& A)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "max(): given vector has no elements" );
  
  return op_max::direct_max(A);
  }



template<typename eT>
inline
eT
max(const op_data<subview<eT>, op_max>& in)
  {
  arma_extra_debug_sigprint();
  arma_extra_debug_print("max(): two consecutive max() calls detected");
  
  const subview<eT>& X = in.m;
  
  arma_debug_check( (X.n_elem == 0), "max(): given matrix has no elements" );
  
  return op_max::direct_max(X);
  }



template<typename eT>
inline
eT
max(const diagview<eT>& A)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "max(): given vector has no elements" );
  
  return op_max::direct_max(A);
  }



//! @}
