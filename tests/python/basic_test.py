import pytest
import dimredtools

def test_hello():
    resp = dimredtools.hello("Jeremy")
    assert resp == "Hello Jeremy"


def test_multiply():
    vec = dimredtools.VectorDouble([0.0, 1.0, 2.0])
    resp = dimredtools.multiply_by_scalar_double(vec, 2.0)
    assert list(resp) == [0.0, 2.0, 4.0]