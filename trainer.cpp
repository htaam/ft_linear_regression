



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
//output price  