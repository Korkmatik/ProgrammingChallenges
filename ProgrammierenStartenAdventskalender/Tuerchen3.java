import java.util.Scanner;

public class Tuerchen3 {

    public static void main(String[] args) {
        
        /* 
         * Aufgabe: Method nimmt Binärzahl als String 
         * und konvertiert diese in Int
         */

        Scanner scanner = new Scanner(System.in);

        System.out.print("Binary Number: ");
        String input = scanner.nextLine();
        scanner.close();

        System.out.println("Integer: " + convertBinaryToInt(input));
    }

    public static int convertBinaryToInt(String binaryNumber) {
        int number = 0;

        int i = 0;
        for (; i < binaryNumber.length() - 1; i++) {
            number = (number + Character.getNumericValue(binaryNumber.charAt(i))) * 2;
        }
        
        return number + Character.getNumericValue(binaryNumber.charAt(i));
    }
}