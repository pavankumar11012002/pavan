#include <stdio.h>
#include <stdlib.h>

#define MAX_AMBULANCES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance;
} Ambulance;

// Selection sort function
void selectionSort(Ambulance ambulances[], int numAmbulances) {
    for (int i = 0; i < numAmbulances - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numAmbulances; j++) {
            if (ambulances[j].distance < ambulances[minIndex].distance) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        Ambulance temp = ambulances[i];
        ambulances[i] = ambulances[minIndex];
        ambulances[minIndex] = temp;
    }
}

int main() {
    int numAmbulances;

    printf("Enter number of ambulances: ");
    scanf("%d", &numAmbulances);

    if (numAmbulances <= 0 || numAmbulances > MAX_AMBULANCES) {
        printf("Invalid number of ambulances.\n");
        return 1;
    }

    Ambulance ambulances[MAX_AMBULANCES];

    printf("Enter ambulance data (Name, Distance):\n");
    for (int i = 0; i < numAmbulances; i++) {
        printf("Ambulance %d:\n", i + 1);
        printf("Name: ");
        // Consume newline left by scanf
        getchar(); // Important to prevent issues with fgets
        fgets(ambulances[i].name, MAX_NAME_LENGTH, stdin);
        ambulances[i].name[strcspn(ambulances[i].name, "\n")] = 0; //Remove trailing newline

        printf("Distance (km): ");
        scanf("%d", &ambulances[i].distance);
    }

    // Sort ambulances by distance
    selectionSort(ambulances, numAmbulances);

    printf("\nSorted Ambulances (by distance):\n");
    for (int i = 0; i < numAmbulances; i++) {
        printf("%s - %d km\n", ambulances[i].name, ambulances[i].distance);
    }

    if (numAmbulances > 0) {
        printf("\nNearest Ambulance Assigned: %s - Distance %d km\n", ambulances[0].name, ambulances[0].distance);
    }

    return 0;
}
