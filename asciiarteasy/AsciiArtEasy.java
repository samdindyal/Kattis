import java.util.Scanner;

public class AsciiArtEasy {

    public static void main(String[] args){

        //Region 1: Setup
        Scanner sc = new Scanner(System.in);
        int ws = sc.nextInt();
        int hs = sc.nextInt();
        int wt = sc.nextInt();
        int ht = sc.nextInt();
        sc.nextLine();//Consume the newline after the 4 ints

        //Region 2: Reading input
        String[] search = new String[hs];
        String[] template = new String[ht];

        for (int i = 0; i < hs; i++) {
            search[i]= sc.nextLine();
        }
        for (int i = 0; i < ht; i++) {
            template[i] = sc.nextLine();
        }

       int index, x = 0;

       for (int i = 0; i < hs; i++)
       {
            if ((x = search[i].indexOf(template[x])) == -1)
                x = 0;
            else if (x < ht -1)
                x = (x+1) % ht;
            else
            {
                System.out.println(x + " " + i);
                System.exit(0);
            }
       }
        System.out.println("no match");
    }
}