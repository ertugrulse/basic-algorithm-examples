#include <stdio.h>

double calculateTicketPrice(int, int, int);
double applyStudentDiscount(double, int);

int main()
{
    int age, dayOfWeek, isStudent;
    double price;

    // Input details from the user
    printf("Enter the age of the person: ");
    scanf("%d", &age);

    printf("Enter the day of the week (1=Monday, 2=Tuesday, ..., 7=Sunday): ");
    scanf("%d", &dayOfWeek);

    printf("Is the person a student? (1 for Yes, 0 for No): ");
    scanf("%d", &isStudent);

    // Calculate the ticket price for this person
    price = calculateTicketPrice(age, dayOfWeek, isStudent);

    // Apply student discount if applicable
    price = applyStudentDiscount(price, isStudent);

    // Output the final price
    printf("The final ticket price is: %.2f liras\n", price);

    return 0;
}
// Function to calculate the ticket price for one person based on age and day of the week
double calculateTicketPrice(int age, int dayOfWeek, int isStudent)
{

    double price = 20.0; // Base price for the ticket

    if (age < 12)
    {
        price = 10.0; // Yaş 12'den küçükse bilet fiyatı 10'a eşit
    }
    else if (age > 60)
    {
        price = 15.0; // Yaş 60'tna büyükse bilet fiyatı 15'e eşit
    }

    if (dayOfWeek == 3)
    {
        price -= 5.0; // dayOfWeek 3'e eşitse yani çarşamba ise price'tan 5 birim düşürdüm
    }

    return price; // En son price geri çağırılır
}

double applyStudentDiscount(double price, int isStudent)
{

    if (isStudent == 1)
    {
        price -= 5.0; // Bu kısımda isStudent 1'e eşitse yani kullanıcı
    } // öğrenci ise price'tan 5 birim düşülür

    return price; // price geri çağırılır 0 ise zaten indirim uygulanmamış oluyo
}
