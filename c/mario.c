#include <stdio.h>
#include <cs50.h>

// Implement a program that that prints out a 
//   double half-pyramid of a specified height.

void halfpyramid(int n);
void midspace(int n);
void leftspace(int i, int n);
void pyramid(int n);

int main(void)
{
    printf("Height:");
    int n = get_int();
    if (n == 0)
    {
        return 0;
    }
    else if (n < 0)
    {
        while (n < 0 || n > 23)
        {
            printf("Height:");
            n = get_int();
        }
        
         pyramid(n);
    }
    
    else if (n > 0)
    {
        while (n < 0 || n > 23)
        {
            printf("Height:");
            n = get_int();
        }
        
        pyramid(n);
        
    }
}

void halfpyramid(int n)
{
    for (int i = 1; i < n+1; i++)
    {
        printf("#");
    }
}


void midspace(int n)
{
    for (int i = n-1; i < n; i++)
    {
        printf("  ");
    }
}

void leftspace(int i, int n)
{
    for (int k = 0; k < n-i; k++)
    {
        printf(" ");
    }
}

void pyramid(int n)
{
    for (int i = 1; i <= n; i++)
        {
            leftspace(i,n);
            halfpyramid(i);
            midspace(i);
            halfpyramid(i);
            printf("\n");
        }
}
