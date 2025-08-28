from setuptools import setup
from Cython.Build import cythonize

setup(
    name='matrix',
    version='1.0',
    description='My Python Matrix Module',
    ext_modules=cythonize("multiply.pyx"),
)
