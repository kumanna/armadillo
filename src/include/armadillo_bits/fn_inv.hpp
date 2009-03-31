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


//! \addtogroup fn_inv
//! @{

//! delayed matrix inverse
template<typename T1>
inline
const op_data<T1, op_inv>
inv(const arma_base<typename T1::elem_type,T1>& X)
  {
  arma_extra_debug_sigprint();
  
  return op_data<T1, op_inv>(X.get_ref());
  }



//! remove the inverse operation if applied twice consecutively
template<typename T1>
inline
const T1&
inv(const op_data<T1, op_inv>& X)
  {
  arma_extra_debug_sigprint();
  
  return X.m;
  }

//! @}
