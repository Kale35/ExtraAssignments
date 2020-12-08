#include <iostream>

//Function that finds the mean of 3 values
float findMean(float a, float b, float c)
{
    float meanNum = (a + b + c) / 3;

    return meanNum;
}

//Function that finds the median of 3 values
float findMedian(float a, float b, float c)
{
    float medianNum;

    //Case for a being the median
    if ((a < b && a > c) || (a > b && a < c))
    {
        medianNum = a;
    }

    //Case for b being the median
    else if ((b < a && b > c) || (b > a && b < c))
    {
        medianNum = b;
    }

    //Case for c being the median
    else if ((c < a && c > b) || (c > a && c < b))
    {
        medianNum = c;
    }

    return medianNum;
}

//Function that finds the mode of 3 values
float findMode(float a, float b, float c)
{
    float modeNum;

    if (a = b)
    {
        modeNum = a;
    }
    else if (b = c)
    {
        modeNum = b;
    }
    else if (a = c)
    {
        modeNum = a;
    }
    else
    {
        modeNum = -1;
    }

    return modeNum;
}

int main()
{
    float mean, median, mode;

    std::cout << "Enter first value(positive)";
    float num1;
    std::cin >> num1;

    std::cout << "Enter second value(positive)";
    float num2;
    std::cin >> num2;

    std::cout << "Enter third value(positive)";
    float num3;
    std::cin >> num3;

    mean = findMean(num1, num2, num3);

    median = findMedian(num1, num2, num3);

    mode = findMode(num1, num2, num3);

    std::cout << "Mean" << mean << std::endl;

    std::cout << "Median:" << median << std::endl;

    std::cout << "Mode:" << mode << std::endl;
};