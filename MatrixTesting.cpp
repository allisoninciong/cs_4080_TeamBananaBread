// MatrixTesting.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <algorithm> 
#include <chrono> 
#include <iostream> 

using namespace std;
using namespace std::chrono;

#define N 1024 // base num

void intMatrix();
void floatMatrix();
void mainMatrix();

int main() {
   cout << "Enter a (int*float), b (int*int), or c(float*float): ";
   char x;
   cin >> x;

   switch (x) {
   case 'a':
      mainMatrix();
      break;
   case 'b':
      intMatrix();
      break;
   case 'c':
      floatMatrix();
      break;
   default:
      cout << "Wrong number given" << endl;
   }

   return 0;
}

void intMatrix()
{
   for (int loop = 0; loop < 10; loop++) {

      // initialize random seed
      srand(time(NULL));

      int** arrayInt1 = new int*[N];
      for (int i = 0; i < N; i++)
         arrayInt1[i] = new int[N];

      int** arrayInt2 = new int*[N];
      for (int i = 0; i < N; i++)
         arrayInt2[i] = new int[N];

      int** finalArrayInt = new int*[N];
      for (int i = 0; i < N; i++)
         finalArrayInt[i] = new int[N];

      // filling the first array
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < N; ++j)
            arrayInt1[i][j] = rand() % 10;
      }

      // filling the second array
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            arrayInt2[i][j] = rand() % 10;
         }
      }

      auto start = high_resolution_clock::now();

      // multiplying both arrays via iteration
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            finalArrayInt[i][j] = 0;
            for (int k = 0; k < N; k++) {
               finalArrayInt[i][j] += arrayInt1[i][k] * arrayInt2[k][j];
            }
            //cout << finalArray[i][j] << " ";
         }
         //cout << "\n";
      }


      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << duration.count() << " microseconds";
      if (loop <= 9)
         std::cout << " + ";
      delete[] arrayInt1, arrayInt2, finalArrayInt;
   }
}

void floatMatrix()
{
   for (int loop = 0; loop < 10; loop++) {

      // initialize random seed
      srand(time(NULL));

      int** array1 = new int*[N];
      for (int i = 0; i < N; i++)
         array1[i] = new int[N];

      int** array2 = new int*[N];
      for (int i = 0; i < N; i++)
         array2[i] = new int[N];

      int** finalArray = new int*[N];
      for (int i = 0; i < N; i++)
         finalArray[i] = new int[N];

      // filling the first array
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < N; ++j)
            array1[i][j] = rand() % 10;
      }

      // filling the second array
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            array2[i][j] = rand() % 10;
         }
      }

      auto start = high_resolution_clock::now();

      // multiplying both arrays via iteration
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            finalArray[i][j] = 0;
            for (int k = 0; k < N; k++) {
               finalArray[i][j] += array1[i][k] * array2[k][j];
            }
            //cout << finalArray[i][j] << " ";
         }
         //cout << "\n";
      }

      auto stop = high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<microseconds>(stop - start);
      std::cout << duration.count() << " microseconds";
      if (loop <= 9)
         std::cout << " + ";
      delete[] array1, array2, finalArray;
   }
}

void mainMatrix()
{
   for (int loop = 0; loop < 10; loop++) {

      // initialize random seed
      srand(time(NULL));

      int** array1 = new int*[N];
      for (int i = 0; i < N; i++)
         array1[i] = new int[N];

      float** array2 = new float*[N];
      for (int i = 0; i < N; i++)
         array2[i] = new float[N];

      float** finalArray = new float*[N];
      for (int i = 0; i < N; i++)
         finalArray[i] = new float[N];

      // filling the first array
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < N; ++j)
            array1[i][j] = rand() % 10;
      }

      // filling the second array
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            array2[i][j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
         }
      }

      auto start = high_resolution_clock::now();

      // multiplying both arrays via iteration
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            finalArray[i][j] = 0;
            for (int k = 0; k < N; k++) {
               finalArray[i][j] += array1[i][k] * array2[k][j];
            }
            //cout << finalArray[i][j] << " ";
         }
         //cout << "\n";
      }

      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << duration.count() << " microseconds";
      if (loop <= 9)
         std::cout << " + ";
      delete[] array1, array2, finalArray;
   }
}