import java.util.*;

//int to float
//
public class MatrixMult {

    public static void main(String[] args) throws Exception {
        long startTime = 0;
        long endTime = 0;
        double tempTimeElapsed = 0;
        double timeElapsed = 0;

        Random rand = new Random();
        int nxtRandom = 10; // Numbers will be between 0 and 10
        Scanner sc = new Scanner(System.in);
        int n = 4; // n represents matrix rows + columns
        System.out.print("Enter a number (higher than 0) for the size your matrix: ");
        do {
            try {
                n = sc.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Enter a number (higher than 0) for your matrix: ");
            }
            sc.nextLine();
        } while (n <= 0);

        if (n == 1) {
            int firstNum, secondNum;
            System.out.println("Enter a number for the first matrix: ");
            firstNum = sc.nextInt();
            System.out.println("Enter a number for the second matrix: ");
            secondNum = sc.nextInt();
            System.out.println(firstNum * secondNum);
            System.exit(0);
        }

        int[][] array1 = new int[n][n];
        int[][] array2 = new int[n][n];
        int[][] finalArray = new int[n][n];

        int counter = 0;

        while (counter < 5) {
            System.out.println(counter);
            // filling the first array
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    array1[i][j] = rand.nextInt(nxtRandom);
            }

            // filling the second array
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    array2[i][j] = rand.nextInt(nxtRandom);
            }

            startTime = System.currentTimeMillis();
            // multiplying both arrays via the classic way
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        finalArray[i][j] += array1[i][k] * (array2[k][j]);
                    }
                }
            }

            endTime = System.currentTimeMillis();
            tempTimeElapsed = endTime - startTime;
            timeElapsed = timeElapsed + tempTimeElapsed;
            counter++;
        }

        /**
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    finalArray[i][j] += array1[i][k] * array2[k][j];
                }
                //System.out.print(finalArray[i][j] + " ");
            }
            //System.out.println();
        }
         **/

        sc.close();
        timeElapsed = ((timeElapsed) / 1000) / 5;
        System.out.println("Runtime: " + timeElapsed + " s");
    }
}