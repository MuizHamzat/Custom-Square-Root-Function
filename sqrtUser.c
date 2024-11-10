#include <stdio.h>
#include <stdlib.h>

//Muiz Hamzat 400500321

//Time complexity is O(log n + n)
double sqrtUser(double number, int n) {
    double start = 0;
    double end = number;
    double ans;

    if (number < 0){
        //Can't find the square root of a negative number
        printf("Cannot find square root of negative number. Will return value of zero.\n");
        return 0;
    }

    /*Find square root of the inputted number rounded down 
    to the nearest whole number using binary search method
    Ex: if number = 67.8, find sqrt(67)*/
    
    int whole_num = number; //type casting number (a double) to an int to "cut off " the decimals
    float accuracy = 0.00001; //THe accuracy used to calculate the square root in the following loop

    //Binary search loop
    while (start <= end) {
        float mid = (start + end)/2; //middle number betweeen start & end
        float mid_squared = mid * mid;
        float difference = abs(mid_squared - whole_num); //This is used to avoid an infinite loop
        //if mid is "close enough" to the number

        /*If mid^2 is smaller than inputted number, mid is below the square root,
        so make mid our start value*/
        if (mid_squared < whole_num && difference >= accuracy) { 
            start = mid;
        } 
        
        /*If mid^2 is bigger than inputted number, mid is above the square root
        so make mid our end value*/
        else if (mid_squared > whole_num && difference >= accuracy) {
            end = mid;
        }
        
        //otherwise, mid must be at the answer so we break out of the loop
        else {
            ans = mid;
            break;
        }
    }

    /*At this point, we have the exact answer down to 6 decimal places,
    however we need to give the answer in up to n decimal places.

    So, we type cast ans to an int, which rounds ans down to the nearest whole number,
    and then type cast it back to a float so we can add its decimals back up to a 
    precision of n.*/ 
    ans = (int)ans;
    ans = (float)ans;

    /*We then continously increment ans by a decimal value that gets more precise
    until we have reached n decimal places*/
    float decimal = 0.1; 

    for (int i=0; i < n; i++) { //Repeat the following loop for each decimal place
        
        /*For the following loop, we add the increment to ans until it is
        larger than the exact answer. We then subtract one increment
        so that ans is slightly less than the exact answer, and then
        increase the precision of the increment value. We keep doing this
        until ans is accurate up to n decimal places.*/

        while (ans * ans <= number) {ans += decimal;}

        ans -= decimal;
        decimal /= 10;
    }

    return ans;
}

int main() {
    
    //Put parameters here
    double number = 89756952;
    int n = 3;
    
    printf("The square root of %lf to %i decimal places is %lf.\n", number, n, sqrtUser(number, n));

}
