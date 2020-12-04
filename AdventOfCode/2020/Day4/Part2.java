import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Part2 {
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

            String[] fieldsValues = passport.split("(\n| )");

            HashMap<String, String> keys = new HashMap<>();
            for (int i = 0; i < fieldsValues.length; i++) {
                String[] splitted = fieldsValues[i].split(":");
                keys.put(splitted[0], splitted[1]);
            }

            Iterator it = keys.keySet().iterator();
            if (keys.size() == 8) {
                
                boolean valid = true;
                while (it.hasNext()) {
                    String k = (String) it.next();
                    if (!isValid(k, keys.get(k))) {
                        //System.out.println("not valid: " + k + " " + keys.get(k));
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    numberValid++;
                } else {
                    //System.out.println("Not valid: " + passport);
                }
                
            } else if (keys.size() == 7) {
                boolean valid = true;
                List<String> ks = new ArrayList<>();
                while (it.hasNext()) {
                    String key = (String) it.next();
                    ks.add(key);
                    if (key.equals("cid")) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    for (int i = 0; i < ks.size(); i++) {
                        if (!isValid(ks.get(i), keys.get(ks.get(i)))) {
                            //System.out.println("Not valid: " + ks.get(i) + " " + keys.get(ks.get(i)));

                            valid = false;
                            break;
                        }
                    }
                }

                if (valid) {
                    numberValid++;
                }else {
                    //System.out.println("Not valid: " + passport);
                }
            }
        }

        scanner.close();

        System.out.println("Valid: " + numberValid);
    }

    public static boolean isValid(String key, String value) {
        int v;

        //System.out.println("key: " + key);

        boolean ret;
        switch(key) {
            case "byr":
                v = Integer.parseInt(value);
                ret = (v >= 1920) && (v <= 2002);
                return ret;
            case "iyr":
                v = Integer.parseInt(value);
                ret = (v >= 2010) && (v <= 2020);
                return ret;
            case "eyr":
                v = Integer.parseInt(value);
                return (v >= 2020) && (v <= 2030);
            case "hgt":
                if (value.contains("cm")) {
                    value = value.replace("cm", "");
                    v = Integer.parseInt(value);
                    return (v >= 150) && (v <= 193);
                } else if (value.contains("in")) {
                    value = value.replace("in", "");
                    v = Integer.parseInt(value);
                    return (v >= 59) && (v <= 76);
                }
                return false;
            case "hcl":
                Pattern pattern = Pattern.compile("#[0-9a-f]{6}");
                Matcher matcher = pattern.matcher(value);
                ret = matcher.find();
                if (ret) {
                    //System.out.println("valid hcl: " + value);
                }
                return ret;
            case "ecl":
                String[] validValues = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                ret = false;
                for (int i = 0; i < validValues.length; i++) {
                    if (validValues[i].equals(value)) {
                        ret = true;
                        break;
                    }                
                }

                return ret;
            case "pid":
                if (value.length() != 9) return false;
                Pattern pattern2 = Pattern.compile("0*[0-9]+{9}");
                ret = pattern2.matcher(value).find();
                if (ret) {
                    System.out.println("valid pid: " + value);
                }
                return ret;
            case "cid":
                return true;
            default:
                return false;
        }
    }
}
