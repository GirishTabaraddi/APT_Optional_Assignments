// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
#include "CFraction.h"
#include "CLifoBuffer.h"
#include "CRpnCalculator.h"

#define FRACTION 		0
#define LIFOBUFFER 		0
#define RPN_CALCULATOR	0

// Main program
int main ()
{
#if FRACTION
	cout << "CalculatorforFractions started." << endl << endl;

	{
		cout << endl << "=============Testing default constructor object ===================" << endl;
		CFraction f1;
		f1.print();
	}

	{
		cout << endl << "======Testing constructor object by passing parameters ============" << endl;
		CFraction f2(1, 3);
		f2.print();
		double result = f2.toDouble();
		cout << "double: " << result << endl;
	}

	{
		cout << endl << "===============Testing shorten method =============================" << endl;
		CFraction f3(24, 3);
		f3.print();
	}

	{
		cout << endl << "===============Testing set method =================================" << endl;
		CFraction f4(-1, 0);
		f4.print();
		f4.set(-4, 0);
	}

	{
		cout << endl << "===============Testing << overloaded method =======================" << endl;
		CFraction f5(2, 3);
		cout << f5 << endl;
	}

	{
		cout << endl << "============Testing pre-increment overloaded method ===============" << endl;
		CFraction f6(1, 3);
		CFraction g;
		g = ++f6;

		cout << "++f == " << f6 << "; (g=++f) == " << g << endl;

		cout << endl << "============Testing post-increment overloaded method ==============" << endl;
		f6.set(1, 3);
		g = f6++;

		cout << "f++ == " << f6 << "; (g=f++) == " << g << endl;
	}

	{
		cout << endl << "================Testing + overloaded method ======================" << endl;

		cout << "(3/4)+(2/3) = " << CFraction(3, 4) + CFraction(2, 3) << endl;
		cout << "(3/5)+(2/10) = " << CFraction(3, 5) + CFraction(2, 10) << endl;

		int OtherInteger = 3;
		cout << "(3/4)+3 = " << CFraction(3, 4) + OtherInteger << endl;
		cout << "3+(3/4) = " << OtherInteger + CFraction(3, 4) << endl;
	}

	{
		cout << endl << "================Testing * overloaded method ======================" << endl;

		cout << "(3/4)*(2/3) = " << CFraction(3, 4) * CFraction(2, 3) << endl;
		cout << "(3/5)*(2/10) = " << CFraction(3, 5) * CFraction(2, 10) << endl;

		int OtherInteger = 4;
		cout << "(3/4)*4 = " << CFraction(3, 4) * OtherInteger << endl;
		cout << "4*(3/4) = " << OtherInteger * CFraction(3, 4) << endl;
	}

	{
		cout << endl << "================Testing / overloaded method ======================" << endl;

		cout << "(3/4)/(2/3) = " << CFraction(3, 4) / CFraction(2, 3) << endl;
		cout << "(3/5)/(2/10) = " << CFraction(3, 5) / CFraction(2, 10) << endl;

		int OtherInteger = 5;
		cout << "(3/4)/4 = " << CFraction(3, 4) / OtherInteger << endl;
		cout << "4/(3/4) = " << OtherInteger / CFraction(3, 4) << endl;
	}

	{
		cout << endl << "================Testing - overloaded method ======================" << endl;

		cout << "(3/4)-(2/3) = " << CFraction(3, 4) - CFraction(2, 3) << endl;
		cout << "(3/5)-(9/10) = " << CFraction(3, 5) - CFraction(9, 10) << endl;

		int OtherInteger = 6;
		cout << "(6/4)-6 = " << CFraction(6, 4) - OtherInteger << endl;
		cout << "6-(6/4) = " << OtherInteger - CFraction(6, 4) << endl;
	}
#endif

#if LIFOBUFFER

	cout << "Lifo Buffer started." << endl << endl;

	{
		CLifoBuffer buffer(5);

		cout << "===========Pushing elements into buffer===========" << endl;
		buffer.push(CFraction(3,4));
		buffer.push(CFraction(6,4));
		buffer.push(CFraction(3,9));
		buffer.push(CFraction(3,10));
		buffer.push(CFraction(6,5));
		buffer.push(CFraction(7,9));

		cout << endl << "============Elements in buffer=============" << endl;
		buffer.print();

		CFraction poppedValue;

		cout << "===========Popping elements from buffer===========" << endl;

		for(int loop = 0; loop < 5; loop++)
		{
			if (buffer.pop(poppedValue))
			{
				cout << "Popped value: " << poppedValue << endl;
			}
		}

		cout << endl << "============Buffer after popping elements=============" << endl;

		buffer.print();
	}
#endif

#if RPN_CALCULATOR
	{
		cout << "CRpnCalculator started." << endl << endl;

		CRpnCalculator RpnCalculator(10);

		cout << "===========Pushing elements into buffer===========" << endl;

		RpnCalculator.pushValue(CFraction(5, 2));
		RpnCalculator.pushValue(CFraction(6, 5));

		RpnCalculator.multiply();	// 5 2 / 6 5 *

		RpnCalculator.pushValue(CFraction(1, 2));

		RpnCalculator.add();	// (5 2 / 6 5 *) 1 2 +

		RpnCalculator.pushValue(CFraction(1, 3));

		RpnCalculator.subtract();	// ((5 2 / 6 5 *) 1 2 +) 1 3 - (result of numerator)

		RpnCalculator.pushValue(CFraction(5, 1));
		RpnCalculator.pushValue(CFraction(1, 6));

		RpnCalculator.add();	// 5 1 6 / +

		RpnCalculator.pushValue(CFraction(11, 4));

		RpnCalculator.add();	// (5 1 6 / +) 11 4 + (result of denominator)

		RpnCalculator.divide();	// (result of numerator) (result of denominator) /

		CFraction Result;

		if(RpnCalculator.popResult(Result))
		{
			cout << endl << "RPN: (5 2 / 6 5 * 1 2 / + 1 3 - / 5 1 6 / + 11 4 / +) result :"
					<< Result << endl;
		}
		else
		{
			cout << "ERROR: Unable to retrieve the result!!!" << endl;
		}

		RpnCalculator.printStack();
	}
#endif

	return 0;
}
