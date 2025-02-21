#include <stdio.h>
#include <string.h>

void calculate_electricity_bill() {
    char customer_name[100];
    char customer_id[50];
    int units_consumed;
    float fixed_charge = 100;
    float base_bill = fixed_charge;
    float surcharge = 0;
    float total_bill;

    printf("Enter Customer Name: ");
    scanf(" %[^\n]s", customer_name); // Note the space before % in scanf

    printf("Enter Customer ID: ");
    scanf(" %[^\n]s", customer_id); // Note the space before % in scanf

    printf("Enter Total Units Consumed: ");
    scanf("%d", &units_consumed);

    if (units_consumed <= 100) {
        base_bill += units_consumed * 5;
    } else if (units_consumed <= 300) {
        base_bill += 100 * 5 + (units_consumed - 100) * 7;
    } else {
        base_bill += 100 * 5 + 200 * 7 + (units_consumed - 300) * 10;
    }

    if (base_bill > 1000) {
        surcharge = base_bill * 0.05;
    }

    total_bill = base_bill + surcharge;

    printf("\nCustomer Name: %s\n", customer_name);
    printf("Customer ID: %s\n", customer_id);
    printf("Units Consumed: %d\n", units_consumed);
    printf("Base Bill: ₹%.2f\n", base_bill); // Format to 2 decimal places
    printf("Surcharge: ₹%.2f\n", surcharge);
    printf("Total Bill: ₹%.2f\n", total_bill); // Format to 2 decimal places
}

int main() {
    calculate_electricity_bill();
    return 0;
}
