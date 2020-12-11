import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Main {

    public static void main(String[] args) throws FileNotFoundException {
        File inputFile = new File("input");
        Scanner scanner = new Scanner(inputFile);

        int numberValid = 0;

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");

            char character = parts[1].charAt(0); // Getting the character that we should check

            // Getting the min and max value
            String[] minMaxParts = parts[0].split("-");
            int min = Integer.parseInt(minMaxParts[0]);
            int max = Integer.parseInt(minMaxParts[1]);

            String password = parts[2]; // Getting the password

            int occurences = 0;
            for (int i = 0; i < password.length(); i++) {
                if (password.charAt(i) == character) {
                    occurences += 1;
                }
            }

            if (min <= occurences && max >= occurences) {
                numberValid += 1;
            }
        }
        scanner.close();

        System.out.println("Number valid passwords: " + numberValid);
    }
}