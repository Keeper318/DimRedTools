import pytest
from sklearn.datasets import load_digits
from dimredtools import MDS
from numpy.testing import assert_equal

def test_mds():
    X, _ = load_digits(return_X_y=True)
    embedding = MDS(n_components=2)
    X_transformed = embedding.fit_transform(X[:100])
    assert_equal(X_transformed.shape, (100, 2))
