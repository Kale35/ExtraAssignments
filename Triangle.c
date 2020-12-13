#include <stdio.h>

int main(void)
{
    double a, b, c;

    //Gets user input for each side
    printf("Enter a base: \n");
    scanf("%lf", &a);

    printf("Enter a perpendicular side: \n");
    scanf("%lf", &b);

    printf("Enter an hypotenuse: \n");
    scanf("%lf", &c);

    //Gets values of all sides squared
    double aandbSquared = pow(a, 2) + pow(b, 2);

    double cSquared = pow(c, 2);

    //Checks each case if the triangle is right, acute, or obtuse
    if (aandbSquared == cSquared)
    {
        printf("Right Triangle\n");
    }
    else if (aandbSquared > cSquared)
    {
        printf("Acute Triangle\n");
    }
    else if (aandbSquared < cSquared)
    {
        printf("Obtuse Triangle");
    }

    return 0;
}