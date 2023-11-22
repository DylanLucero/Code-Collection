public abstract class BankAccount {

    //Data
    protected String accountNumber = "0000-0000-0000-0000";
    protected double interestRate = 0.0;
    protected int balance = 0;

    //Methods
    public boolean credit(int amount){
        if(amount<=0){
            return false;
        } else {
            this.balance += amount;
            return true;
        }
    }
    

    public int getBalance(){ 
        return this.balance;
     }

    public String getAccountNumber(){ 
        return this.accountNumber;
     }

    public void setAccountNumber(String accountNumber){
        this.accountNumber = accountNumber;
    }

    public double getInterestRate(){ 
        return this.interestRate; 
    }

    public void setInterestRate(double interestRate){
        if(interestRate < 0.00){
            return;
        } else {
            this.interestRate = interestRate;
        }
    }

    //Abstract Methods
    public abstract void applyInterest();

    public abstract boolean debit(int amount);

    public abstract String getAccountInfo();



}