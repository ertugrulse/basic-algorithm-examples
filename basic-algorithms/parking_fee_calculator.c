#include <stdio.h>

int calculateTotalMinutes(int, int, int, int);
double calculateParkingFee(int);

int main(void)
{

    // Variables for entry and exit times
    int entryHour, entryMinute;
    int exitHour, exitMinute;
    // Total parking duration in minutes
    int totalMinutes;
    // Parking fee to be calculated
    double parkingFee;

    // Get entry time
    printf("Enter entry time (HH MM): ");
    scanf("%d %d", &entryHour, &entryMinute);

    // Get exit time
    printf("Enter exit time (HH MM): ");
    scanf("%d %d", &exitHour, &exitMinute);

    // Calculate the total minutes of parking
    totalMinutes = calculateTotalMinutes(entryHour, entryMinute, exitHour, exitMinute);

    // Calculate the parking fee
    parkingFee = calculateParkingFee(totalMinutes);

    // Display the result
    printf("Total parking time: %d minutes\n", totalMinutes);
    printf("Parking fee: %.2lf Liras\n", parkingFee);

    return 0;
}

// Function to calculate total parking duration in minutes
int calculateTotalMinutes(int entryHour, int entryMinute, int exitHour, int exitMinute)
{
    int entryLastMinute = entryHour * 60 + entryMinute; // giriş saatini dakikaya çevirir
    int exitLastMinute = exitHour * 60 + exitMinute;    // çıkış saatini dakikaya çevirir

    if (exitLastMinute < entryLastMinute)
    {                              // çıkış saati giriş saatinden küçükse yani ertesi güne geçilirse
        exitLastMinute += 24 * 60; // 1 gün yani 1440 dakika eklenir
    }

    return exitLastMinute - entryLastMinute; // toplam süre hesaplanır
}

// Function to calculate parking fee based on total parking time in minutes
double calculateParkingFee(int totalMinutes)
{
    if (totalMinutes == 0)
    { // süre sıfırsa ücret 0 olur
        return 0.0;
    }
    else if (totalMinutes <= 30)
    { // 30'a eşit veya daha küçükse de ücret 0 olur
        return 0.0;
    }
    else if (totalMinutes <= 60)
    { // 60'a eşit veya daha küçükse ücret 10 olur
        return 10.0;
    }
    else if (totalMinutes <= 120)
    {                                                  // park süresi 120 dakikaya eşit veya daha kısa ise:
        int extraMinutes = totalMinutes - 69;          //
        int extraTenMinutes = (extraMinutes + 9) / 10; //(extraMinutes+9) işlemi 10'a yuvarlanır daha sonra 10'a bölerek ekstra miktarı belirlenir
        return 10.0 + extraTenMinutes * 3.0;           // 10.0 birim ilk 60 dakika, ekstra her 10 dakika başına 3 birim.
    }
    else if (totalMinutes <= 300)
    {
        int extraMinutes = totalMinutes - 129; // yukardaki işlemin benzeri burda da geçerli
        int extraTenMinutes = (extraMinutes + 9) / 10;
        return 40.0 + extraTenMinutes * 5.0;
    }
    else
    {
        return 100.0; // bir üstteki else if geçersiz ise yani dakika 300'den büyükse
    } // toplam ücret 100 olur
}
