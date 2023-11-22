public class CreditcardAccount extends BankAccount{

    //Data
    private int creditLimit = 0;

    
    //Methods
    public int getCreditLimit(){ 
        return creditLimit; 
    }

    public void setCreditLimit(int creditLimit){
        this.creditLimit = creditLimit;
    }

    @Override
    public boolean debit(int amount) { 
        if (amount > creditLimit){
            return false;
        } else {
            balance -= amount;
            return true;
        }
     }


    public String getAccountInfo(){
        String string = "";
        string = string + "Account type  : Creditcard\n";
        string = string + "Account #     : " + this.accountNumber + "\n";
        string = string + "Balance       : $" + String.format("%.2f", ((double)this.balance / 200)) + "\n";
        string = string + "Interest rate : " + String.format("%.2f", (this.interestRate * 100.00)) + "%" + "\n";
        string = string + "Credit limit  : $" + String.format("%.2f", ((double)this.creditLimit / 100)) + "\n";; 
        return string;
    }

    @Override
    public void applyInterest() {
        if (getBalance()<0){
            this.balance = ((int)(this.balance + (this.balance * this.getInterestRate())));
        }
    }
}
