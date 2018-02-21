#include <cs50.h>
#include <stdio.h>

// Implement a program that determines whether a 
// provided credit card number is valid according to Luhn’s algorithm.
// A key idea here is that the nth to last digit is num/(ten_power(n-1)) % 10 for n < 10.

int length(long long n);
int split_num_sum(int n);
int ten_power(int m);
bool luhn_alg(long long n);
bool is_amex(long long n);
bool is_master(long long n);
bool is_visa(long long n);
long long first_num(long long n);
long long second_num(long long n);
long long first_kth_nums(long long n, int k);
long long last_kth_nums(long long n, int k);

int main(void)
{
    printf("Number:");
    long long num = get_long_long();
    int numlength = length(num);

    if (num < 0 || numlength > 16 ||  numlength < 13 || numlength == 14)
    {
        printf("INVALID\n");
    }
    
     else if (numlength == 13)
    {
        is_visa(num);
    }
    
    else if (numlength == 15)
    {
        is_amex(num);
    }
    
    else if (numlength == 16 && is_visa(num))
    {
        
    }
    else if (numlength == 16 && is_master(num))
    {
        
    }

    else 
    {
        printf("INVALID\n");
    }

}

int length(long long n)
{
    int i=0;
    while (n > 0)
        {
            n = n/10;
            i++;
        }
        
    return i;
}


int split_num_sum(int n)
{
    
    if (n == 10)
    {
        return 1;
    }
    else if ((n/10) % 10 == 0) // n a single digit
    {
        return n;
    }
    else 
    {
        return ((n%10)+((n/10)%10)); // two digits added together
    }
        
}

int ten_power(int m)
{
    long long power = 1;
    
    for (int i = 1; i <= m; i++)
    {
        power = power*10;
    }
    return power;
}

bool luhn_alg(long long n)
{
    int luhn_num; 
    int every_other_sum = 0;
    int other_every_other_sum = 0;
    if (length(n) == 13)
    {
        every_other_sum = 0;
        for (int i = 1; i < 4; i++)
        {
            every_other_sum = every_other_sum+ split_num_sum(2*first_kth_nums(n,2i))+split_num_sum(2*last_kth_nums(n,2i));
        }
        
        other_every_other_sum = split_num_sum(first_kth_nums(n,7));
        for (int i = 0; i < 3; i++)
        {
            other_every_other_sum = other_every_other_sum + split_num_sum(first_kth_nums(n,2*i+1))+split_num_sum(last_kth_nums(n,2*i+1));
        }
    }
    
    else if (length(n) == 15)
    {
        every_other_sum = split_num_sum(2*last_kth_nums(n,(length(n)+1)/2));
        for (int i = 1; i < 4; i++)
        {
            every_other_sum = every_other_sum+ split_num_sum(2*first_kth_nums(n,2*i))+split_num_sum(2*last_kth_nums(n,2*i));
        }

        other_every_other_sum = split_num_sum(last_kth_nums(n,9))+ split_num_sum(last_kth_nums(n,7));
        for (int i = 0; i < 3; i++)
        {
            other_every_other_sum = other_every_other_sum + split_num_sum(first_kth_nums(n,2*i+1))+split_num_sum(last_kth_nums(n,2*i+1));
        }
    }
    
    else if (length(n) == 16)
    {
        every_other_sum = 0;
        for (int i = 0; i < 4; i++)
        {
            every_other_sum = every_other_sum+ split_num_sum(2*first_kth_nums(n,2*i+1))+split_num_sum(2*last_kth_nums(n,2*i+2));
        }

        other_every_other_sum = split_num_sum(last_kth_nums(n,9))+ split_num_sum(last_kth_nums(n,7));
        for (int i = 0; i < 3; i++)
        {
            other_every_other_sum = other_every_other_sum + split_num_sum(first_kth_nums(n,2*i+2))+split_num_sum(last_kth_nums(n,2*i+1));
        }
    }
    
    luhn_num = (every_other_sum + other_every_other_sum) % 10;

    if (luhn_num == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

bool is_amex(long long n)
{
    if ((first_num(n) == 3 && second_num(n) == 4 && luhn_alg(n)))
    {
        printf("AMEX\n");
        return true;
    }
    else if ((first_num(n) == 3 && second_num(n) == 7 && luhn_alg(n)))
    {
        printf("AMEX\n");
        return true;
    }
    else
    {
        return false;
    }
}

bool is_master(long long n)
{
    if (first_num(n) == 5)
    {
        if ((second_num(n) == 1 || second_num(n) == 2 || second_num(n) == 3 || second_num(n) == 4 || second_num(n) == 5 ) && luhn_alg(n))
        {
            printf("MASTERCARD\n");
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool is_visa(long long n)
{
    if ( (first_num(n) == 4 && luhn_alg(n)) || (first_num(n) == 4 && luhn_alg(n)) )
    {
        printf("VISA\n");
        return true;
    }
    else
    {
        return false;
    }
}

long long first_num(long long n)
{
    return first_kth_nums(n,1); // first number of n
}

long long second_num(long long n)
{
    return first_kth_nums(n,2); // second number of n
}

long long first_kth_nums(long long n, int k) // gets digits 1,2,..., length(num)-9
{
    long long newnum = n/ten_power(9); // truncate num to first length(num)-9 digits
    int truncatenum_length = length(n)-9; 
    return newnum/ten_power(truncatenum_length-k) % 10; // kth number of n
}

long long last_kth_nums(long long n, int k) // length(num)-8, length(num)-7,..., length(num)
{
    return n/(ten_power(k-1)) % 10; // 
}
