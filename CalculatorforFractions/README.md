# Calculator for Fractions

Develop a class which stores fractions using the format f = n/d and supports the binary operations +, -, *, / as well as the unary operations c++ and ++c.

## UML

**CFraction**

-*m_numerator: long*   
-*m_denominator: long*

---

-*shorten(): void*  
+*CFraction(numerator: long, denominator: long)*  
+*set(numerator: long, denominator: long): void*  
+*toDouble(): double*  
+*print(): void*  
+*operator++(): CFraction&*  
+*operator++(int): CFraction*  

## Implementation

	1. Declare the class as defined in the UML diagram. Note that Together does not show default parameter values in the class diagram. The constructor is fully specified as +Fraction(numerator:long=0, denominator:long=1)
	2. Implement the shorten()method. It's purpose is to “normalize” the fraction, i. e. make sure that nominator and denominator have no common divider greater than 1 (a quick research using the Internet will show you how this can be done easily). The fraction is to be kept in a normalized form by all methods and functions described below.
	3. Implement the constructor. What special condition must be observed? How can you handle it? (Supply the answer as comment in the code and implement appropriately.)
	4. Implement the set method. What special condition must be observed? How can you handle it? (Supply the answer as comment in the code and implement appropriately. Note that the best approach to handle the condition in this method differs from the best approach for handling the problem in the constructor.)
	5. Implement the toDouble() method, which calculates the value of the fraction as floating point number.
	6. Implement the print() method, which prints the fraction number in the format Fraction[nominator=value; denominator=value] 
	7. Test the constructor by defining the following objects and printing them:
		Fraction f1;
		Fraction f2(1,3);
		Fraction f3(24, 3);
	8. Add code for testing toDouble() using f2.
	9. Implement overloaded operators for the +, -, * and / operation, supporting operations between 2 fractions as well as operations between an integer and a fraction. Hint: You will need 3 overloaded operators per operation, e. g. fraction + fraction, fraction + integer, integer + fraction. Choose the most efficient way to do each implementation.
	10. Implement the overloaded << Operator, which prints the fraction as “(nominator/denominator)” (without trailing newline).
	11. Test the overloaded operators by adding some calculations and printouts in the following format. Make sure that all operators are tested: 
		cout << "(3/4)+(2/3) = "
		<< Fraction(3, 4) + Fraction (2, 3) << endl;
		// Add more testcases as needed!
	12. Whenever possible, choose values that also show that normalization (shortening) works (the above example does not fulfill this criterion).
	13. Implement the post and pre-increment operators. Add the following test case to your program and compare the implemented operators with the behavior of the standard postand pre-increment operators (e. g. for an integer variable) 
		Fraction f(1, 3);
		Fraction g;
		g = ++f;
		cout << "++f == " << f << "; (g=++f) == " << g << endl;
		f.set(1,3);
		g = f++;
		cout << "f++ == " << f << "; (g=f++) == " << g << endl;
