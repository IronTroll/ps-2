#include <stdio.h>
#include<math.h>

//1.uloha
/*
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return ((double)stick_length * (double)human_weight / ((double)human_weight + (double)car_weight));
}
*/
//2.uloha
float unit_price(const float pack_price, const int rolls_count, const int pieces_count)
{
    return (pack_price / (pieces_count * rolls_count) * 100);
}

//3.uloha
int collatz(int number)
{
    int count = 1;
    while (number != 1)
    {
        if (number % 2 == 0)
            number /= 2;
        else
            number = (number * 3) + 1;
        count++;
    }
    return count;
}

// 4.uloha
int opposite_number(int n, int number)
{
    int length = n / 2;
    if (length > number)
        number += length;
    else
        number -= length;
    return number;
}

//5.uloha
void counter(const int input_array[], const int array_size, int result_array[2])
{
    int p = 0, n = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (i % 2 == 0)
            p += input_array[i];
        else
            n += input_array[i];
    }
    result_array[0] = p;
    result_array[1] = n;
}

//6.uloha
unsigned long sum_squared(int line)
{
    unsigned long sucet = 0;
    unsigned long x = 1;
    for (int i=0; i<=line; i++)
    {
        x = x*(line-i+1)/i;
        sucet+=pow(x,2);
    }
    return sucet;   
}

/*
unsigned long sum_squared(int line)
{
    unsigned long sucet = 0;
    unsigned long x = 1;
    line += 1;
    for (long int k = 1; k <= line; k++)
    {
        sucet += pow(x, 2);
        x = x * (line - k) / k;
    }
    return sucet;
}
*/

// 7.uloha
int array_min(int input_array[], const int array_size)
{
    int min = 1000000;

    if (input_array == NULL)
        return -1;
    else
    {
        for (int i = 0; i < array_size; i++)
        {
            if (input_array[i] < min)
                min = input_array[i];
        }
        return min;
    }
}
int array_max(int input_array[], const int array_size)
{
    int max = 0;

    if (input_array == NULL)
        return -1;
    else
    {
        for (int i = 0; i < array_size; i++)
        {
            if (input_array[i] > max)
                max = input_array[i];
        }
        return max;
    }
}

// 8.uloha
unsigned long special_counter(const int input_array[], const int array_size)
{
    int sucet = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (i % 2 != 0)
            sucet += pow(input_array[i], 2);
        else
            sucet += input_array[i];
    }
    return sucet;
}

// 9.uloha

int special_numbers(const int input_array[], const int array_size, int result_array[])
{
    int special = 0, j = 0;
    for (int i = 0; i < array_size; i++)
    {
        int sucet = 0;
        for (int k = i + 1; k < array_size; i++)
        {
            sucet += input_array[k];
        }
        if (input_array[i] > sucet)
        {
            special++;
            result_array[j] = input_array[i];
            j++;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    //1.uloha
    /*
    int a,b,c;
    printf("Zadaj dlzku tyce:\n");
    scanf("%d",&a);
    printf("Zadaj vahu cloveka:\n");
    scanf("%d",&b);
    printf("Zadaj vahu auta:\n");
    scanf("%d",&c);

    printf("%.2f",lift_a_car(a,b,c));
    */
    /////////////////////////////////////////////
    /*2.uloha
    int rc, pc;
    float pp;
    printf("Zadajte cenu za balenie:\n");
    scanf("%f", &pp);
    printf("Zadajte pocet kotucov:\n");
    scanf("%d", &rc);
    printf("Pocet utrzkov v kotuci:\n");
    scanf("%d", &pc);
    printf("Jednotkova cena je: %.2f", unit_price(pp, rc, pc));
    */

    // 3. uloha
    printf("%lu\n", sum_squared(1));
    // prints: 2
    printf("%lu\n", sum_squared(4));
    // prints: 70
    printf("%lu\n", sum_squared(33));
}