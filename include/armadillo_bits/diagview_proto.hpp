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


//! Class for storing data required to extract and set the diagonals of a matrix
template<typename eT>
class diagview : public Base<eT, diagview<eT> >
  {
  public:   const Mat<eT>& m;
  protected:      Mat<eT>* m_ptr;
  
  public:
  
  typedef eT elem_type;
  typedef typename get_pod_type<elem_type>::pod_type pod_type;

  const u32 row_offset;
  const u32 col_offset;
  const u32 n_elem;
  
  
  protected:
  
  arma_inline diagview(const Mat<eT>& in_m, const u32 in_row_offset, const u32 in_col_offset, const u32 len);
  arma_inline diagview(      Mat<eT>& in_m, const u32 in_row_offset, const u32 in_col_offset, const u32 len);
  
  
  public:
  
  inline ~diagview();
  
  template<typename T1>
  inline void operator=(const Base<eT,T1>& x);
  
  inline void operator=(const diagview& x);
  
  arma_inline eT& operator[](const u32 i);
  arma_inline eT  operator[](const u32 i) const;
  
  arma_inline eT& operator()(const u32 i);
  arma_inline eT  operator()(const u32 i) const;

//   arma_inline double& at(const u32 in_n_row, in_n_col);
//   arma_inline double  at(const u32 in_n_row, in_n_col) const;
//    
//   arma_inline double& operator()(const u32 in_n_row, in_n_col);
//   arma_inline double  operator()(const u32 in_n_row, in_n_col) const;
  
  inline void fill(const eT val);
  inline void zeros();
  
  inline static void extract(Mat<eT>& out, const diagview& in);
  
  
  private:
  
  friend class Mat<eT>;
  diagview();
  //diagview(const diagview&);  // making this private causes an error under gcc 4.1/4.2, but not 4.3
  };


//! @}
