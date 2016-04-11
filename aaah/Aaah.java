import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Aaah {
  public static void main(String[] args) throws Exception {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    System.out.println(reader.readLine().length() < reader.readLine().length() ? "no" : "go");
  }
}
