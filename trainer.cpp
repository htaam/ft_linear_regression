


/*
float old_theta0 //from file
float old_theta1 //from file
int file_milage //from data
int file_price//from data
int m// number of lines in data file

learn = ??//what this??

Sum0//somatorio para theta0

for(int j=2;j<=m+1;j++)
{
    temp = estimate(j)-price(j);
    Sum0 = Sum0 + temp;
} 

float new_theta0 = learn * (1/m)*Sum0;

Sum1// somatorio para theta1

for(int j=2;j<=m+1;j++)
{
    temp = (estimate(j) - price(j)*milage(j));
    Sum1 = Sum1 + temp;
}
float new_theta1 = learn * (1/m)*Sum1; 
//output price  */


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to load data from a CSV file
void loadData(const string& filePath, vector<double>& mileage, vector<double>& price) {
    ifstream file(filePath);
    string line;
    
    // Skip the header row
    getline(file, line);
    
    while (getline(file, line)) {
        if (line.empty()) {
            continue;  // Skip empty lines
        }
        
        stringstream ss(line);
        string temp;
        double m, p;
        
        try {
            getline(ss, temp, ',');
            m = stod(temp);
            
            getline(ss, temp, ',');
            p = stod(temp);
            
            mileage.push_back(m);
            price.push_back(p);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid data format in line: " << line << endl;
            continue;  // Skip this line and move to the next one
        } catch (const out_of_range& e) {
            cerr << "Error: Data out of range in line: " << line << endl;
            continue;  // Skip this line and move to the next one
        }
    }
}

// Function to compute the cost (mean squared error)
double computeCost(const vector<double>& mileage, const vector<double>& price, double theta0, double theta1) {
    int m = mileage.size();
    double cost = 0;
    
    for (int i = 0; i < m; i++) {
        double prediction = theta0 + theta1 * mileage[i];
        cost += (prediction - price[i]) * (prediction - price[i]);
    }
    
    return cost / (2 * m);
}

// Function to perform gradient descent
void gradientDescent(const vector<double>& mileage, const vector<double>& price, double& theta0, double& theta1, double learningRate, int numIterations) {
    int m = mileage.size();
    
    for (int iter = 0; iter < numIterations; iter++) {
        double sum0 = 0, sum1 = 0;
        
        for (int i = 0; i < m; i++) {
            double prediction = theta0 + theta1 * mileage[i];
            sum0 += (prediction - price[i]);
            sum1 += (prediction - price[i]) * mileage[i];
        }
        
        theta0 -= learningRate * (sum0 / m);
        theta1 -= learningRate * (sum1 / m);
        
        double cost = computeCost(mileage, price, theta0, theta1);
        cout << "Cost after iteration " << iter + 1 << ": " << cost << endl;
    }
}

// Function to save the trained model to a file
void saveModel(double theta0, double theta1, const string& filePath = "model.txt") {
    ofstream file(filePath);
    file << theta0 << "," << theta1;
    file.close();
}

// Function to train the model
void trainModel(const string& filePath, double learningRate = 1, int numIterations = 1) {
    vector<double> mileage, price;
    loadData(filePath, mileage, price);
    
    double theta0 = 0, theta1 = 0;
    gradientDescent(mileage, price, theta0, theta1, learningRate, numIterations);
    
    saveModel(theta0, theta1);
    cout << "Model trained successfully: theta0 = " << theta0 << ", theta1 = " << theta1 << endl;
}
///Example usage:
int main() {
     trainModel("data.csv");
     return 0;
 }
