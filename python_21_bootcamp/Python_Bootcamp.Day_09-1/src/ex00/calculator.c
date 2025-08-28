#include <Python.h>

static PyObject* add_calculator(PyObject* self, PyObject* args) {
    PyObject *arg1, *arg2;
    
    // Parse the arguments as two objects
    if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
        return NULL;  // Failed to parse arguments
    }

    // Check if the first argument is an integer
    if (PyLong_Check(arg1)) {
        // Handle integer
        long a = PyLong_AsLong(arg1);
        long b = PyLong_AsLong(arg2);
        long result = a + b;
        return PyLong_FromLong(result);
    }

    // Check if the first argument is a float
    if (PyFloat_Check(arg1)) {
        // Handle float
        double a = PyFloat_AsDouble(arg1);
        double b = PyFloat_AsDouble(arg2);
        double result = a + b;
        return PyFloat_FromDouble(result);
    }

    // Invalid argument types
    PyErr_SetString(PyExc_TypeError, "Invalid argument types");
    return NULL;
}

static PyObject* sub_calculator(PyObject* self, PyObject* args) {
    PyObject *arg1, *arg2;
    
    // Parse the arguments as two objects
    if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
        return NULL;  // Failed to parse arguments
    }

    // Check if the first argument is an integer
    if (PyLong_Check(arg1)) {
        // Handle integer
        long a = PyLong_AsLong(arg1);
        long b = PyLong_AsLong(arg2);
        long result = a - b;
        return PyLong_FromLong(result);
    }

    // Check if the first argument is a float
    if (PyFloat_Check(arg1)) {
        // Handle float
        double a = PyFloat_AsDouble(arg1);
        double b = PyFloat_AsDouble(arg2);
        double result = a - b;
        return PyFloat_FromDouble(result);
    }

    // Invalid argument types
    PyErr_SetString(PyExc_TypeError, "Invalid argument types");
    return NULL;
}

static PyObject* mul_calculator(PyObject* self, PyObject* args) {
    PyObject *arg1, *arg2;
    
    // Parse the arguments as two objects
    if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
        return NULL;  // Failed to parse arguments
    }

    // Check if the first argument is an integer
    if (PyLong_Check(arg1)) {
        // Handle integer
        long a = PyLong_AsLong(arg1);
        long b = PyLong_AsLong(arg2);
        long result = a * b;
        return PyLong_FromLong(result);
    }

    // Check if the first argument is a float
    if (PyFloat_Check(arg1)) {
        // Handle float
        double a = PyFloat_AsDouble(arg1);
        double b = PyFloat_AsDouble(arg2);
        double result = a * b;
        return PyFloat_FromDouble(result);
    }

    // Invalid argument types
    PyErr_SetString(PyExc_TypeError, "Invalid argument types");
    return NULL;
}

static PyObject* div_calculator(PyObject* self, PyObject* args) {
    PyObject *arg1, *arg2;
    
    // Parse the arguments as two objects
    if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2))
        return NULL;  // Failed to parse arguments

    // Check if the first argument is an integer
    if (PyLong_Check(arg1)) {
        // Handle integer
        long a = PyLong_AsLong(arg1);
        long b = PyLong_AsLong(arg2);
        if (b == 0)
        {
            PyErr_SetString(PyExc_ZeroDivisionError, "Division by zero");
            return NULL;
        }
        long result = a / b;
        return PyLong_FromLong(result);
    }

    // Check if the first argument is a float
    if (PyFloat_Check(arg1))
    {
        // Handle float
        double a = PyFloat_AsDouble(arg1);
        double b = PyFloat_AsDouble(arg2);
        if (b == 0.0)
        {
            PyErr_SetString(PyExc_ZeroDivisionError, "Division by zero");
            return NULL;
        }
        double result = a / b;
        return PyFloat_FromDouble(result);
    }

    // Invalid argument types
    PyErr_SetString(PyExc_TypeError, "Invalid argument types");
    return NULL;
}


static PyMethodDef calculator_methods[] = {
    {"add", add_calculator, METH_VARARGS, "addition of two ints"},
    {"sub", sub_calculator, METH_VARARGS, "addition of two ints"},
    {"mul", mul_calculator, METH_VARARGS, "addition of two ints"},
    {"div", div_calculator, METH_VARARGS, "addition of two ints"},
    // Add more functions here
    {NULL, NULL, 0, NULL}  // Sentinel value marking the end of the methods array
};

static struct PyModuleDef calculator_module = {
    PyModuleDef_HEAD_INIT,
    "calculator",   // Module name
    "calculator module includes add, sub, mul, div",
    -1,
    calculator_methods
};

PyMODINIT_FUNC PyInit_calculator(void) {
    return PyModule_Create(&calculator_module);
}