# -*- coding: utf-8 -*-
"""
Created on Wed Apr 29 16:22:17 2020

@author: kevin
"""
import random
import time
import csv

#creates a matrix of shape (numRows, numColumns)
def create_matrix(numRows, numColumns, datatype="int"):
    if(datatype == "int"):
        matrix = [[random.randint(0,10) for i in range(numColumns)] for j in range(numRows)]
    elif(datatype == "float"):
         matrix = [[random.uniform(0.0,1.0) for i in range(numColumns)] for j in range(numRows)]
    else:
        matrix = None
    return matrix


# returns the product of the matrix multiplication of the two parameters
def multiply_matrix(matrix1, matrix2):
    matrix1NumRows = len(matrix1)
    matrix1NumColumns = len(matrix1[0])
    matrix2NumRows = len(matrix2)
    matrix2NumColumns = len(matrix2[0])
    
    if(matrix1NumColumns != matrix2NumRows):
        raise ValueError()
    
    resultMatrix = []
    
    for i in range(matrix1NumRows):
        row = []
        for j in range(matrix2NumColumns):
            val = 0
            for k in range(matrix1NumColumns):
                val += matrix1[i][k] * matrix2[k][j]
            row.append(val)
        resultMatrix.append(row)
    return resultMatrix

#returns time to perform a multiplication of two square matrices of size
def time_matmul(datatype1, datatype2, size):
    mat1 = create_matrix(size, size, datatype1)
    mat2 = create_matrix(size, size, datatype2)
    
    timing = time.perf_counter()
    final_mat = multiply_matrix(mat1, mat2)
    return time.perf_counter() - timing


#returns avg time for numMultiplications number of  matrix multiplications
def time_many_matmul(datatype1, datatype2, size, numMultiplications):
    total = 0
    for i in range(numMultiplications):
        total += time_matmul(datatype1, datatype2, size)
    return total / numMultiplications
    
#returns a list of avg times for numMultiplications number of matrix multiplications
#   for matrices of size (base * 2**i)
def time_many_sizes(datatype1, datatype2, numMultiplications, base=32, numOfSizes=6):
    result =[]
    for i in range(numOfSizes):
        result.append(time_many_matmul(datatype1, datatype2, (base * 2**i), numMultiplications))
    return result


result = {}

numMultiplications = 10

result["int_int"] = time_many_sizes("int", "int", numMultiplications)
result["float_float"] = time_many_sizes("float", "float", numMultiplications)
result["int_float"] = time_many_sizes("int", "float", numMultiplications)

file = open("python_data.csv", "w", newline ='')
writer = csv.writer(file)
for key, values in result.items():
    writer.writerow([key] + values)

file.close()
print(result)