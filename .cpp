#include <iostream>
#include <iomanip> 

using namespace std;

//comment  Constants for charges
const double SERVICE_CHARGE_RATE = 0.07; 
const double TAX_RATE = 0.09;           
const double LARGE_BILL_THRESHOLD = 1500.00; 

/**
 * @brief Calculates the final bill amount including service charge and tax.
 * * @param subtotal The initial cost of the meal.
 * @return The final bill amount.
 */
double calculateFinalBill(double subtotal) {
    // Calculate the service charge and tax amounts
    double serviceCharge = subtotal * SERVICE_CHARGE_RATE;
    double taxAmount = subtotal * TAX_RATE;

    //  the final bill
    double finalBill = subtotal + serviceCharge + taxAmount;
    
    return finalBill;
}

int main()
 {
    int numTables = 0;

    // 1.  number of tables (N)
    cout << " Restaurant Bill Calculator " << endl;
    cout << "Enter the number of tables (N): ";
    // Use a while loop to ensure the user enters a positive number
    while (!(cin >> numTables) || numTables <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of tables: ";
        cin.clear(); // Clear error flags
        cin,ignore(10000, '\n'); // Discard bad input
    }

    cout << "\n--- Processing " << numTables << " Tables ---" << endl;

    // 2. Loop 
    for (int i = 1; i <= numTables; ++i) 
	{
        double subtotal = 0.0;
        double finalAmount = 0.0;
        string billClassification;
        cout << "\nEnter subtotal amount for **Table " << i << "**: $";
        while (!(cin >> subtotal) || subtotal < 0) {
            cout << "Invalid input. Please enter a non-negative subtotal: $";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }

        //  the final bill
        finalAmount = calculateFinalBill(subtotal);

        // 3.  if/else condition to find the bill size
        if (finalAmount > LARGE_BILL_THRESHOLD) {
            billClassification = "**LARGE**";
        } else 
		 {
            billClassification = "Standard";
        }
        
        cout << fixed << setprecision(2); 
        cout << "\n Bill Details for Table " << i << ":" << endl;
        cout << "   Subtotal: $" << subtotal << endl;
        cout << "   Service Charge (7%):$" << subtotal * SERVICE_CHARGE_RATE << endl;
        cout << "   Tax (9%):$" << subtotal * TAX_RATE << endl;
        cout << "   ---------------------------------" << endl;
        cout << "   **FINAL AMOUNT DUE:** $" << finalAmount << endl;
        cout << "   Bill Classification:   " << billClassification << endl;
        cout << "-----------------------------------" << endl;
    }

    cout << "\n All table bills have been calculated. Thank you!" << endl;

    return 0;
}
