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


//! \addtogroup fn_var
//! @{



template<typename T1>
inline
basic_mat<typename T1::pod_type>
var(const arma_base<typename T1::elem_type,T1>& X, const u32 norm_type = 0, const u32 dim = 0)
  {
  arma_extra_debug_sigprint();
  
  const unwrap<T1> A_tmp(X.get_ref());

  // if T1 is a complex matrix,
  // pod_type is the underlying type used by std::complex;
  // otherwise pod_type is the same as elem_type
  
  typedef typename T1::elem_type  in_eT;
  typedef typename T1::pod_type  out_eT;

  const basic_mat<in_eT>& A = A_tmp.M;
  
  basic_mat<out_eT> out;
  
  op_var::apply(out, A, norm_type, dim);
  
  return out;
  }



//! Immediate 'find the variance of a row vector' operation
template<typename eT>
inline
eT
var(const basic_rowvec<eT>& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A.mem, A.n_elem, norm_type);
  }



//! Immediate 'find the variance of a row vector' operation (version for complex numbers)
template<typename T>
inline
T
var(const basic_rowvec< std::complex<T> >& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A.mem, A.n_elem, norm_type);
  }



//! Immediate 'find the variance of a column vector' operation
template<typename eT>
inline
eT
var(const basic_colvec<eT>& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A.mem, A.n_elem, norm_type);
  }



//! Immediate 'find the variance of a column vector' operation (version for complex numbers)
template<typename T>
inline
T
var(const basic_colvec< std::complex<T> >& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A.mem, A.n_elem, norm_type);
  }



template<typename eT>
inline
eT
var(const subview_row<eT>& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A, norm_type);
  }



template<typename T>
inline
T
var(const subview_row< std::complex<T> >& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A, norm_type);
  }



template<typename eT>
inline
eT
var(const subview_col<eT>& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A, norm_type);
  }



template<typename T>
inline
T
var(const subview_col< std::complex<T> >& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A, norm_type);
  }



template<typename eT>
inline
eT
var(const diagview<eT>& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A, norm_type);
  }



template<typename T>
inline
T
var(const diagview< std::complex<T> >& A, const u32 norm_type = 0)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_check( (A.n_elem == 0), "var(): given vector has no elements" );
  
  return op_var::direct_var(A, norm_type);
  }



//! @}
