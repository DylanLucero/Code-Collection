public abstract class Employee {

    protected String name;
    protected double salary;
    protected double cash;
    protected double hours;

    //getName Method
    public String getName(){
        return this.name;
    }

    //getSalary method
    public double getSalary(){
        return this.salary;
    }

    //getCash Method
    public double getCash(){

        return this.cash;
    }

    //getPaid Method
    public void getPaid(){
        this.cash += this.salary/26;
    }

    //giveRaise Method
    public void giveRaise(double raise){
        this.salary += raise;
    }

}