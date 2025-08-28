cdef class MatrixMultiplication:
    cdef int* matrix1
    cdef int* matrix2
    cdef int rows1
    cdef int cols1
    cdef int rows2
    cdef int cols2

    def __init__(self, matrix1, matrix2):
        self.matrix1 = &matrix1[0][0]
        self.matrix2 = &matrix2[0][0]
        self.rows1 = len(matrix1)
        self.cols1 = len(matrix1[0])
        self.rows2 = len(matrix2)
        self.cols2 = len(matrix2[0])

    def multiply(self) -> "int[:, :]":
        cdef int rows1 = self.rows1
        cdef int cols1 = self.cols1
        cdef int rows2 = self.rows2
        cdef int cols2 = self.cols2

        if cols1 != rows2:
            raise ValueError("Matrix dimensions are not compatible for multiplication")

        cdef int* result = <int*>PyMem_Malloc(sizeof(int) * rows1 * cols2)
        if result is NULL:
            raise MemoryError("Failed to allocate memory for the result matrix")

        cdef int[:, :] result_view = <int[:, :]>&result[0]
        cdef int i, j, k
        for i in range(rows1):
            for j in range(cols2):
                result_view[i, j] = 0
                for k in range(cols1):
                    result_view[i, j] += self.matrix1[i * cols1 + k] * self.matrix2[k * cols2 + j]

        return result_view[:rows1, :cols2]
