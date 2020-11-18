import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String first = scanner.nextLine();
        String second = scanner.nextLine();
        scanner.close();

        String output = "";
        for (int i = 0; i < first.length(); i++) {
            output += first.charAt(i) == second.charAt(i) ? '0' : '1';
        }

        System.out.println(output);
    }
}