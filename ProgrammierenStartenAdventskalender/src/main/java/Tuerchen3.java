public class Tuerchen3 {

    /* 
     * Aufgabe: Method nimmt Binärzahl als String 
     * und konvertiert diese in Int
     */

    public static int convertBinaryToInt(String binaryNumber) {
        int number = 0;

        int i = 0;
        for (; i < binaryNumber.length() - 1; i++) {
            number = (number + Character.getNumericValue(binaryNumber.charAt(i))) * 2;
        }
        
        return number + Character.getNumericValue(binaryNumber.charAt(i));
    }
}