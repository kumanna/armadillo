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


//! \addtogroup fn_dot
//! @{


template<typename T1, typename T2>
inline
typename T1::elem_type
dot(const arma_base<typename T1::elem_type,T1>& A, const arma_base<typename T1::elem_type,T2>& B)
  {
  arma_extra_debug_sigprint();
  
  return op_dot::apply(A,B);
  }



template<typename T1, typename T2>
inline
typename T1::elem_type
norm_dot(const arma_base<typename T1::elem_type,T1>& A, const arma_base<typename T1::elem_type,T2>& B)
  {
  arma_extra_debug_sigprint();
  
  return op_norm_dot::apply(A,B);
  }


//! @}
