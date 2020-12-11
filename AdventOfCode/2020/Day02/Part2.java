import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Part2 {
    public static void main(String[] args) throws FileNotFoundException {
        
        File inputFile = new File("input");
        Scanner scanner = new Scanner(inputFile);

        int valid = 0;
        while (scanner.hasNextLine()) {
            String input = scanner.nextLine();
            var parts = input.split(" ");

            char character = parts[1].charAt(0);

            String password = parts[2];

            var positionParts = parts[0].split("-");
            int firstPosition = Integer.parseInt(positionParts[0]) - 1;
            int secondPosition = Integer.parseInt(positionParts[1]) - 1;

            if (
                (password.charAt(firstPosition) == character && password.charAt(secondPosition) != character) ||
                (password.charAt(firstPosition) != character && password.charAt(secondPosition) == character)
            ) {
                valid++;
            }
        }

        scanner.close();

        System.out.println("Valid passwords: " + valid);
    }
}
