#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include "DimRedTools/CoverTree.hpp"

namespace py = pybind11;
using py::literals::operator""_a;
using dim_red::Matrix;
using dim_red::NearestNeighbors;
typedef std::pair<Eigen::RowVectorXd, Eigen::RowVectorXd> VectorPair;

namespace pybind11 {
namespace detail {

/*template <typename T, typename Class>
void bindDefaultConstructor(Class& cl) {
    cl.def(py::init([]() { return new T(); }), "Default constructor");
}

template <typename T, typename Class>
void bindCopyFunctions(Class& cl) {
    cl.def(py::init([](const T& cp) { return new T(cp); }), "Copy constructor");
    cl.def("__copy__", [](T& v) { return T(v); });
    cl.def("__deepcopy__", [](T& v, py::dict& memo) { return T(v); });
}*/

}  // namespace detail
}  // namespace pybind11

class PyNearestNeighbors : public NearestNeighbors {
public:
    using NearestNeighbors::NearestNeighbors;

    std::pair<Eigen::RowVectorXd, Eigen::RowVectorXd> query(const Eigen::Ref<const Matrix> &point,
                                                            int k,
                                                            bool sort_results) const override {
        PYBIND11_OVERRIDE_PURE(VectorPair, NearestNeighbors, query, point, k, sort_results);
    }
    std::pair<Eigen::RowVectorXd, Eigen::RowVectorXd> queryRadius(
        const Eigen::Ref<const Matrix> &point, double radius, bool sort_results) const override {
        PYBIND11_OVERRIDE_PURE_NAME(VectorPair, NearestNeighbors, "query_radius", queryRadius,
                                    point, radius, sort_results);
    }
};
