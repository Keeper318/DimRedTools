#include "doctest/doctest.h"
#include "DimRedTools/DimRedTools.hpp"
#include <vector>

template <typename T>
int checkArray(std::vector<T>& a, std::vector<T>& b) {
    for (size_t i = 0; i < a.size(); i++) {
        auto result = a[i] == doctest::Approx(b[i]);
        if (!result) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

TEST_SUITE("VectorMath") {
    TEST_CASE("Doubles") {
        std::vector<double> input{0.0, 1.0, 2.0};
        std::vector<double> expected{0.0, 2.0, 4.0};
        double scalar = 2.0;
        auto output = dim_red_tools::multiplyByScalar(input, scalar);

        SUBCASE("SameLength") {
            CHECK_EQ(output.size(), output.size());
        }
        SUBCASE("CorrectOutput") {
            auto val = checkArray(output, expected);
            CHECK_MESSAGE((val == -1), "Vectors are not equal");
        }
    }
}

TEST_SUITE("Hello") {
    TEST_CASE("Name") {
        std::string input = "Jeremy";
        std::string output = dim_red_tools::hello(input);
        std::string expected = "Hello Jeremy";
        CHECK_EQ(output, expected);
    }
}
