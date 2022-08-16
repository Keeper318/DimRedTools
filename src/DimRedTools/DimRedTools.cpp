#include "DimRedTools/DimRedTools.hpp"

namespace dim_red_tools {

std::string hello(std::string& name) {
    return "Hello " + name;
}

template <typename T>
std::vector<T> multiplyByScalar(std::vector<T>& vec, T scalar) {
    std::vector<T> b;
    b.reserve(vec.size());

    std::transform(vec.begin(), vec.end(), std::back_inserter(b),
                   [scalar](auto& a_elem) { return a_elem * scalar; });

    return b;
}

// Forward declare specialization
// https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
template std::vector<double> multiplyByScalar<double>(std::vector<double>& vec, double scalar);
template std::vector<int> multiplyByScalar<int>(std::vector<int>& vec, int scalar);
template std::vector<size_t> multiplyByScalar<size_t>(std::vector<size_t>& vec, size_t scalar);

}  // namespace dim_red_tools
