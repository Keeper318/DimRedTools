#ifndef DIMREDTOOLS_INCLUDE_DIMREDTOOLS_DIMREDTOOLS_HPP_
#define DIMREDTOOLS_INCLUDE_DIMREDTOOLS_DIMREDTOOLS_HPP_

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

namespace dim_red_tools {

/**
 * \brief Get version of DRT
 *
 * \return std::string
 */
std::string getDimRedToolsVersion();

/**
 * \brief Says hello with a name
 *
 * \param name
 * \return std::string
 */
std::string hello(std::string& name);

/**
 * \brief Multiplies a generic array by a scalar
 *
 * \tparam T
 * \param vec
 * \param scalar
 * \return std::vector<T>
 */
template <typename T>
std::vector<T> multiplyByScalar(std::vector<T>& vec, T scalar);

}  // namespace dim_red_tools

#endif
