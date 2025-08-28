from setuptools import setup, Extension

# Define the module extension
module_extension = Extension(
    'calculator',  # Module name
    sources=['calculator.c'],  # C source files
)

# Setup configuration
setup(
    name='calculator',
    version='1.0',
    description='My Python Calculator Module',
    ext_modules=[module_extension],
    install_requires=[
        'setuptools>=58.0.0',
    ],
)