import pytest
import dimredtools
import numpy as np
from numpy.testing import assert_equal, assert_allclose

def test_covertree():
    rng = np.random.RandomState(0)
    X = rng.random_sample((10, 3))
    tree = dimredtools.CoverTree(X)

    correct_indices = [0, 3, 1]
    correct_distances = [0., 0.19662693, 0.29473397]
    for distances, indices in (tree.query(X[0], k=3), tree.query_radius(X[0], r=0.3, sort_results=True)):
        assert_allclose(distances, correct_distances, rtol=1e-05, atol=1e-07)
        assert_equal(indices, correct_indices)
