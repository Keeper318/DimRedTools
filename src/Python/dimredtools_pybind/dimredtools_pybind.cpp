#include "dimredtools_pybind/dimredtools_pybind.hpp"
#include "dimredtools_pybind/docstring/docstring.hpp"

using dim_red_tools::docstring::functionDocInject;

PYBIND11_MODULE(dimredtools_pybind, m) {
    m.doc() = "Python binding of DimRedTools";

    py::bind_vector<std::vector<double>>(m, "VectorDouble", py::buffer_protocol());
    py::bind_vector<std::vector<int>>(m, "VectorInt", py::buffer_protocol());
    py::bind_vector<std::vector<std::size_t>>(m, "VectorULongInt", py::buffer_protocol());

    m.def("hello", &dim_red_tools::hello, "name"_a, "Says hello to name");
    functionDocInject(m, "hello", {{"name", "The name to say hello with"}});

    // You *can* use function overload with same name, but python documentation doesn't support
    // function overload Here I choose to make multiple function with different names
    m.def("multiply_by_scalar_double", &dim_red_tools::multiplyByScalar<double>, "vec"_a,
          "scalar"_a, "Multiplies a double vector");
    m.def("multiply_by_scalar_int", &dim_red_tools::multiplyByScalar<int>, "vec"_a, "scalar"_a,
          "Multiplies an int vector");
    m.def("multiply_by_scalar_size_t", &dim_red_tools::multiplyByScalar<size_t>, "vec"_a,
          "scalar"_a, "Multiplies a size_t vector");
    functionDocInject(m, "multiply_by_scalar_double",
                                 {{"vec", "A list of double numbers "},
                                  {"scalar", "A scalar number to multiply the list by."}});
    functionDocInject(m, "multiply_by_scalar_int",
                                 {{"vec", "A list of int numbers "},
                                  {"scalar", "A scalar number to multiply the list by."}});
    functionDocInject(m, "multiply_by_scalar_size_t",
                                 {{"vec", "A list of size_t numbers "},
                                  {"scalar", "A scalar number to multiply the list by."}});

    m.def("get_dimredtools_version", &dim_red_tools::getDimRedToolsVersion,
          "Get DimRedTools Version");
    // Here's an example to overload, but the documentation is wonky
    // m.def("multiply_by_scalar", &DimRedTools::MultiplyByScalar<double>, "vec"_a, "scalar"_a,
    // "Multiplies a vector"); m.def("multiply_by_scalar", &DimRedTools::MultiplyByScalar<int>,
    // "vec"_a, "scalar"_a, "Multiplies a vector"); m.def("multiply_by_scalar",
    // &DimRedTools::MultiplyByScalar<size_t>, "vec"_a, "scalar"_a, "Multiplies a vector");
    // docstring::FunctionDocInject(
    //     m, "multiply_by_scalar",
    //     {{"vec", "A list of numbers (double, int, size_t)"}, {"scalar", "A scalar number to
    //     multiply the list by."}});
}