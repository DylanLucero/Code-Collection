import java.util.Scanner;
public class Company {
    public static void main(String [] args){
        Scanner scnr = new Scanner(System.in);

        Employee[] employees = new Employee[5];

        boolean menu = true;

        while (menu = true){
            System.out.println("Main Menu");
            System.out.println("a. Add an Employee");
            System.out.println("b. List all Employees");
            System.out.println("c. Give an Employee a raise");
            System.out.println("d. Give Paychecks");
            System.out.println("e. Change someone’s hours");
            System.out.println("f. Quit");

            char userChoice = scnr.nextLine().charAt(0);

            if(userChoice == 'a'){

            }else if(userChoice == 'b'){

            }else if(userChoice == 'c'){

            }else if(userChoice == 'd'){

            }else if(userChoice == 'e'){

            }else if(userChoice == 'f'){
                System.out.println("See you again.");
                break;
            }





        }
    }
}
