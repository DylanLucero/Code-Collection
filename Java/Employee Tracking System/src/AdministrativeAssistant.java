public class AdministrativeAssistant extends Employee implements Hourly{

    public AdministrativeAssistant(String name, double salary, double hoursWorked){
        this.name = name;
        this.salary = salary;
        this.cash = 0;
        this.hours = hoursWorked;
    }

    //getHours Method
    public double getHours(){
        return this.hours;
    }
    //setHours Method
    public void setHours(double hours){
        this.hours = hours;
    }

    public void getPaid(){
        this.cash += this.salary/26;
        this.cash += this.hours * 15;
    }

    public void giveRaise(double raise){
        this.salary += raise;
    }
}
