/*Josh Ryther
 * Project 2
 * 06/02/20
 */

#include "InterestCalculator.h"

char cmd = 'c';
 
int main()
{
    while (cmd != 'q') {
        InterestCalculator newCalc;
        newCalc.dataInputUI(); //Displays input
        newCalc.displayCharts(); //Displays interest and year end balances
        
        cout << "Press q to quit or any other key to continue.\n";
        cin >> cmd;
    }

	return 0;
    
}
