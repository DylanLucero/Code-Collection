public class CheckingAccount extends BankAccount{

    private int overdraftFee = 0;

    public int getOverdraftFee(){ 
        return this.overdraftFee; 
    }

    public void setOverdraftFee(int overdraftFee){
        this.overdraftFee = overdraftFee;
    }

    public String getAccountInfo(){
        String string = "";
        string = string + "Account type  : Checking\n";
        string = string + "Account #     : " + this.accountNumber + "\n";
        string = string + "Balance       : " + this.balance /2 + "\n";
        string = string + "Interest rate : " + this.interestRate + "\n";
        string = string + "Overdraft fee : " + this.overdraftFee;
        return string;
    }


    public boolean debit(int amount) {   
        this.balance -= amount;
        if (this.balance < 0) 
            this.balance -= overdraftFee;
        return true;
        
     }

    @Override
    public void applyInterest() { 
        if (balance <= 0) 
            return;
        this.balance = (int) (this.balance + (this.balance * this.interestRate));
    }

}
