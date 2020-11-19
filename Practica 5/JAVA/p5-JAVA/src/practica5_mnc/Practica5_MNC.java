package practica5_mnc;

import java.util.Random;
import org.ejml.simple.SimpleMatrix;

public class Practica5_MNC {

    public static void main(String[] args) {
        int min = 2;
        int max = 500;
        int nOps = 100;
        double [] timesOps = new double[max];
        timesOps[0] = 0; timesOps[1] = 0;
        long start;
        long end;
        Random rand = new Random();         
        
        for (int i = min; i <= max; i++){
            start = System.nanoTime();
            for (int j = 0; j < nOps; j++){
                SimpleMatrix matRes = generateMatrix(i, i, rand).mult(generateMatrix(i, i, rand));                
            }
            end = System.nanoTime();
            timesOps[i-1] = ((end-start)/1e9)/nOps;
            System.out.println("Matrix with dimension [" + i + "x" + i + "], time in seconds:" + timesOps[i-1]);
        }
    }
    
    public static SimpleMatrix generateMatrix(int m, int n, Random rand){
        return SimpleMatrix.random_DDRM(m, n, 0.1, 1.0, rand);        
    }  
    
    public static void printMatrix(SimpleMatrix mat){
        System.out.println("Matrix with rows=" + mat.numRows() + " and cols=" + mat.numCols());
        for (int i = 0; i < mat.numRows(); i++) {
            for (int j = 0; j < mat.numCols(); j++) {
                System.out.print(mat.get(i, j) + " ");                
            }
            System.out.println();
        }
        System.out.println("\n");
    }
}
