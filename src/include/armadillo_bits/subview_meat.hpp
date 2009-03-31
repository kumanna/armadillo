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


//! \addtogroup subview
//! @{


template<typename eT>
inline
subview<eT>::~subview()
  {
  arma_extra_debug_sigprint();
  }


template<typename eT>
inline
subview<eT>::subview(const basic_mat<eT>& in_m, const u32 in_row1, const u32 in_col1, const u32 in_row2,  const u32 in_col2)
  : m(in_m)
  , m_ptr(0)
  , aux_row1(in_row1)
  , aux_col1(in_col1)
  , aux_row2(in_row2)
  , aux_col2(in_col2)
  , n_rows(1 + in_row2 - in_row1)
  , n_cols(1 + in_col2 - in_col1)
  , n_elem(n_rows*n_cols)
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
subview<eT>::subview(basic_mat<eT>& in_m, const u32 in_row1, const u32 in_col1, const u32 in_row2,  const u32 in_col2)
  : m(in_m)
  , m_ptr(&in_m)
  , aux_row1(in_row1)
  , aux_col1(in_col1)
  , aux_row2(in_row2)
  , aux_col2(in_col2)
  , n_rows(1 + in_row2 - in_row1)
  , n_cols(1 + in_col2 - in_col1)
  , n_elem(n_rows*n_cols)
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
void
subview<eT>::fill(const eT val)
  {
  arma_extra_debug_sigprint();
  
  for(u32 col = 0; col<n_cols; ++col)
    {
    eT* coldata = colptr(col);
    
    for(u32 row = 0; row != n_rows; ++row)
      {
      coldata[row] = val;
      }
    }
  
  
  }



template<typename eT>
inline
void
subview<eT>::operator+= (const eT val)
  {
  arma_extra_debug_sigprint();
  
  for(u32 col = 0; col<n_cols; ++col)
    {
    eT* coldata = colptr(col);
    
    for(u32 row = 0; row<n_rows; ++row)
      {
      coldata[row] += val;
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator-= (const eT val)
  {
  arma_extra_debug_sigprint();
  
  for(u32 col = 0; col<n_cols; ++col)
    {
    eT* coldata = colptr(col);
    
    for(u32 row = 0; row<n_rows; ++row)
      {
      coldata[row] -= val;
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator*= (const eT val)
  {
  arma_extra_debug_sigprint();
  
  for(u32 col = 0; col<n_cols; ++col)
    {
    eT* coldata = colptr(col);
    
    for(u32 row = 0; row<n_rows; ++row)
      {
      coldata[row] *= val;
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator/= (const eT val)
  {
  arma_extra_debug_sigprint();
  
  for(u32 col = 0; col<n_cols; ++col)
    {
    eT* coldata = colptr(col);
    
    for(u32 row = 0; row<n_rows; ++row)
      {
      coldata[row] /= val;
      }
    
    }
  
  }



template<typename eT>
template<typename T1>
inline
void
subview<eT>::operator= (const arma_base<eT,T1>& in)
  {
  arma_extra_debug_sigprint();
  
  const unwrap<T1> tmp(in.get_ref());
  
  const basic_mat<eT>& x = tmp.M;
        subview<eT>&   t = *this;
  
  arma_debug_assert_same_size(t, x, "insert into submatrix");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] = x_coldata[row];
      }
      
    }
  }



template<typename eT>
template<typename T1>
inline
void
subview<eT>::operator+= (const arma_base<eT,T1>& in)
  {
  arma_extra_debug_sigprint();
  
  const unwrap<T1> tmp(in.get_ref());
  
  const basic_mat<eT>& x = tmp.M;
        subview<eT>&   t = *this;
  
  arma_debug_assert_same_size(t, x, "matrix addition");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] += x_coldata[row];
      }
    }
  
  }



template<typename eT>
template<typename T1>
inline
void
subview<eT>::operator-= (const arma_base<eT,T1>& in)
  {
  arma_extra_debug_sigprint();
  
  const unwrap<T1> tmp(in.get_ref());
  
  const basic_mat<eT>& x = tmp.M;
        subview<eT>&   t = *this;
  
  arma_debug_assert_same_size(t, x, "matrix subtraction");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] -= x_coldata[row];
      }
    }
  
  }



template<typename eT>
template<typename T1>
inline
void
subview<eT>::operator%= (const arma_base<eT,T1>& in)
  {
  arma_extra_debug_sigprint();
  
  const unwrap<T1> tmp(in.get_ref());
  
  const basic_mat<eT>& x = tmp.M;
        subview<eT>&   t = *this;
  
  arma_debug_assert_same_size(t, x, "matrix schur product");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] *= x_coldata[row];
      }
    }
  
  }



template<typename eT>
template<typename T1>
inline
void
subview<eT>::operator/= (const arma_base<eT,T1>& in)
  {
  arma_extra_debug_sigprint();
  
  const unwrap<T1> tmp(in.get_ref());
  
  const basic_mat<eT>& x = tmp.M;
        subview<eT>&   t = *this;
  
  arma_debug_assert_same_size(t, x, "element-wise matrix division");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] /= x_coldata[row];
      }
    }
  
  }



//! x.submat(...) = y.submat(...)
template<typename eT>
inline
void
subview<eT>::operator= (const subview<eT>& x_in)
  {
  arma_extra_debug_sigprint();
  
  const bool overlap = check_overlap(x_in);
  
  basic_mat<eT>*     tmp_mat     = overlap ? new basic_mat<eT>(x_in.m) : 0;
  const subview<eT>* tmp_subview = overlap ? new subview<eT>(*tmp_mat, x_in.aux_row1, x_in.aux_col1, x_in.aux_row2, x_in.aux_col2) : 0;
  const subview<eT>&           x = overlap ? (*tmp_subview) : x_in;
  
  subview<eT>& t = *this;
  
  arma_debug_assert_same_size(t, x, "insert into submatrix");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] = x_coldata[row];
      }
    
    }
    
  if(overlap)
    {
    delete tmp_subview;
    delete tmp_mat;
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator+= (const subview<eT>& x_in)
  {
  arma_extra_debug_sigprint();
  
  const bool overlap = check_overlap(x_in);
  
  basic_mat<eT>*     tmp_mat     = overlap ? new basic_mat<eT>(x_in.m) : 0;
  const subview<eT>* tmp_subview = overlap ? new subview(*tmp_mat, x_in.aux_row1, x_in.aux_col1, x_in.aux_row2, x_in.aux_col2) : 0;
  const subview<eT>&           x = overlap ? (*tmp_subview) : x_in;
  
  
  subview<eT>& t = *this;
  
  arma_debug_assert_same_size(t, x, "matrix addition");

  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] += x_coldata[row];
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator-= (const subview<eT>& x_in)
  {
  arma_extra_debug_sigprint();
  
  const bool overlap = check_overlap(x_in);
  
  basic_mat<eT>*     tmp_mat     = overlap ? new basic_mat<eT>(x_in.m) : 0;
  const subview<eT>* tmp_subview = overlap ? new subview(*tmp_mat, x_in.aux_row1, x_in.aux_col1, x_in.aux_row2, x_in.aux_col2) : 0;
  const subview<eT>&           x = overlap ? (*tmp_subview) : x_in;
  
  subview<eT>& t = *this;
  
  arma_debug_assert_same_size(t, x, "matrix subtraction");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] -= x_coldata[row];
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator%= (const subview& x_in)
  {
  arma_extra_debug_sigprint();
  
  const bool overlap = check_overlap(x_in);
  
  basic_mat<eT>*     tmp_mat     = overlap ? new basic_mat<eT>(x_in.m) : 0;
  const subview<eT>* tmp_subview = overlap ? new subview(*tmp_mat, x_in.aux_row1, x_in.aux_col1, x_in.aux_row2, x_in.aux_col2) : 0;
  const subview<eT>&           x = overlap ? (*tmp_subview) : x_in;
  
  subview<eT>& t = *this;
  
  arma_debug_assert_same_size(t, x, "matrix schur product");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] *= x_coldata[row];
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::operator/= (const subview& x_in)
  {
  arma_extra_debug_sigprint();
  
  const bool overlap = check_overlap(x_in);
  
  basic_mat<eT>*     tmp_mat     = overlap ? new basic_mat<eT>(x_in.m) : 0;
  const subview<eT>* tmp_subview = overlap ? new subview(*tmp_mat, x_in.aux_row1, x_in.aux_col1, x_in.aux_row2, x_in.aux_col2) : 0;
  const subview<eT>&           x = overlap ? (*tmp_subview) : x_in;
  
  subview<eT>& t = *this;
  
  arma_debug_assert_same_size(t, x, "element-wise matrix division");
  
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
          eT* t_coldata = t.colptr(col);
    const eT* x_coldata = x.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] /= x_coldata[row];
      }
    
    }
  
  }



template<typename eT>
inline
void
subview<eT>::zeros()
  {
  arma_extra_debug_sigprint();
  
  subview<eT>& t = *this;
  
  for(u32 col = 0; col<t.n_cols; ++col)
    {
    eT* t_coldata = t.colptr(col);
    
    for(u32 row = 0; row<t.n_rows; ++row)
      {
      t_coldata[row] = eT(0);
      }
    
    }
  
  }



template<typename eT>
inline
eT&
subview<eT>::operator[](const u32 i)
  {
  arma_check( (m_ptr == 0), "subview::operator[]: matrix is read-only");
  
  const u32 in_col = i / n_rows;
  const u32 in_row = i % n_rows;
    
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return access::rw( (*m_ptr).mem[index] );
  }



template<typename eT>
inline
eT
subview<eT>::operator[](const u32 i) const
  {
  const u32 in_col = i / n_rows;
  const u32 in_row = i % n_rows;
  
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return m.mem[index];
  }



template<typename eT>
inline
eT&
subview<eT>::operator()(const u32 i)
  {
  arma_check( (m_ptr == 0), "subview::operator(): matrix is read-only");
  arma_debug_check( (i >= n_elem), "subview::operator(): index out of bounds");
    
  const u32 in_col = i / n_rows;
  const u32 in_row = i % n_rows;
  
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return access::rw( (*m_ptr).mem[index] );
  }



template<typename eT>
inline
eT
subview<eT>::operator()(const u32 i) const
  {
  arma_debug_check( (i >= n_elem), "subview::operator(): index out of bounds");
  
  const u32 in_col = i / n_rows;
  const u32 in_row = i % n_rows;
  
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return m.mem[index];
  }



template<typename eT>
inline
eT&
subview<eT>::operator()(const u32 in_row, const u32 in_col)
  {
  arma_check( (m_ptr == 0), "subview::operator(): matrix is read-only");
  arma_debug_check( ( (n_elem == 0) || (in_row >= n_rows) || (in_col >= n_cols)), "subview::operator(): index out of bounds");
  
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return access::rw( (*m_ptr).mem[index] );
  }



template<typename eT>
inline
eT
subview<eT>::operator()(const u32 in_row, const u32 in_col) const
  {
  arma_debug_check( ( (n_elem == 0) || (in_row >= n_rows) || (in_col >= n_cols)), "subview::operator(): index out of bounds");
  
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return m.mem[index];
  }



template<typename eT>
inline
eT&
subview<eT>::at(const u32 in_row, const u32 in_col)
  {
  arma_check( (m_ptr == 0), "subview::at(): matrix is read-only");
  
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return access::rw( (*m_ptr).mem[index] );
  }



template<typename eT>
inline
eT
subview<eT>::at(const u32 in_row, const u32 in_col) const
  {
  const u32 index = (in_col + aux_col1)*m.n_rows + aux_row1 + in_row;
  return m.mem[index];
  }



template<typename eT>
inline
eT*
subview<eT>::colptr(const u32 in_col)
  {
  arma_check( (m_ptr == 0), "subview::colptr(): matrix is read-only");
    
  return & access::rw((*m_ptr).mem[ (in_col + aux_col1)*m.n_rows + aux_row1 ]);
  }



template<typename eT>
inline
const eT*
subview<eT>::colptr(const u32 in_col) const
  {
  return & m.mem[ (in_col + aux_col1)*m.n_rows + aux_row1 ];
  }



template<typename eT>
inline
bool
subview<eT>::check_overlap(const subview<eT>& x) const
  {
  const subview<eT>& t = *this;
  
  if(&t.m != &x.m)
    {
    return false;
    }
  else
    {
    const bool row_overlap =
      (
      ( (x.aux_row1 >= t.aux_row1) && (x.aux_row1 <= t.aux_row2) )
      || 
      ( (x.aux_row2 >= t.aux_row1) && (x.aux_row2 <= t.aux_row2) )
      );
    
    const bool col_overlap =
      (
      ( (x.aux_col1 >= t.aux_col1) && (x.aux_col1 <= t.aux_col2) )
      || 
      ( (x.aux_col2 >= t.aux_col1) && (x.aux_col2 <= t.aux_col2) )
      );
    
    
    return (row_overlap & col_overlap);
    }
  }



//! X = Y.submat(...)
template<typename eT>
inline
void
subview<eT>::extract(basic_mat<eT>& actual_out, const subview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  //
  const bool alias = (&actual_out == &in.m);
  
  basic_mat<eT>* tmp = (alias) ? new basic_mat<eT> : 0;
  basic_mat<eT>& out = (alias) ? (*tmp)            : actual_out;
  
  //
  
  const u32 n_rows = in.n_rows;
  const u32 n_cols = in.n_cols;
  
  out.set_size(n_rows, n_cols);
  
  arma_extra_debug_print(arma_boost::format("out.n_rows = %d   out.n_cols = %d    in.m.n_rows = %d  in.m.n_cols = %d") % out.n_rows % out.n_cols % in.m.n_rows % in.m.n_cols );
  
  
  if((n_rows == 1) && (n_cols != 1))
    {
    arma_extra_debug_print("subview::apply(): copying row (going across columns)");
    
    for(u32 col = 0; col<n_cols; ++col)
      {
      out[col] = in.m.at(in.aux_row1, col);
      }
    }
  else
  if((n_rows != 1) && (n_cols == 1))
    {
    arma_extra_debug_print("subview::apply(): copying col (going across n_rows)");
    
    const eT* in_coldata = in.colptr(0);
    
    for(u32 row = 0; row<n_rows; ++row)
      {
      out[row] = in_coldata[row];
      }
    
    }
  else  
  for(u32 col = 0; col<n_cols; ++col)
    {
          eT* out_coldata = out.colptr(col);
    const eT*  in_coldata =  in.colptr(col);
    
    for(u32 row = 0; row<n_rows; ++row)
      {
      out_coldata[row] = in_coldata[row];
      }
    
    }
  
  
  if(alias)
    {
    actual_out = out;
    delete tmp;
    }
  
  }



//! X += Y.submat(...)
template<typename eT>
inline
void
subview<eT>::plus_inplace(basic_mat<eT>& out, const subview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(out, in, "matrix addition");
  
  if(&out != &in.m)
    {
    const u32 n_rows = out.n_rows;
    const u32 n_cols = out.n_cols;
    
    for(u32 col = 0; col<n_cols; ++col)
      {
            eT* out_coldata = out.colptr(col);
      const eT*  in_coldata =  in.colptr(col);
      
      for(u32 row = 0; row<n_rows; ++row)
        {
        out_coldata[row] += in_coldata[row];
        }
      }
    }
  else
    {
    // X += X.submat(...)
    // this only makes sense if X and X.submat(...) are the same size
    
    eT* out_mem = out.memptr();
    
    for(u32 i=0; i<out.n_elem; ++i)
      {
      out_mem[i] *= eT(2);
      }
    }
  
  }



//! X -= Y.submat(...)
template<typename eT>
inline
void
subview<eT>::minus_inplace(basic_mat<eT>& out, const subview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(out, in, "matrix subtraction");
  
  if(&out != &in.m)
    {
    const u32 n_rows = out.n_rows;
    const u32 n_cols = out.n_cols;
    
    for(u32 col = 0; col<n_cols; ++col)
      {
            eT* out_coldata = out.colptr(col);
      const eT*  in_coldata =  in.colptr(col);
      
      for(u32 row = 0; row<n_rows; ++row)
        {
        out_coldata[row] -= in_coldata[row];
        }
      }
    }
  else
    {
    out.zeros();
    }
  
  }



//! X *= Y.submat(...)
template<typename eT>
inline
void
subview<eT>::times_inplace(basic_mat<eT>& out, const subview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_mul_size(out, in, "matrix multiply");

  if(&out != &in.m)
    {
    glue_times::apply_inplace(out, basic_mat<eT>(in));
    }
  else
    {
    glue_times::apply_inplace(out, out);
    }
  
  }



//! X %= Y.submat(...)
template<typename eT>
inline
void
subview<eT>::schur_inplace(basic_mat<eT>& out, const subview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(out, in, "matrix schur product");
  
  if(&out != &in.m)
    {
    const u32 n_rows = out.n_rows;
    const u32 n_cols = out.n_cols;
    
    for(u32 col = 0; col<n_cols; ++col)
      {
            eT* out_coldata = out.colptr(col);
      const eT*  in_coldata =  in.colptr(col);
      
      for(u32 row = 0; row<n_rows; ++row)
        {
        out_coldata[row] *= in_coldata[row];
        }
      }
    }
  else
    {
    eT* out_mem = out.memptr();
    
    for(u32 i=0; i<out.n_elem; ++i)
      {
      const eT tmp = out_mem[i];
      out_mem[i] = tmp*tmp;
      }
    }
  
  }



//! X /= Y.submat(...)
template<typename eT>
inline
void
subview<eT>::div_inplace(basic_mat<eT>& out, const subview<eT>& in)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(out, in, "element-wise matrix division");
  
  if(&out != &in.m)
    {
    const u32 n_rows = out.n_rows;
    const u32 n_cols = out.n_cols;
    
    for(u32 col = 0; col<n_cols; ++col)
      {
            eT* out_coldata = out.colptr(col);
      const eT*  in_coldata =  in.colptr(col);
      
      for(u32 row = 0; row<n_rows; ++row)
        {
        out_coldata[row] /= in_coldata[row];
        }
      }
    }
  else
    {
    eT* out_mem = out.memptr();
    
    for(u32 i=0; i<out.n_elem; ++i)
      {
      const eT tmp = out_mem[i];
      out_mem[i] = tmp*tmp;
      }
    }
  
  }



//
//
//



template<typename eT>
inline
subview_col<eT>::subview_col(const basic_mat<eT>& in_m, const u32 in_col)
  : subview<eT>(in_m, 0, in_col, in_m.n_rows-1, in_col)
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
subview_col<eT>::subview_col(basic_mat<eT>& in_m, const u32 in_col)
  : subview<eT>(in_m, 0, in_col, in_m.n_rows-1, in_col)
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
void
subview_col<eT>::operator=(const subview<eT>& X)
  {
  arma_extra_debug_sigprint();
  
  subview<eT>::operator=(X);
  arma_debug_check( (subview<eT>::n_cols > 1), "subview_col(): incompatible dimensions" );
  }



template<typename eT>
inline
void
subview_col<eT>::operator=(const subview_col<eT>& X)
  {
  arma_extra_debug_sigprint();
  
  subview<eT>::operator=(X); // interprets 'subview_col' as 'subview'
  arma_debug_check( (subview<eT>::n_cols > 1), "subview_col(): incompatible dimensions" );
  }



template<typename eT>
template<typename T1>
inline
void
subview_col<eT>::operator=(const arma_base<eT,T1>& X)
  {
  arma_extra_debug_sigprint();
  
  subview<eT>::operator=(X);
  arma_debug_check( (subview<eT>::n_cols > 1), "subview_col(): incompatible dimensions" );
  }




//
//
//



template<typename eT>
inline
subview_row<eT>::subview_row(const basic_mat<eT>& in_m, const u32 in_row)
  : subview<eT>(in_m, in_row, 0, in_row, in_m.n_cols-1)
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
subview_row<eT>::subview_row(basic_mat<eT>& in_m, const u32 in_row)
  : subview<eT>(in_m, in_row, 0, in_row, in_m.n_cols-1)
  {
  arma_extra_debug_sigprint();
  }



template<typename eT>
inline
void
subview_row<eT>::operator=(const subview<eT>& X)
  {
  arma_extra_debug_sigprint();
  
  subview<eT>::operator=(X);
  arma_debug_check( (subview<eT>::n_rows > 1), "subview_row(): incompatible dimensions" );
  }



template<typename eT>
inline
void
subview_row<eT>::operator=(const subview_row<eT>& X)
  {
  arma_extra_debug_sigprint();
  
  subview<eT>::operator=(X); // interprets 'subview_row' as 'subview'
  arma_debug_check( (subview<eT>::n_rows > 1), "subview_row(): incompatible dimensions" );
  }



template<typename eT>
template<typename T1>
inline
void
subview_row<eT>::operator=(const arma_base<eT,T1>& X)
  {
  arma_extra_debug_sigprint();
  
  subview<eT>::operator=(X);
  arma_debug_check( (subview<eT>::n_rows > 1), "subview_row(): incompatible dimensions" );
  }



//! @}
