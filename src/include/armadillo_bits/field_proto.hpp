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


//! \addtogroup field
//! @{



//! A lightweight 2D container for abitrary objects
//! (the objects must have a copy constructor)

template<typename oT>
class field
  {
  public:
  
  typedef oT object_type;
  
  const u32 n_rows;
  const u32 n_cols;  
  const u32 n_elem;
  
  
  private:
  
  u32  pad;
  oT** mem;       //!< pointer to memory used by the object
  oT*  mem_local[ 16 ];
  //!< Internal memory, allocated on the stack.
  //!< Designed to avoid calling the 'new' operator for small amounts of memory, resulting in considerable speedups.
  //!< Memory is allocated, via the 'new' operator, only if required.
  
  
  public:
  
  inline ~field();
  inline  field();
  
  inline                  field(const field& x);
  inline const field& operator=(const field& x);
  
  inline                  field(const subview_field<oT>& x);
  inline const field& operator=(const subview_field<oT>& x);
  
  inline explicit field(const u32 n_elem_in);
  inline          field(const u32 n_rows_in, const u32 n_cols_in);
  
  inline void set_size(const u32 n_obj_in);
  inline void set_size(const u32 n_rows_in, const u32 n_cols_in);
  
  inline       oT& operator[](const u32 i);
  inline const oT& operator[](const u32 i) const;
  
  inline       oT& operator()(const u32 i);
  inline const oT& operator()(const u32 i) const;
  
  inline       oT&         at(const u32 row, const u32 col);
  inline const oT&         at(const u32 row, const u32 col) const;
  
  inline       oT& operator()(const u32 row, const u32 col);
  inline const oT& operator()(const u32 row, const u32 col) const;
  
  inline       subview_field<oT> row(const u32 row_num);
  inline const subview_field<oT> row(const u32 row_num) const;
  
  inline       subview_field<oT> col(const u32 col_num);
  inline const subview_field<oT> col(const u32 col_num) const;
  
  inline       subview_field<oT> rows(const u32 in_row1, const u32 in_row2);
  inline const subview_field<oT> rows(const u32 in_row1, const u32 in_row2) const;
  
  inline       subview_field<oT> cols(const u32 in_col1, const u32 in_col2);
  inline const subview_field<oT> cols(const u32 in_col1, const u32 in_col2) const;
  
  inline       subview_field<oT> subfield(const u32 in_row1, const u32 in_col1, const u32 in_row2, const u32 in_col2);
  inline const subview_field<oT> subfield(const u32 in_row1, const u32 in_col1, const u32 in_row2, const u32 in_col2) const;
  
  inline void print(const std::string extra_text = "") const;
  
  inline void fill(const oT& x);
  
  inline void reset();
  inline void reset_objects();
  
  inline void save(const std::string name) const;
  inline void load(const std::string name);
  
  
  private:
  
  inline void init(const field<oT>& x);
  inline void init(const u32 n_rows_in, const u32 n_cols_in);
  
  inline void delete_objects();
  inline void create_objects();
  
  friend class field_aux;
  friend class subview_field<oT>;
  };



class field_aux
  {
  public:
  
  template<typename oT>
  inline static void reset_objects(field< oT               >& x);
  
  template<typename eT>
  inline static void reset_objects(field< basic_mat<eT>    >& x);
  
  template<typename eT>
  inline static void reset_objects(field< basic_colvec<eT> >& x);
  
  template<typename eT>
  inline static void reset_objects(field< basic_rowvec<eT> >& x);
  };


//! @}
