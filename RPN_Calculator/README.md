# Extension - An RPN Calculator

Now you will implement a calculator for evaluating expressions of fractions noted in reversepolish notation.

Reverse polish notation (RPN, also known as postfix notation) is a mathematical notation that puts the operator behind the operands. In contrast, the notation we are accustomed to is called infix notation, because the operator is put between the operands. As a simple example, consider infix noted “3 + 4” which becomes “3 4 +” using postfix notation (see also
http://en.wikipedia.org/wiki/Reverse_Polish_notation).

An interesting point about postfix notation is that no parentheses are required for complex expression. Consider the more complex example “(3 + 4) * (5 + 6)”. Using RPN this becomes “3 4 + 5 6 + *”. This simplified processing led to the implementation of RPN in early hand held calculators (burdening the user with the task of rearranging the expression). The German Wikipedia page about RPN shows a picture of such a calculator (http://de.wikipedia.org/wiki/Umgekehrte_Polnische_Notation).

The first step in the implementation of the RPN calculator is providing the calculator’s memory. The memory of an RPN calculator is organized as a stack or LIFO buffer (Last In First Out) that stores the operands until the operation is chosen. The UML diagram below shows the LIFO buffer.

## UML

---

**CFraction**

-*m_numerator: long*   
-*m_denominator: long*


-*shorten(): void*  
+*CFraction(numerator: long, denominator: long)*  
+*set(numerator: long, denominator: long): void*  
+*toDouble(): double*  
+*print(): void*  
+*operator++(): CFraction&*  
+*operator++(int): CFraction*  

---

**CLifoBuffer**

-*m_size: int*  
-*m_tos: int*  
-*m_pBuffer: CFraction*  


+*CLifoBuffer(size: int)*  
+*~CLifoBuffer()*  
+*print(): void*  
+*push(data: const CFraction&): bool*  
+*pop(data: CFraction&): bool*  

---

**CLifoBuffer** "0..1" --> "2..10" **CFraction** : *Composition*  

---

## Implementation

	1. Copy the existing class Fraction to the new project.
	2. Define the class LifoBuffer specified in the UML diagram.
	3. Implement the constructor. Allocate the required memory. Set the pointer to the top of stack (tos) to -1. Using this invalid index indicates that the stack is empty. Print all attributes and the content of the buffer.
	4. Implement the destructor. Make sure that all allocated memory is released.
	5. Implement the push() operation. Check if there is still memory left. In case there is  increment the top of stack pointer and store the value.
	6. Implement the pop() operation. Check if there is a value in the buffer. In case there is, return it and decrement the top of stack.
	7. Implement the print() operation, printing the values of all attributes as well as the content of the buffer.
	8. Test the first version of the class by generating a LIFO buffer object with 5 elements, adding three items, printing its content, retrieving the elements and printing the content again.

Now add a class that implements the actual RPN calculator as specified by the UML diagram below.

## UML

---

**CFraction**

-*m_numerator: long*   
-*m_denominator: long*  

-*shorten(): void*  
+*CFraction(numerator: long, denominator: long)*  
+*set(numerator: long, denominator: long): void*  
+*toDouble(): double*  
+*print(): void*  
+*operator++(): CFraction&*  
+*operator++(int): CFraction*  

---

**CLifoBuffer**

-*m_size: int*  
-*m_tos: int*  
-*m_pBuffer: CFraction*  


+*CLifoBuffer(size: int)*  
+*~CLifoBuffer()*  
+*print(): void*  
+*push(data: const CFraction&): bool*  
+*pop(data: CFraction&): bool*  

---

**CLifoBuffer** "0..1" --> "2..10" **CFraction** : *Composition*

---

**CRpnCalculator**

-*m_stack: CLifoBuffer*  


+*pushValue(data: const CFraction&): bool*  
+*popResult(data: CFraction&): bool*  
+*add(): void*  
+*subtract(): void*  
+*multiply(): void*  
+*divide(): void*  

---

**CRpnCalculator** --> **CLifoBuffer** : *Composition*  
**CRpnCalculator** --> **CFraction** : *Association*  

---

## Implementation

	1. Add the new class RpnCalculator to the project.
	2. Implement pushValue() and popValue(). These methods delegate directly to the corresponding methods of the stack attribute (the LIFO buffer).
	3. The methods add(), subtract(), multiply() and divide() perform the respective operations using the two top values on the stack and replace these values with the result.
	4. Test the implementation. Create an instance of RpnCalculator. Write a test program that invokes its methods as necessary to evaluate and print the result. There may be only a single invocation of popResult() in your code.
