#include <iostream>
#include <ctime>
#include "numbers.dat"

int binary_search(int const arr[], int arr_sz, int needed_num);
int find_alike(int const arr[], int arr_sz, int pos, int dir);
int is_a_prime(int num);
int count_primes(int const arr[], int arr_sz, int left_pos, int right_pos);

/* As we know that numbers in that array can't go higher than 100 000, we can
   use a list of primes from 2 to sqrt (100 000) for quicker prime checks */
const int PossiblePrimes[] = {
    2,		3,		5,		7,		11,		13,		17,		19,		23,		29,
    31,		37,		41,		43,		47,		53,		59,		61,		67,		71,
    73,		79,		83,		89,		97,		101,	103,	107,	109,	113,
    127,	131,	137,	139,	149,	151,	157,	163,	167,	173,
    179,	181,	191,	193,	197,	199,	211,	223,	227,	229,
    233,	239,	241,	251,	257,	263,	269,	271,	277,	281,
    283,	293,	307,	311,	313 };
const int PossiblePrimesSize = sizeof(PossiblePrimes) / sizeof(PossiblePrimes[0]);

int
main(int argc, char *argv[])
{
    /* Note: Data[] and Size loaded from "numbers.dat" */
    int start_num,  s_pos;
    int finish_num, f_pos;

    /* we require an even number of arguments */
    if((argc % 2) && (argc > 1))
    {
        /* looping through pairs of arguments */
        for (int i = 1; i < argc; i += 2)
        {
            start_num  = std::atoi(argv[i]);
            finish_num = std::atoi(argv[i + 1]);
            /* if impossible interval, print 0 and skip */
            if(start_num > finish_num)
            {
                printf("0\n");
                continue;
            }
            
            /* searching indexes of specified numbers */
            s_pos = binary_search(Data, Size, start_num);
            f_pos = binary_search(Data, Size, finish_num);

            /* if indexes don't meet this: 0 <= s_pos <= f_pos < Size,
               then print out 0 and don't do any further calculations */
            if((f_pos >= Size) || (s_pos > f_pos) || (s_pos < 0))
                printf("0\n");
            else
            {
                /* widening the interval */
                s_pos = find_alike(Data, Size, s_pos, -1);
                f_pos = find_alike(Data, Size, f_pos, 1);
                printf("%d\n", count_primes(Data, Size, s_pos, f_pos));
            }
        }
        return 0;
    }
    else
        return -1;
}

/* binary_search()
 * Returns needed element's index in arr.
 * If doesn't find needed element, returns -1.
 * Takes - 1D sorted array(arr[]) + its size(arr_sz),
 *       - search borders(low, high),
 *       - number to search(needed).
 */
int
binary_search(int const arr[], int arr_sz, int needed_num)
{
    int mid, low = 0, high = arr_sz - 1;
    int curr_num;
    while(1)
    {
        mid = (low + high) / 2;
        curr_num = arr[mid];
        if(needed_num > curr_num)
            low  = mid + 1;
        else if(needed_num < curr_num)
            high = mid - 1;
        else return mid;

        if(low > high) return -1;
    }
}

/* find_alike()
 * If dir  =  1, finds LAST element equal to arr[pos]
 * If dir  = -1, finds FIRST element equal to arr[pos]
 * in 1D sorted array arr[] and returns its index.
 */
int
find_alike(int const arr[], int arr_sz, int pos, int dir)
{
    if((pos >= arr_sz) || (pos < 0))
        return -1;

    int needed_num = arr[pos];
    do pos += dir;
    while ((pos < arr_sz) && (pos >= 0) && (arr[pos] == needed_num));
    return (pos - dir);
}

/* is_a_prime()
 * Returns 1 if num is prime, 0 if num is NOT prime.
 */
int
is_a_prime(int num)
{
    if(num < 2)
        return 0;
    for(int i = 0; i < PossiblePrimesSize; i++)
       if((num > PossiblePrimes[i]) && (num % PossiblePrimes[i] == 0))
          return 0;
    return 1;
}

/* count_primes()
 * Returns number of primes in interval of indexes
 * [left_pos, right_pos] for array arr[] of size arr_sz.
 */
int
count_primes(int const arr[], int arr_sz, int left_pos, int right_pos)
{
    int rez = 0;
    int curr_num = -1;
    int curr_is_prime;

    for(int i = left_pos; i <= right_pos; i++)
    {
        /* if haven't seen this number before, do prime check */
        if(arr[i] != curr_num)
        {
            curr_num = arr[i];
            curr_is_prime = is_a_prime(curr_num);
        }
        rez += curr_is_prime;
    }
    return rez;
}