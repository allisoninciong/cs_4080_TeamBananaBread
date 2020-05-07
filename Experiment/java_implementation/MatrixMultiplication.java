import java.util.Random;

public class MatrixMultiplication 
{
	static final int NUM_TRIALS = 10;
	public static void main(String[] args)
	{
		System.out.println(timeManySizes("int", "int", 32, 6));
		System.out.println(timeManySizes("float", "float", 32, 6));
		System.out.println(timeManySizes("float", "int", 32, 6));
	}
	
	public static int[][] createIntMatrix(int size)
	{
		Random rand = new Random();
		int[][] array = new int[size][size];
		for (int i = 0; i < size; i++) 
		{
            for (int j = 0; j < size; j++)
                array[i][j] = rand.nextInt(10);
        }
		return array;
	}
	
	public static float[][] createFloatMatrix(int size)
	{
		Random rand = new Random();
		float[][] array = new float[size][size];
		for (int i = 0; i < size; i++) 
		{
            for (int j = 0; j < size; j++)
                array[i][j] = rand.nextFloat();
        }
		return array;
	}
	public static long timeMatMul(float[][] array1, int[][] array2, int size)
	{
		long startTime = System.nanoTime();
	    // multiplying both arrays via the classic way
		float finalArray[][] =  new float[size][size];
	    for (int i = 0; i < size; i++) {
	        for (int j = 0; j < size; j++) {
	            for (int k = 0; k < size; k++) {
	                finalArray[i][j] += array1[i][k] * (array2[k][j]);
	            }
	        }
	    }

	    long timeElapsed = System.nanoTime() - startTime;
	    return timeElapsed/1000;
	}
	public static long timeMatMul(float[][] array1, float[][] array2, int size)
	{
		long startTime = System.nanoTime();
	    // multiplying both arrays via the classic way
		float finalArray[][] =  new float[size][size];
	    for (int i = 0; i < size; i++) {
	        for (int j = 0; j < size; j++) {
	            for (int k = 0; k < size; k++) {
	                finalArray[i][j] += array1[i][k] * (array2[k][j]);
	            }
	        }
	    }

	    long timeElapsed = System.nanoTime() - startTime;
	    return timeElapsed/1000;
	}
	
	public static long timeMatMul(int[][] array1, int[][] array2, int size)
	{
		long startTime = System.nanoTime();
	    // multiplying both arrays via the classic way
		int finalArray[][] =  new int[size][size];
	    for (int i = 0; i < size; i++) {
	        for (int j = 0; j < size; j++) {
	            for (int k = 0; k < size; k++) {
	                finalArray[i][j] += array1[i][k] * (array2[k][j]);
	            }
	        }
	    }

	    long timeElapsed = System.nanoTime() - startTime;
	    return timeElapsed/1000;
	}
	public static long getAvgTime(String datatype1, String datatype2, int size)
	{
		if(datatype1.equalsIgnoreCase("int"))
		{
			long avgTime = 0;
			for(int trial = 0; trial < NUM_TRIALS; trial++)
			{
				int[][] array1= createIntMatrix(size);
				int[][] array2= createIntMatrix(size);
				
			    avgTime += timeMatMul(array1, array2, size);
			}
			return avgTime / NUM_TRIALS;
		}
		else if(datatype2.equalsIgnoreCase("float")) 
		{
			long avgTime = 0;
			for(int trial = 0; trial < NUM_TRIALS; trial++)
			{
				float[][] array1= createFloatMatrix(size);
				float[][] array2= createFloatMatrix(size);
				
			    avgTime += timeMatMul(array1, array2, size);
			}
			return avgTime / NUM_TRIALS;
		}
		else 
		{
			long avgTime = 0;
			for(int trial = 0; trial < NUM_TRIALS; trial++)
			{
				float[][] array1= createFloatMatrix(size);
				int[][] array2= createIntMatrix(size);
				
			    avgTime += timeMatMul(array1, array2, size);
			}
			return avgTime / NUM_TRIALS;
		}
	}
	public static String timeManySizes(String datatype1, String datatype2, int base, int numIterations)
	{
		String result = datatype1 + "_" + datatype2 + ",";
		for(int i = 0; i < numIterations; i++)
		{
			result += getAvgTime(datatype1, datatype2, (int)(base * Math.pow(2, i )));
			if(i < numIterations-1)
				result += ",";
		}
		return result;
	}
	
}
