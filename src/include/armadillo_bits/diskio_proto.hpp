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


//! \addtogroup diskio
//! @{


//! class for saving and loading matrices and fields
class diskio
  {
  public:
  
  template<typename eT>
  struct is_supported_type
    {
    static const bool value = 
      (
      false
      || is_u8<eT>::value
      || is_s8<eT>::value
      || is_u16<eT>::value
      || is_s16<eT>::value
      || is_u32<eT>::value
      || is_s32<eT>::value
      || is_float<eT>::value
      || is_double<eT>::value
      || is_complex_float<eT>::value
      || is_complex_double<eT>::value
      );
    };
  
  
  template<typename eT>
  inline static std::string gen_txt_header(const basic_mat<eT>& x);
  
  template<typename eT>
  inline static std::string gen_bin_header(const basic_mat<eT>& x);

  
  inline static char conv_to_hex_char(const u8 x);
  inline static void conv_to_hex(char* out, const u8 x);

  inline static std::string gen_tmp_name(const std::string& x);
  
  inline static void safe_rename(const std::string& old_name, const std::string& new_name);
  
  
  //
  // saving
  
  template<typename eT>
  inline static void save_raw_ascii  (const basic_mat<eT>& x, const std::string& name);
  
  template<typename eT>
  inline static void save_arma_ascii (const basic_mat<eT>& x, const std::string& name);
  
  template<typename eT>
  inline static void save_arma_ascii (const basic_mat<eT>& x, const std::string& name, std::ofstream& f);
  
  template<typename eT>
  inline static void save_arma_binary(const basic_mat<eT>& x, const std::string& name);
  
  template<typename eT>
  inline static void save_arma_binary(const basic_mat<eT>& x, const std::string& name, std::ofstream& f);
  
  template<typename eT>
  inline static void save_pgm_binary (const basic_mat<eT>& x, const std::string& name);
  
  template<typename T>
  inline static void save_pgm_binary (const basic_mat< std::complex<T> >& x, const std::string& name);
  
  
  //
  // loading
  
  template<typename eT>
  inline static void load_raw_ascii  (basic_mat<eT>& x, const std::string& name);
  
  template<typename eT>
  inline static void load_arma_ascii (basic_mat<eT>& x, const std::string& name);
  
  template<typename eT>
  inline static void load_arma_ascii (basic_mat<eT>& x, const std::string& name, std::ifstream& f);
  
  template<typename eT>
  inline static void load_arma_binary(basic_mat<eT>& x, const std::string& name);
  
  template<typename eT>
  inline static void load_arma_binary(basic_mat<eT>& x, const std::string& name, std::ifstream& f);
  
  template<typename eT>
  inline static void load_pgm_binary (basic_mat<eT>& x, const std::string& name);
  
  template<typename T>
  inline static void load_pgm_binary (basic_mat< std::complex<T> >& x, const std::string& name);
  
  template<typename eT>
  inline static void load_auto_detect(basic_mat<eT>& x, const std::string& name);
  
  inline static void pnm_skip_comments(std::fstream& f);
  
  
  // field saving and loading
  
  template<typename T1>
  inline static void save_field(const field<T1>& x, const std::string& name);
  
  template<typename T1>
  inline static void load_field(      field<T1>& x, const std::string& name);
  
  };


//! @}
