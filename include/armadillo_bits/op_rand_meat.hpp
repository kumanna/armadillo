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


//! \addtogroup op_rand
//! @{


//! TODO: optionally use the Marsenne-Twister random number generator (see Boost)
template<typename eT>
inline
void
op_rand::direct_rand(eT* x, const u32 n_elem)
  {
  arma_extra_debug_sigprint();
  
  for(u32 i=0; i<n_elem; ++i)
    {
    x[i] = eT(std::rand()) / eT(RAND_MAX);
    }
  
  
  }



template<typename T>
inline
void
op_rand::direct_rand(std::complex<T>* x, const u32 n_elem)
  {
  arma_extra_debug_sigprint();
  
  for(u32 i=0; i<n_elem; ++i)
    {
    const T a = T(std::rand()) / T(RAND_MAX);
    const T b = T(std::rand()) / T(RAND_MAX);

    x[i] = std::complex<T>(a,b);
    }
  
  
  }



template<typename T1>
inline
void
op_rand::apply(Mat<typename T1::elem_type>& out, const Op<T1,op_rand>& in)
  {
  arma_extra_debug_sigprint();
  
  out.set_size(in.aux_u32_a, in.aux_u32_b);
  
  op_rand::direct_rand(out.memptr(), out.n_elem);
  }



template<typename eT>
inline
void
op_rand::apply(Cube<eT>& out, const OpCube<Cube<eT>,op_rand>& in)
  {
  arma_extra_debug_sigprint();
  
  out.set_size(in.aux_u32_a, in.aux_u32_b, in.aux_u32_c);
  
  op_rand::direct_rand(out.memptr(), out.n_elem);
  }



//! @}
