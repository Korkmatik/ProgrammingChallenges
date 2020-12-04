import java.util.Stack;

public class Tuerchen2 {
    
    /*
     * Aufgabe: Erstelle eine Methode, welche eine Dezimalzahl annimmt
     * und diesen in eine binärzahl umwandelt (String)
     */

    public static String decimalToBinary(int number) {
        Stack<Character> binaryNumbers = new Stack<Character>();

        do {
            char remainder = (char)((number % 2) + '0');
            binaryNumbers.push(remainder);

            number /= 2;
        } while(number != 0);

        String binaryNumber = "";
        while (!binaryNumbers.isEmpty()) {
            binaryNumber += binaryNumbers.pop();
        }

        return binaryNumber;
    }
}
