import java.io.Console;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        
        Console console = System.console();

        int levels = Integer.parseInt(console.readLine());
        String[] littleXLevels = console.readLine().split(" ");
        String[] littleYLevels = console.readLine().split(" ");

        ArrayList<Integer> unique = new ArrayList<>();
        for (int i = 0; i < littleXLevels.length; i++) {
            Integer level = Integer.parseInt(littleXLevels[i]);
            if (!unique.contains(level)) {
                unique.add(level);
            }
        }

        for (int i = 0; i < littleYLevels.length; i++) {
            Integer level = Integer.parseInt(littleYLevels[i]);
            if (!unique.contains(level)) {
                unique.add(level);
            } 
        }
 
        for (Integer i = 1; i < levels + 1; i++) {
            if (!unique.contains(i)) {
                System.out.println("Oh, my keyboard!");
                return;
            }
        }

        System.out.println("I become the guy.");
    }
}