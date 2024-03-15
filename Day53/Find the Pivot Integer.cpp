class Solution {
public:
    int pivotInteger(int n) {
        // Initialize two pointers, i and j, to keep track of the range
        int i = 1;
        int j = n;

        // Initialize leftSum and rightSum to keep track of sums on the left and right sides respectively
        int leftSum = 1;
        int rightSum = n;

        // Loop until i is less than j
        while(i < j){
            // If leftSum is less than rightSum, increment i and update leftSum
            if(leftSum < rightSum){
                i++;
                leftSum += i;
            }
            // If leftSum is greater than or equal to rightSum, decrement j and update rightSum
            else{
                j--;
                rightSum += j;
            }
        } 

        // If leftSum equals rightSum, return the pivot integer (i), otherwise return -1
        return (leftSum == rightSum) ? i : -1;
    }
};
