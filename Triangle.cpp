
// C++ program to count of acute, obtuse and right
// triangles in an array
#include "Headers.h"
using namespace std;

// Find the number of acute, right, obtuse triangle
// that can be formed from given array.
void findTriangle(int a[], int n)
{
    int b[n + 2];

    // Finding the square of each element of array.
    for (int i = 0; i < n; i++)
        b[i] = a[i] * a[i];

    // Sort the sides of array and their squares.
    sort(a, a + n);
    sort(b, b + n);

    // x for acute triangles
    // y for right triangles
    // z for obtuse triangles
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        int p = i + 1;
        int q = i + 1;

        for (int j = i + 1; j < n; j++)
        {
            // Finding the farthest point p where
            // a^2 + b^2 >= c^2.
            while (p < n - 1 && b[i] + b[j] >= b[p + 1])
                p++;

            q = max(q, p);

            // Finding the farthest point q where
            // a + b > c.
            while (q < n - 1 && a[i] + a[j] > a[q + 1])
                q++;

            // If point p make right triangle.
            if (b[i] + b[j] == b[p])
            {
                // All triangle between j and p are acute
                // triangles. So add p - j - 1 in x.
                x += max(p - j - 1, 0);

                // Increment y by 1.
                y++;

                // All triangle between q and p are acute
                // triangles. So add q - p in z.
                z += q - p;
            }

            // If no right triangle
            else
            {
                // All triangle between j and p are acute
                // triangles. So add p - j in x.
                x += max(p - j, 0);

                // All triangle between q and p are acute
                // triangles. So add q - p in z.
                z += q - p;
            }
        }
    }

    cout << "Acute Triangle: " << x << endl;
    cout << "Right Triangle: " << y << endl;
    cout << "Obtuse Triangle: " << z << endl;
}

// Driver Code
int main()
{
    int arr[] = {2, 3, 9, 10, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    findTriangle(arr, n);
    return 0;
}