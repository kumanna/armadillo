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


//! \addtogroup glue_minus
//! @{


//! Immediate out = A-B
template<typename eT>
inline
void
glue_minus::apply(basic_mat<eT>& out, const basic_mat<eT>& A, const basic_mat<eT>& B)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(A, B, "matrix subtraction");
  
  // no aliasing problem
  out.set_size(A.n_rows,A.n_cols);
    
        eT* out_mem = out.memptr();
  const eT* A_mem   = A.mem;
  const eT* B_mem   = B.mem;
  
  const u32 n_elem  = A.n_elem;
  
  for(u32 i=0; i<n_elem; ++i)
    {
    out_mem[i] = A_mem[i] - B_mem[i];
    }
    
  }



//! Immediate out = A-B-C
template<typename eT>
inline
void
glue_minus::apply(basic_mat<eT>& out, const basic_mat<eT>& A, const basic_mat<eT>& B, const basic_mat<eT>& C)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(A, B, "matrix subtraction");
  arma_debug_assert_same_size(A, C, "matrix subtraction");
  
  // no aliasing problem
  out.set_size(A.n_rows, A.n_cols);
    
        eT* out_mem = out.memptr();
  const eT* A_mem   = A.mem;
  const eT* B_mem   = B.mem;
  const eT* C_mem   = C.mem;
  
  const u32 n_elem = A.n_elem;
  
  for(u32 i=0; i<n_elem; ++i)
    {
    out_mem[i] = A_mem[i] - B_mem[i] - C_mem[i];
    }
  
  }



//! Immediate out = A-B  (operands obtained from glue_data)
template<typename eT>
inline
void
glue_minus::apply(basic_mat<eT>& out, const glue_data<basic_mat<eT>,basic_mat<eT>,glue_minus>& X)
  {
  glue_minus::apply(out, X.A, X.B);
  }



//! Immediate out = A-B-C  (operands obtained from glue_data)
template<typename eT>
inline
void
glue_minus::apply(basic_mat<eT>& out, const glue_data< glue_data<basic_mat<eT>,basic_mat<eT>,glue_minus>, basic_mat<eT>, glue_minus> &X)
  {
  glue_minus::apply(out, X.A.A, X.A.B, X.B);
  }



//! Immediate out = A-B-...-Z  (operands obtained from glue_data)
template<typename T1, typename T2>
inline
void
glue_minus::apply(basic_mat<typename T1::elem_type>& out, const glue_data<T1,T2,glue_minus>& X)
  {
  arma_extra_debug_sigprint();
  
  typedef typename T1::elem_type eT;
  
  const u32 N_mat = 1 + depth_lhs< glue_minus, glue_data<T1,T2,glue_minus> >::num;
  arma_extra_debug_print( arma_boost::format("N_mat = %d") % N_mat );


  if(N_mat == 2)
    {
    unwrap<T1> tmp1(X.A);
    unwrap<T2> tmp2(X.B);
    
    glue_minus::apply(out, tmp1.M, tmp2.M);
    }
  else
    {
    const basic_mat<eT>* ptrs[N_mat];
    bool                 del[N_mat];

    mat_ptrs<glue_minus, glue_data<T1,T2,glue_minus> >::get_ptrs(ptrs, del, X);
    //mat_ptrs_outcheck<glue_minus, glue_data<T1,T2,glue_minus> >::get_ptrs(ptrs, del, X, &out);

    for(u32 i=0; i<N_mat; ++i)  arma_extra_debug_print( arma_boost::format("ptrs[%d] = %x")  % i % ptrs[i] );
    for(u32 i=0; i<N_mat; ++i)  arma_extra_debug_print( arma_boost::format(" del[%d] = %d")  % i %  del[i] );

    const basic_mat<eT>& tmp_mat = *(ptrs[0]);
    
    for(u32 i=1; i<N_mat; ++i)
      {
      arma_debug_assert_same_size(tmp_mat, *(ptrs[i]), "matrix subtraction");
      }
  
    const u32 n_rows = ptrs[0]->n_rows;
    const u32 n_cols = ptrs[0]->n_cols;
  
    // no aliasing problem
    out.set_size(n_rows,n_cols);
    
    const u32 n_elem = ptrs[0]->n_elem;
    
    for(u32 j=0; j<n_elem; ++j)
      {
      eT acc = ptrs[0]->mem[j];
    
      for(u32 i=1; i<N_mat; ++i)
        {
        acc -= ptrs[i]->mem[j];
        }
    
      out[j] = acc;
      }

    for(u32 i=0; i<N_mat; ++i)
      {
      if(del[i] == true)
        {
        arma_extra_debug_print( arma_boost::format("delete ptrs[%d]") % i );
        delete ptrs[i];
        }
      }

    }
  }


//! Immediate out -= B
template<typename eT>
inline
void
glue_minus::apply_inplace(basic_mat<eT>& out, const basic_mat<eT>& B)
  {
  arma_extra_debug_sigprint();
  
  arma_debug_assert_same_size(out, B, "matrix subtraction");

        eT* out_mem = out.memptr();
  const eT* B_mem   = B.mem;
  
  const u32 n_elem  = out.n_elem;
  
  for(u32 i=0; i<n_elem; ++i)
    {
    out_mem[i] -= B_mem[i];
    }
    
  }



template<typename T1, typename op_type>
inline
void
glue_minus::apply_inplace(basic_mat<typename T1::elem_type>& out, const op_data<T1, op_type>& X)
  {
  arma_extra_debug_sigprint();
  
  typedef typename T1::elem_type eT;
  
  const basic_mat<eT> tmp(X);
  glue_minus::apply(out, out, tmp);
  }
  


template<typename T1, typename T2, typename glue_type>
inline
void
glue_minus::apply_inplace(basic_mat<typename T1::elem_type>& out, const glue_data<T1, T2, glue_type>& X)
  {
  arma_extra_debug_sigprint();
  
  typedef typename T1::elem_type eT;
  
  out = out - X;
  }



//
// matrix subtraction with different element types

template<typename eT1, typename eT2>
inline
void
glue_minus::apply_mixed(basic_mat<typename promote_type<eT1,eT2>::result>& out, const basic_mat<eT1>& X, const basic_mat<eT2>& Y)
  {
  arma_extra_debug_sigprint();
  
  typedef typename promote_type<eT1,eT2>::result out_eT;
  
  arma_debug_assert_same_size(X,Y, "matrix subtraction");
  
  out.set_size(X.n_rows, X.n_cols);
  
        out_eT* out_mem = out.memptr();
  const eT1*    X_mem   = X.mem;
  const eT2*    Y_mem   = Y.mem;
  
  const u32 n_elem = out.n_elem;
  
  for(u32 i=0; i<n_elem; ++i)
    {
    out_mem[i] = upgrade_val<eT1,eT2>::apply(X_mem[i]) - upgrade_val<eT1,eT2>::apply(Y_mem[i]);
    }
  }



//
// glue_minus_diag


template<typename T1, typename T2>
inline
void
glue_minus_diag::apply(basic_mat<typename T1::elem_type>& out, const T1& A_orig, const op_data<T2,op_diagmat>& B_orig)
  {
  arma_extra_debug_sigprint();
  
  isnt_same_type<typename T1::elem_type, typename T2::elem_type>::check();
  
  const unwrap<T1> tmp1(A_orig);
  const unwrap<T2> tmp2(B_orig.m);
  
  typedef typename T1::elem_type eT;
  
  const basic_mat<eT>& A = tmp1.M;
  const basic_mat<eT>& B = tmp2.M;
  
  arma_debug_check( !B.is_square(), "glue_minus_diag::apply(): matrices must be square" );
  arma_debug_assert_same_size(A, B, "matrix subtraction");

  
  // no aliasing problem
  out.set_size(A.n_rows, A.n_cols);
  
  for(u32 col=0; col<A.n_cols; ++col)
    {
    for(u32 row=0; row<A.n_rows; ++row)
      {
      if(col != row)
        {
        out.at(row,col) = A.at(row,col);
        }
      else
        {
        out.at(row,col) = A.at(row,col) - B.at(row,col);
        }
      }
    }
  
  }



template<typename T1, typename T2>
inline
void
glue_minus_diag::apply(basic_mat<typename T1::elem_type>& out, const op_data<T1,op_diagmat>& A_orig, const T2& B_orig)
  {
  arma_extra_debug_sigprint();
  
  isnt_same_type<typename T1::elem_type, typename T2::elem_type>::check();
  
  const unwrap<T1> tmp1(A_orig.m);
  const unwrap<T2> tmp2(B_orig);
  
  typedef typename T1::elem_type eT;
  
  const basic_mat<eT>& A = tmp1.M;
  const basic_mat<eT>& B = tmp2.M;
  
  arma_debug_check( !A.is_square(), "glue_minus_diag::apply(): matrices must be square" );
  arma_debug_assert_same_size(A, B, "matrix subtraction");
  
  
  // no aliasing problem
  out.set_size(A.n_rows, A.n_cols);
  
  for(u32 col=0; col<A.n_cols; ++col)
    {
    for(u32 row=0; row<A.n_rows; ++row)
      {
      if(col != row)
        {
        out.at(row,col) = -B.at(row,col);
        }
      else
        {
        out.at(row,col) = A.at(row,col) - B.at(row,col);
        }
      }
    }
  
  }



template<typename T1, typename T2>
inline
void
glue_minus_diag::apply(basic_mat<typename T1::elem_type>& out, const op_data<T1,op_diagmat>& A_orig, const op_data<T2,op_diagmat>& B_orig)
  {
  arma_extra_debug_sigprint();
  
  isnt_same_type<typename T1::elem_type, typename T2::elem_type>::check();
  
  const unwrap<T1> tmp1(A_orig.m);
  const unwrap<T2> tmp2(B_orig.m);
  
  typedef typename T1::elem_type eT;
  
  const basic_mat<eT>& A = tmp1.M;
  const basic_mat<eT>& B = tmp2.M;
    
  arma_debug_check( !A.is_square(), "glue_minus_diag::apply(): matrices must be square" );
  arma_debug_assert_same_size(A, B, "matrix subtraction");
  
  
  if( (&out != &A) && (&out != &B) )
    {
    out.zeros(A.n_rows, A.n_cols);
    
    for(u32 i=0; i<A.n_rows; ++i)
      {
      out.at(i,i) = A.at(i,i) - B.at(i,i);
      }
    }
  else
    {
    for(u32 col=0; col<A.n_cols; ++col)
      {
      for(u32 row=0; row<A.n_rows; ++row)
        {
        if(col != row)
          {
          out.at(row,col) = 0.0;
          }
        else
          {
          out.at(row,col) = A.at(row,col) - B.at(row,col);
          }
        }
      }
    }
  
  }



template<typename T1, typename T2>
inline
void
glue_minus_diag::apply(basic_mat<typename T1::elem_type>& out, const glue_data<T1, op_data<T2,op_diagmat>, glue_minus_diag>& X)
  {
  glue_minus_diag::apply(out, X.A, X.B);
  }



template<typename T1, typename T2>
inline
void
glue_minus_diag::apply(basic_mat<typename T1::elem_type>& out, const glue_data< op_data<T1,op_diagmat>, T2, glue_minus_diag>& X)
  {
  glue_minus_diag::apply(out, X.A, X.B);
  }



template<typename T1, typename T2>
inline
void
glue_minus_diag::apply(basic_mat<typename T1::elem_type>& out, const glue_data<op_data<T1,op_diagmat>, op_data<T2,op_diagmat>, glue_minus_diag>& X)
  {
  glue_minus_diag::apply(out, X.A, X.B);
  }


//! @}
