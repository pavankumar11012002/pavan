#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_SIZE 100
#define MAX_ITEM_NAME_LENGTH 50

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
} Item;

typedef struct {
    Item items[MAX_STOCK_SIZE];
    int top;
} Stock;

void initializeStock(Stock *stock) {
    stock->top = -1;
}

void addStock(Stock *stock, const char *itemName) {
    if (stock->top < MAX_STOCK_SIZE - 1) {
        stock->top++;
        strcpy(stock->items[stock->top].name, itemName);
        printf("Stock Added: %s\n", itemName);
    } else {
        printf("Stock full!\n");
    }
}

void dispatchItem(Stock *stock) {
    if (stock->top >= 0) {
        printf("Dispatching Item: %s\n", stock->items[stock->top].name);
        stock->top--;
    } else {
        printf("No stock available!\n");
    }
}

void displayRemainingStock(Stock *stock) {
    if (stock->top >= 0) {
        printf("Remaining Stock: ");
        for (int i = 0; i <= stock->top; i++) {
            printf("%s", stock->items[i].name);
            if (i < stock->top) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("No stock remaining.\n");
    }
}

int main() {
    Stock warehouseStock;
    initializeStock(&warehouseStock);

    addStock(&warehouseStock, "Item A");
    addStock(&warehouseStock, "Item B");
    addStock(&warehouseStock, "Item C");

    dispatchItem(&warehouseStock);
    displayRemainingStock(&warehouseStock);

    addStock(&warehouseStock, "Item D");
    displayRemainingStock(&warehouseStock);

    dispatchItem(&warehouseStock);
    dispatchItem(&warehouseStock);
    dispatchItem(&warehouseStock);
    dispatchItem(&warehouseStock); //Try to dispatch when stock is empty

    return 0;
}
