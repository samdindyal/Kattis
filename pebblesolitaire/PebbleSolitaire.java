import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.HashMap;

public class PebbleSolitaire {

	private static HashMap<String, Integer> map;
	private static int min;

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(reader.readLine());
		String input;
		for (int i = 0; i < n; i++)
		{
			input = reader.readLine();
			min = input.length();
			map = new HashMap<String, Integer>();
			System.out.println(solve(input));
		}
	}

	private static int solve(String input) {

		if (map.containsKey(input))
			return map.get(input);

		int pebbleCount = 0;

			for (int i = 0; i < input.length(); i++)
				if (input.charAt(i) == 'o')
					pebbleCount++;
			min = Math.min(min, pebbleCount);

		if (pebbleCount > 1 && (input.contains("oo-") || input.contains("-oo")))
		{
			String str;
			for (int j = 1; j < input.length() - 1; j++)
			{
				if (input.charAt(j) == 'o' ) {
					if (input.charAt(j-1) == 'o' && input.charAt(j+1) == '-') {
						str = input.substring(0, j-1) + "--o" + input.substring(j+2, input.length());
						map.put(str, solve(str));
					}
					else if (input.charAt(j-1) == '-' && input.charAt(j+1) == 'o') {
						str = input.substring(0, j-1) + "o--" + input.substring(j+2, input.length());	
						map.put(str, solve(str));
					}
				}
			}

		}
		return min;
	}
}