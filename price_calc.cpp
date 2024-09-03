/*
float theta0 //from file
float theta1 //from file
int milage //from input

float price =    theta0 + (theta1 * mileage);

//output price  */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to load the model from a file
void loadModel(double& theta0, double& theta1, const string& filePath = "model.txt") {
    ifstream file(filePath);
    string line;
    
    if (file.is_open()) {
        getline(file, line);
        size_t commaPos = line.find(',');
        theta0 = stod(line.substr(0, commaPos));
        theta1 = stod(line.substr(commaPos + 1));
    }
    file.close();
}

// Function to predict the price of a car based on mileage
double predictPrice(double mileage, double theta0, double theta1) {
    return theta0 + theta1 * mileage;
}

// Main function for the prediction program
int main() {
    double theta0, theta1;
    loadModel(theta0, theta1);
    
    double mileage;
    cout << "Enter the mileage of the car: ";
    cin >> mileage;
    
    double estimatedPrice = predictPrice(mileage, theta0, theta1);
    cout << "The estimated price for a car with " << mileage << " mileage is: $" << estimatedPrice << endl;
    
    return 0;
}

// Example usage:
// int main() {
//     main();
//     return 0;
// }
