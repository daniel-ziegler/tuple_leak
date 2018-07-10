#include <cassert>
#include <iostream>
#include <random>

#include <pybind11/pybind11.h>

#define XTENSOR_ENABLE_ASSERT
#include "xtensor/xarray.hpp"
#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pytensor.hpp"


namespace py = pybind11;

// This one is fine
void pytuple() {
		xt::pytensor<float, 1> ones = xt::ones<float>({10});
    py::make_tuple(ones);
}

// This one leaks!
void stltuple() {
		xt::pytensor<float, 1> ones = xt::ones<float>({10});
    std::tuple<xt::pytensor<float, 1>> tup(ones);
}


PYBIND11_MODULE(tuple_fun, m) {
    xt::import_numpy();
    m.def("pytuple", &pytuple);
    m.def("stltuple", &stltuple);
}
