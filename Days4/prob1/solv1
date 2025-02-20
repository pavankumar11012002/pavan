#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char expiry_date[11]; // Format: YYYY-MM-DD
    float price;
} Medicine;

void sort_by_expiry_date(Medicine meds[], int count) {
    Medicine temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(meds[i].expiry_date, meds[j].expiry_date) > 0) {
                temp = meds[i];
                meds[i] = meds[j];
                meds[j] = temp;
            }
        }
    }
}

void save_to_file(Medicine meds[], int count) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, %s, ₹%.2f\n", meds[i].id, meds[i].name, meds[i].expiry_date, meds[i].price);
    }

    fclose(file);
    printf("Records saved in \"medicine_inventory.txt\".\n");
}

int main() {
    int count;
    printf("Enter number of medicines: ");
    scanf("%d", &count);

    Medicine meds[count];
    for (int i = 0; i < count; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &meds[i].id);
        printf("Name: ");
        scanf(" %[^\n]s", meds[i].name);
        printf("Expiry Date (YYYY-MM-DD): ");
        scanf("%s", meds[i].expiry_date);
        printf("Price: ₹");
        scanf("%f", &meds[i].price);
    }

    sort_by_expiry_date(meds, count);

    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, meds[i].name, meds[i].expiry_date);
    }

    save_to_file(meds, count);

    return 0;
}
