import java.io.File;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) throws Exception {
        
        File input = new File("input");
        Scanner scanner = new Scanner(input);
        scanner.useDelimiter("\n\n"); 

        String[] mustHaveFields = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };
        int numberNotValid = 0;
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

            for (int i = 0; i < mustHaveFields.length; i++) {
                String key = mustHaveFields[i];
                System.out.println("Checking key: " + key);
                boolean match = false;
                for (int j = 0; j < keys.length; j++) {
                    if (key.equals(mustHaveFields[j])) {
                        match = true;
                        break;
                    }
                }

                if (!match) {
                    numberNotValid++;
                    break;
                }

            }

            System.out.println("-------------------------------------------------------");
        }

        scanner.close();

        System.out.println("Valid: " + (numberPassports - numberNotValid));
    }

}