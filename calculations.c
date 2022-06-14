#include "C:/Users/darkarp/AppData/Local/Programs/Python/Python310/include/Python.h"
#include "dict/headers/dict.h"
#include <stdlib.h>
#include <time.h>

static PyObject* method_factors(PyObject* self, PyObject* args) {
    int number = 0;
    int value_to_add = 0;

    // parse argument "number", k= unsigned long long without overflow check
    if (!PyArg_ParseTuple(args, "k", &number)) {
        return NULL;
    }

    PyObject* list = PyList_New(0);
    if (number % 2 == 0) {
        PyList_Append(list, Py_BuildValue("i", 2));
        number /= 2;
        while (number % 2 == 0) number /= 2;
    }
    for (int i = 3; i <= sqrt(number); i = i + 2) {
        while (number % i == 0) {
            number /= i;
            PyList_Append(list, Py_BuildValue("i", i));
        }
    }
    if (number > 2) PyList_Append(list, Py_BuildValue("i", number));
    return list;
}

static PyObject* method_generate_modulos(PyObject* self, PyObject* args) {
    PyObject* factors = NULL;
    int size = 0, max_iter = 0;
    // parse argument "number"
    // k= unsigned long long without overflow check
    // O= PyObject*
    if (!PyArg_ParseTuple(args, "Okk", &factors, &size, &max_iter)) {
        return NULL;
    }
    PyObject* list = PyList_New(0);
    uint64_t list_size = PyList_GET_SIZE(factors);
    for (int i = 0; i < max_iter;i++) {
        unsigned long long factor = PyLong_AsLong(PyList_GetItem(factors, rand() % list_size));
        PyList_Append(list, Py_BuildValue("i", (i * factor) % size));
    }
    return list;
}

static PyObject* method_unique_occurences(PyObject* self, PyObject* args) {
    PyObject* factors = NULL;
    int size = 0, max_iter = 0;
    // parse argument "number"
    // k= unsigned long long without overflow check
    // O= PyObject*
    if (!PyArg_ParseTuple(args, "Okk", &factors, &size, &max_iter)) {
        return NULL;
    }
    PyObject* list = PyList_New(0);
    uint64_t list_size = PyList_GET_SIZE(factors);
    for (int i = 0; i < max_iter;i++) {
        uint64_t factor = PyLong_AsLong(PyList_GetItem(factors, rand() % list_size));
        PyList_Append(list, Py_BuildValue("i", (i * factor) % size));
    }
    return list;
}

static PyMethodDef Calculations[] = {
    {"factors", method_factors, METH_VARARGS, "Number calculations"},
    {"generate_modulos", method_generate_modulos, METH_VARARGS, "Number calculations"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef calculations = {
    PyModuleDef_HEAD_INIT,
    "calculations",
    "Number calculations",
    -1,
    Calculations,
};

PyMODINIT_FUNC PyInit_calculations(void) {
    srand((unsigned int)time(0));
    return PyModule_Create(&calculations);
}