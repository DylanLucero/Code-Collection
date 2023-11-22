public class SoftwareEngineer extends Employee{

    public SoftwareEngineer(String name, double salary){
        this.name = name;
        this.salary = salary;
        this.cash = 0;
    }

    public void giveRaise(double raise){
        this.salary += raise;
    }

}
