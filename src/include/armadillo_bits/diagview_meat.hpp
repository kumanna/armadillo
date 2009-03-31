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


//! \addtogroup diagview
//! @{


template<typename eT>
inline
diagview<eT>::~diagview()
  {
  arma_extra_debug_sigprint();
  }


template<typename eT>
inline
diagview<eT>::diagview(const basic_mat<eT>& in_m, const u32 in_row_offset, const u32 in_col_offset, const u32 in_len)
  : m(in_m)
  , m_ptr(0)
  , row_offset(in_row_offset)
  , col_offset(in_col_offset)
  , n_elem(in_len)
//   , len
//       (
//       (id == 0)
//         ? (std::min)(m.n_rows, m.n_cols) 
//         : (
//           (id > 0)
//             ? (std::min)(m.n_rows,      m.n_cols - id)
//             : (std::min)(m.n_rows + id, m.n_cols     )
//           )
//       )
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
diagview<eT>::diagview(basic_mat<eT>& in_m, const u32 in_row_offset, const u32 in_col_offset, const u32 in_len)
  : m(in_m)
  , m_ptr(&in_m)
  , row_offset(in_row_offset)
  , col_offset(in_col_offset)
  , n_elem(in_len)
  {
  arma_extra_debug_sigprint();
  }



//! set a diagonal of our matrix using data from a foreign object
template<typename eT>
template<typename T1>
inline
void
diagview<eT>::operator= (const arma_base<eT,T1>& o)
  {
  arma_extra_debug_sigprint();
  arma_check( (m_ptr == 0), "diagview::operator=(): matrix is read only");
  
  const unwrap<T1> tmp(o.get_ref());
  const basic_mat<eT>& x = tmp.M;
  
  diagview& t = *this;
  
  arma_debug_check( !x.is_vec(), "diagview::operator=(): need a vector");
  arma_debug_check( (t.n_elem != x.n_elem), "diagview::operator=(): diagonal and given vector have incompatible lengths");
  
  basic_mat<eT>& t_m = *(t.m_ptr);
  
  for(u32 i=0; i<n_elem; ++i)
    {
    t_m.at(i+row_offset, i+col_offset) = x.mem[i];
    }
  
  }



//! set a diagonal of our matrix using a diagonal from a foreign matrix
template<typename eT>
inline
void
diagview<eT>::operator= (const diagview<eT>& x)
  {
  arma_extra_debug_sigprint();
  arma_check( (m_ptr == 0), "diagview::operator=(): matrix is read only");
  
  diagview<eT>& t = *this;
  
  arma_debug_check( (t.n_elem != x.n_elem), "diagview::operator=(): diagonals have incompatible lengths");
  
        basic_mat<eT>& t_m = *(t.m_ptr);
  const basic_mat<eT>& x_m = x.m;
  
  for(u32 i=0; i<n_elem; ++i)
    {
    t_m.at(i+t.row_offset, i+t.col_offset) = x_m.at(i+x.row_offset, i+x.col_offset);
    }
    
  }



//! \brief
//! extract a diagonal and store it as a column vector
template<typename eT>
inline
void
diagview<eT>::extract(basic_mat<eT>& actual_out, const diagview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  const basic_mat<eT>& in_m = in.m;
  const bool alias = (&actual_out == &in_m);
  
  basic_mat<eT>* tmp = (alias) ? new basic_mat<eT> : 0;
  basic_mat<eT>& out = (alias) ? (*tmp)            : actual_out;
  
  const u32 in_n_elem     = in.n_elem;
  const u32 in_row_offset = in.row_offset;
  const u32 in_col_offset = in.col_offset;
  
  out.set_size(in_n_elem,1);
  eT* out_mem = out.memptr();
  
  for(u32 i=0; i<in_n_elem; ++i)
    {
    out_mem[i] = in_m.at(i+in_row_offset, i+in_col_offset);
    }
  
  
  if(alias)
    {
    actual_out = out;
    delete tmp;
    }
  
  }



template<typename eT>
inline
eT&
diagview<eT>::operator[](const u32 i)
  {
  return (*m_ptr).at(i+row_offset, i+col_offset);
  }
  
  
  
template<typename eT>
inline
eT
diagview<eT>::operator[](const u32 i) const
  {
  return m.at(i+row_offset, i+col_offset);
  }
  
  
  
template<typename eT>
inline
eT&
diagview<eT>::operator()(const u32 i)
  {
  arma_check( (m_ptr == 0), "diagview::operator(): matrix is read only");
  arma_debug_check( (i > n_elem), "diagview::operator(): index out of bounds" );
  
  return (*m_ptr).at(i+row_offset, i+col_offset);
  }
  
  
  
template<typename eT>
inline
eT
diagview<eT>::operator()(const u32 i) const
  {
  arma_debug_check( (i > n_elem), "diagview::operator(): index out of bounds" );
  
  return m.at(i+row_offset, i+col_offset);
  }



template<typename eT>
inline
void
diagview<eT>::fill(const eT val)
  {
  arma_extra_debug_sigprint();
  arma_check( (m_ptr == 0), "diagview::operator(): matrix is read only");
  
  basic_mat<eT>& x = (*m_ptr);
  
  for(u32 i=0; i<n_elem; ++i)
    {
    x.at(i+row_offset, i+col_offset) = val;
    }
  }



template<typename eT>
inline
void
diagview<eT>::zeros()
  {
  arma_extra_debug_sigprint();
  arma_check( (m_ptr == 0), "diagview::operator(): matrix is read only");
  
  basic_mat<eT>& x = (*m_ptr);
  
  for(u32 i=0; i<n_elem; ++i)
    {
    x.at(i+row_offset, i+col_offset) = eT(0);
    }
  }



//! @}
