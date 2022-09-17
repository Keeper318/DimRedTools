import pytest
import numpy as np
from dimredtools import MDS, Isomap
from numpy.testing import assert_equal

def run(model, n_components):
    X = np.random.uniform(size=(1000, 10))
    assert_equal(model.fit_transform(X[:100]).shape, (100, n_components))


def test_mds():
    run(MDS(), 2)


def test_isomap():
    run(Isomap(), 2)
