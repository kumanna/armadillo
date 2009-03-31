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


//! \addtogroup op_stddev
//! @{

//! Class for finding the standard deviation
class op_stddev
  {
  public:
  
  template<typename eT>
  inline static void apply(basic_mat<eT>& out, const basic_mat<eT>& X, const u32 norm_type, const u32 dim);
  
  template<typename T>
  inline static void apply(basic_mat<T>& out, const basic_mat< std::complex<T> >& X, const u32 norm_type, const u32 dim);
  
  };

//! @}
