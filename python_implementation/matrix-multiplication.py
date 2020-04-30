# -*- coding: utf-8 -*-
"""
Created on Wed Apr 29 16:22:17 2020

@author: kevin
"""
import random

#creates a matrix of shape (numRows, numColumns)
def create_matrix(numRows, numColumns, datatype="int"):
    if(datatype == "int"):
        matrix = [[random.randint(0,10) for i in range(numColumns)] for j in range(numRows)]
    elif(datatype == "float"):
         matrix = [[random.uniform(0.0,1.0) for i in range(numColumns)] for j in range(numRows)]
    else:
        matrix = None
    return matrix



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



