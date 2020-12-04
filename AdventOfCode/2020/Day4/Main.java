import java.io.File;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) throws Exception {
        
        File input = new File("input");
        Scanner scanner = new Scanner(input);
        scanner.useDelimiter("\n\n"); 

        String[] mustHaveFields = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };
        int numberValid = 0;
        int numberPassports = 0;
        while (scanner.hasNext()) {
            String passport = scanner.next();
            numberPassports++;

            System.out.println("Passport: " +  passport);
            System.out.println();

            String[] fieldsValues = passport.split("(\n| )");
            System.out.println(fieldsValues.length);

            String[] keys = new String[fieldsValues.length];
            for (int i = 0; i < fieldsValues.length; i++) {
                keys[i] = fieldsValues[i].split(":")[0];
                System.out.println("Key: " + keys[i]);
            }

            if (keys.length == 8) {
                numberValid++;
            } else if (keys.length == 7) {
                boolean valid = true;
                for (int i = 0; i < keys.length; i++) {
                    if (keys[i].contains("cid")) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    numberValid++;
                }
            }

            System.out.println("-------------------------------------------------------");
        }

        scanner.close();

        System.out.println("Valid: " + numberValid);
    }

}