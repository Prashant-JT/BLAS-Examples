package practica5_mnc;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ejml.simple.SimpleMatrix;

public class Practica5_MNC {

    public static void main(String[] args) {
        int min = 100;
        int max = 1000;
        int nOps = 100;
        double [] timesOps = new double[46];
        int cont = 0;
        long start;
        long end;
        Random rand = new Random();         
        
        for (int i = min; i <= max; i+=20){
            start = System.nanoTime();
            for (int j = 0; j < nOps; j++){
                SimpleMatrix matRes = generateMatrix(i, i, rand).mult(generateMatrix(i, i, rand));                
            }
            end = System.nanoTime();
            timesOps[cont] = ((end-start)/1e9)/nOps;
            System.out.println("Matrix with dimension [" + i + "x" + i + "], time in seconds:" + timesOps[cont]);
            cont++;
        }
        
        writeCSV(timesOps);
    }
    
    public static void writeCSV(double [] timesO){
        BufferedWriter br = null;
        try {
            br = new BufferedWriter(new FileWriter("Ejercicio5JAVA.csv"));
        } catch (IOException ex) {
            Logger.getLogger(Practica5_MNC.class.getName()).log(Level.SEVERE, null, ex);
        }
        StringBuilder sb = new StringBuilder();

        for (double element : timesO) {
            sb.append(element);
            sb.append(",");
        }
        
        sb.deleteCharAt(timesO.length-1);

        try {
            br.write(sb.toString());
            br.close();
        } catch (IOException ex) {
            Logger.getLogger(Practica5_MNC.class.getName()).log(Level.SEVERE, null, ex);
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
