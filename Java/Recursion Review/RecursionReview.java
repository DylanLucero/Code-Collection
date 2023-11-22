/******************************************************************************
Code by Dylan Lucero
---------------------
This file contains the methods that were described in the original Recursion
review pdf file.
*******************************************************************************/
public class RecursionReview
{
	public static void main(String[] args) {
		/*
		a. base case - num < 10, return num
		b. recursive case - digit + sumDigits( num / 10)
		*/

		System.out.println("sumDigits(126) 	= " + sumDigits(126));
		System.out.println("sumDigits(49)  	= " + sumDigits(49));
		System.out.println("sumDigits(2)   	= " + sumDigits(2));
		System.out.println();
		
		System.out.println("count3(313)	= " + count3(313));
		System.out.println("count3(3)    	= " + count3(3));
		System.out.println("count3(456)  	= " + count3(456));
		System.out.println();

		System.out.println("recMult(0,10) 	= " + recMult(0,10));
		System.out.println("recMult(1,5) 	= " + recMult(1,5));
		System.out.println("recMult(18,8) 	= " + recMult(18,8));
		System.out.println();

		System.out.println("isPrime(919,2) 	= " + isPrime(919,2));
		System.out.println("isPrime(50,2) 	= " + isPrime(50,2));
		System.out.println("isPrime(2,2) 	= " + isPrime(2,2));
		System.out.println();

		System.out.println("dupVowel(hello) = " + dupVowel("hello"));
		System.out.println("dupVowel(xxyy) 	= " + dupVowel("xxyy"));
		System.out.println("dupVowel(abc) 	= " + dupVowel("abc"));
		System.out.println();

		System.out.println("array10([10, 20, 31])" + "");
		System.out.println("array10([11, 10])" + "");
		System.out.println("array10([1, 2, 3, 4])" + "");
		System.out.println();


	}

// sumDigits will add the digits in a number
	public static int sumDigits( int num){
	    if( num < 10 )              // base case
			return num;
	    if( num == 0)                 // alternate base case version
	        return 0;
	    else                        // recursive case
	        return num % 10 + sumDigits( num / 10 );
	}


// count3: given a non-negative int n, recursively count the occurrences of 3 as a digit

	public static int count3(int num){
	    if( num < 10 ) 				// Base Case: if num < 10, and num == 3, return 1, else return 0
			if(num == 3)
				return 1;
			else
			 	return 0;             
	    else						// Recursive Case: if num % 10 == 3, add 1 and do another pass; else do another pass
		    if(num % 10 == 3)
				return 1 + count3(num/10);
			else
				return count3(num/10);                  				
				                     
	}

// recMult: This method performs multiplication by recursively performing addition
	public static int recMult(int x, int y){
		if(x == 0 || y == 0) 		// Base Case: return 0 if x or y = 0
			return 0;
		else 						// Recursive Case: return x + x y times; decrement every pass until y = 0.
			return x + recMult(x, y-1);
	}

/*
	isPrime: boolean returning recursive method to determine if a number is prime. 
	Recursively determine if the any number less the number are divisible by the number.
*/

	public static boolean isPrime(int numCheck, int count){
		if(numCheck <=2)			// Base Case: check if numCheck = 2; return true numCheck = 2 and false if numCheck != 2
			if(numCheck == 2)
				return true;
			else
				return false;
		if(numCheck % 2 == 0)
			return false;
		if(Math.sqrt(numCheck) > count)
			return true;
		else
			return isPrime(numCheck, count);
	}
/*
Given a String, recursively build a new string where the vowels are duplicated.

vowels: a,e,i,o,u
*/
	public static String dupVowel(String str){
		if(str.length() < 1)				// Base Case: If string length is smaller than 1, return string
			return str;
		
		switch (str.charAt(0)){		// Switch checks each character in to see if its a vowel
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				return "" + str.charAt(0) + str.charAt(0) + dupVowel(str.substring(+1));
			default:
				return "" + str.charAt(0) + dupVowel(str.substring(+1));
		}
	}


/*
 Given an array of ints, recursively compute the number of times that a multiple of 10
appears in the array. index is used to examine a specific element from the array. Use a
helper function to incorporate an index to count through elements in the array.

int array10( int[] nums){…}
int array10Helper( int[] nums, int index ){…}  
*/
}







