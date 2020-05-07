// MatrixTesting.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include <cmath>

using namespace std;
using namespace std::chrono;

const int NUM_TRIALS = 10;

void intMatrix(int N)
{
   long avgTime = 0;
   for (int loop = 0; loop < NUM_TRIALS; loop++) {

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
      avgTime += duration.count();
      delete[] arrayInt1, arrayInt2, finalArrayInt;
   }
   cout << avgTime / NUM_TRIALS;
}

void floatMatrix(int N)
{
   long avgTime = 0;
   for (int loop = 0; loop < NUM_TRIALS; loop++) {

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
      avgTime += duration.count();
      delete[] array1, array2, finalArray;
   }
   cout << avgTime / NUM_TRIALS;
}

void mainMatrix(int N)
{
   long avgTime = 0;
   for (int loop = 0; loop < NUM_TRIALS; loop++) {

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
      avgTime += duration.count();
      delete[] array1, array2, finalArray;
   }
   cout << avgTime / NUM_TRIALS;
}
void timeManySizes(int base, int numIterations)
{
   cout << "int_int,";
   for (int i = 0; i < numIterations; i++)
   {
      intMatrix(base * pow(2.0,i));
      if (i < numIterations-1)
      {
         cout << ",";
      }
   }
   cout << endl;
   cout << "float_float,";
   for (int i = 0; i < numIterations; i++)
   {
      floatMatrix(base * pow(2.0,i));
      if (i < numIterations-1)
      {
         cout << ",";
      }
   }
   cout << endl;
   cout << "int_float,";
   for (int i = 0; i < numIterations; i++)
   {
      intMatrix(base * pow(2.0,i));
      if (i < numIterations-1)
      {
         cout << ",";
      }
      
   }
   cout << endl;
}

int main() 
{
   timeManySizes(32, 6);
   system("pause");
   return 0;
}