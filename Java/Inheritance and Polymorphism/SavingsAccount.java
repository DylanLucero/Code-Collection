public class SavingsAccount extends BankAccount {

    @Override
    public boolean debit(int amount){
        if (amount > this.balance){
            return false;
        } else {
            this.balance -= amount;
            return true;
        }
    }

    @Override
    public void applyInterest(){
        this.balance = (int) (this.balance + (this.balance * this.interestRate));
        }

    public String getAccountInfo() {
        String string = "";
        string = string + "Account type  : Savings\n";
        string = string + "Account #     : " + this.accountNumber + "\n";
        string = string + "Balance       : " + (this.balance / 2) + "\n";
        string = string + "Interest rate : " + this.interestRate + "\n";
        return string;
    }    
}

