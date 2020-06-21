#include "InterestCalculator.h"


InterestCalculator::InterestCalculator(){
};

double InterestCalculator::interestMonthly(double m_initInvest, double m_intRate, double m_monthlyDep) { //Calculates interest for displayCharts()
    m_interest = (m_initInvest + m_monthlyDep) * ((m_intRate / 100) / 12);
    return m_interest;
}

void InterestCalculator::dataInputUI(){  //Input interface
    
    cout << setfill('*');
    cout << setw(32) << '*' << endl;
     
    cout <<setw(11) << right << ' ';
    cout << "Data Input";
    cout << setw(11) << left << ' ' << endl;
     
    cout << "Initial Investment Amount: $";
    cin >> m_initInvest;
    cout << "Monthly Deposit: $";
    cin >> m_monthDep;
    cout << "Annual Interest: %";
    cin >> m_yearInterest;
    cout << "Number of years: ";
    cin >> m_numYears;
    cout << "\n\n";
}
 
void InterestCalculator::displayCharts() {  //Displays the end of year balance and interest
    //Balance and Interest Without Additional Monthly Deposits
    m_tempInitInvest = m_initInvest;

    //Header
    cout << "    Balance and Interest Without Additional Monthly Deposits    \n";
    cout << setw(65) << right << setfill('=') << "=\n";
    cout << setfill(' ');
    cout << setw(6)<< right << "Year";
    cout << setw(23) << right << "Year End Balance";
    cout << setw(34) << right << " Year End Earned Interest\n";
    cout << setw(65) << setfill('-') << "-\n";
    
    //Data
    for (int i = 1; i <= m_numYears; ++i){
        for (int j = 0; j < 12; ++j) {
            m_tempInterest = interestMonthly(m_tempInitInvest, m_yearInterest);
            m_tempInitInvest += m_tempInterest;
            m_interestTotal += m_tempInterest;
        }
        cout << setfill(' ') << fixed << setprecision(2);
        cout << setw(6)<< right << i;
        cout << setw(23) << right << m_tempInitInvest;
        cout << setw(33) << right << m_interestTotal << "\n";
        m_interestTotal = 0;
    }
    cout << "\n\n";
    
    //Balance and Interest With Additional Monthly Deposits
    m_tempInitInvest = m_initInvest;
    m_interest = 0;
    
    //Header
    cout << "     Balance and Interest With Additional Monthly Deposits     \n";
    cout << setw(65) << setfill('=') << "=\n";
    cout << setfill(' ');
    cout << setw(6)<< right << "Year";
    cout << setw(23) << right << "Year End Balance";
    cout << setw(34) << right << " Year End Earned Interest\n";
    cout << setw(65) << setfill('-') << "-\n";
     
    //Data
    for (int i = 1; i <= m_numYears; ++i){
        for (int j = 0; j < 12; ++j) {
            m_tempInterest = interestMonthly(m_tempInitInvest, m_yearInterest, m_monthDep);
            m_tempInitInvest += (m_tempInterest + m_monthDep);
            m_interestTotal += m_tempInterest;
        }
        cout << setfill(' ') << fixed << setprecision(2);
        cout << setw(6)<< right << i;
        cout << setw(23) << right << m_tempInitInvest;
        cout << setw(33) << right << m_interestTotal << "\n";
        m_interestTotal = 0;
    }
    cout << "\n\n";
}


