#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef union {
    float daily_rent;
    float total_rent;
} Rent;
typedef struct {
    int id;
    char model[50];
    Rent rent;
    int rent_type; 
} Car;
void save_to_file(Car cars[], int count) {
    FILE *file = fopen("car_rentals.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;}
    for (int i = 0; i < count; i++) {
        if (cars[i].rent_type == 0) {
            fprintf(file, "%d, %s, ₹%.2f/day\n", cars[i].id, cars[i].model, cars[i].rent.daily_rent);
        } else {
            fprintf(file, "%d, %s, ₹%.2f (total rent)\n", cars[i].id, cars[i].model, cars[i].rent.total_rent);
        }
    }
    fclose(file);
    printf("Data saved in \"car_rentals.txt\".\n");
}
void update_rental_info(Car *car) {
    printf("Update rental information for %s (ID: %d)\n", car->model, car->id);
    printf("Enter 0 for daily rent or 1 for total rent: ");
    scanf("%d", &car->rent_type);
    if (car->rent_type == 0) {
        printf("Enter daily rent: ₹");
        scanf("%f", &car->rent.daily_rent);
    } else {
        printf("Enter total rent: ₹");
        scanf("%f", &car->rent.total_rent);
    }
}
int main() {
    int count;
    printf("Enter number of cars: ");
    scanf("%d", &count);
    Car cars[count];
    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &cars[i].id);
        printf("Model: ");
        scanf(" %[^\n]s", cars[i].model);
        update_rental_info(&cars[i]);
    }
    printf("\nCars Available:\n");
    for (int i = 0; i < count; i++) {
        if (cars[i].rent_type == 0) {
            printf("%d. %s - ₹%.2f/day\n", i + 1, cars[i].model, cars[i].rent.daily_rent);
        } else {
            printf("%d. %s - ₹%.2f (total rent)\n", i + 1, cars[i].model, cars[i].rent.total_rent);
        }
    }
    save_to_file(cars, count);
    return 0;
}
