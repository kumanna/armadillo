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


//! \addtogroup op_dot
//! @{

//! \brief
//! dot product operation 

class op_dot
  {
  public:
  
  template<typename eT>
  inline static eT direct_dot(const u32 n_elem, const eT* const A, const eT* const B);
  
  template<typename eT>
  inline static eT direct_dot(const u32 n_elem, const eT* const A, const eT* const B, const eT* C);
  
  template<typename T1, typename T2>
  inline static typename T1::elem_type apply(const arma_base<typename T1::elem_type,T1>& A_orig, const arma_base<typename T1::elem_type,T2>& B_orig);
  };
  
  

//! \brief
//! normalised dot product operation 

class op_norm_dot
  {
  public:
  
  template<typename T1, typename T2>
  inline static typename T1::elem_type apply(const arma_base<typename T1::elem_type,T1>& A_orig, const arma_base<typename T1::elem_type,T2>& B_orig);
  };

//! @}
