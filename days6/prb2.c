#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
} Product;

// Comparison function for qsort (ascending order of price)
int comparePrices(const void *a, const void *b) {
    return ((Product *)a)->price - ((Product *)b)->price;
}

// Binary search function (assumes records are sorted by name)
int binarySearch(Product products[], int numProducts, const char *searchName) {
    int low = 0, high = numProducts - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int comparison = strcasecmp(products[mid].name, searchName); //Case-insensitive comparison
        if (comparison == 0) {
            return mid; // Found
        } else if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int numProducts;

    printf("Enter number of products: ");
    scanf("%d", &numProducts);

    if (numProducts <= 0 || numProducts > MAX_PRODUCTS) {
        printf("Invalid number of products.\n");
        return 1;
    }

    Product products[MAX_PRODUCTS];

    printf("Enter product data:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: ");
        // Consume newline left by scanf
        getchar(); // Important to prevent issues with fgets
        fgets(products[i].name, MAX_NAME_LENGTH, stdin);
        products[i].name[strcspn(products[i].name, "\n")] = 0; //Remove trailing newline

        printf("Price: ");
        scanf("%d", &products[i].price);
    }

    // Sort by price (ascending)
    qsort(products, numProducts, sizeof(Product), comparePrices);

    printf("\nSorted by Price:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s (%d)", products[i].name, products[i].price);
        if (i < numProducts -1) printf(", "); //Add comma unless it's the last element
    }
    printf("\n");

    // Display cheapest and most expensive products
    if (numProducts > 0) {
        printf("\nCheapest Product: %s (%d)\n", products[0].name, products[0].price);
        printf("Most Expensive Product: %s (%d)\n", products[numProducts - 1].name, products[numProducts - 1].price);
    }

    // Search by name
    char searchName[MAX_NAME_LENGTH];
    printf("\nEnter product name to search: ");
    getchar(); // Consume newline
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; //Remove trailing newline

    int index = binarySearch(products, numProducts, searchName);
    if (index != -1) {
        printf("Found (%s, Price: %d)\n", products[index].name, products[index].price);
    } else {
        printf("Product not found.\n");
    }

    return 0;
}
