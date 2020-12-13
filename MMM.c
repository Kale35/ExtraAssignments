#define MAX 25
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int readAll();
void fill(int total, int nums[]);
void sortData(int nums[], int total);
double findMean(int nums[], int total);
double findMedian(int nums[], int total);
int findMode(int nums[], int total);
void results(double mean, double median, double mode);
bool redo();

int main()
{
    int nums[MAX];
    int total;
    double mean, median, mode;
    do
    {
        total = readAll(); //guarantee 1-25
        fill(total, nums); //read in the #s don't need to check range
        sortData(nums, total);
        mean = findMean(nums, total);
        median = findMedian(nums, total);
        mode = findMode(nums, total);
        results(mean, median, mode);
    } while (redo());
    return 0;
}

//Funciton to read all values
int readAll()
{
    int num;
    do
    {
        printf("How many numbers? ");
        scanf("%i", &num);
    } while (num < 1 || num > 25);
    return num;
}

//Function which fills data
void fill(int total, int nums[])
{
    int temp;
    int i;
    printf("Please enter %i numbers\n", total);
    for (i = 0; i <= total - 1; i++)
    {
        scanf("\n%i", &nums[i]);
    }
}

//Function to sort data
void sortData(int nums[], int total)
{
    int x;
    int y;
    for (x = 0; x < total; x++)
    {
        for (y = 0; y < total - 1; y++)
        {
            if (nums[y] > nums[y + 1])
            {
                int temp = nums[y + 1];
                nums[y + 1] = nums[y];
                nums[y] = temp;
            }
        }
    }
}

//Function to find mean
double findMean(int nums[], int total)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < total; i++)
    {
        sum += nums[i];
    }
    return (sum / total);
}

//Function to find median
double findMedian(int nums[], int total)
{
    int temp;
    int i, j;
    for (i = 0; i < total; i++)
        for (j = i + 1; j < total; j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    if (total % 2 == 0)
    {
        return (nums[total / 2] + nums[total / 2 - 1]) / 2;
    }
    else
    {
        return nums[total / 2];
    }
}

//Function to find mode
int findMode(int nums[], int total)
{
    int i, j, maxCount, modeValue;
    int tally[total];
    for (i = 0; i < total; i++)
    {
        tally[nums[i]]++;
    }
    maxCount = 0;
    modeValue = 0;
    for (j = 0; j < total; j++)
    {
        if (tally[j] > maxCount)
        {
            maxCount = tally[j];
            modeValue = j;
        }
    }
    return modeValue;
}

//Prints results and asks to redo
void results(double mean, double median, double mode)
{
    printf("Mean: %d\tMedian: %d\tMode: %i", mean, median, mode);
}

bool redo()
{
    char *temp;
    printf("\nWould you like to play again(Y/N)? ");
    scanf("%s", &temp);
    while (temp != 'n' && temp != 'N' && temp != 'y' && temp != 'Y')
    {
        printf("\nI am sorry that is invalid -- try again");
        printf("\nWould you like to play again(Y/N)? ");
        scanf("%s", &temp);
    }
    if (temp == 'y' || temp == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}