#include <cs50.h>
#include <stdio.h>

// Implement a program that reports a user’s water
//   usage, converting minutes spent in the shower 
//   to bottles of drinking water.

int main(void)
{
    printf("How long was your shower (in minutes)?\n");
    int i = get_int();
        printf("Minutes: %i\nBottles: %i\n", i, 12*i);
}
