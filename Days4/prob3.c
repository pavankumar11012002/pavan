#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "payroll.txt"
typedef struct {
    int empID;
    char name[50];
    float basicSalary;
    float allowances;
    float grossSalary;
} Employee;

void calculateGrossSalary(Employee *emp) {
    emp->grossSalary = emp->basicSalary + emp->allowances;
}
void savePayrollToFile(Employee employees[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f,%.2f,%.2f\n", 
                employees[i].empID, employees[i].name, 
                employees[i].basicSalary, employees[i].allowances, 
                employees[i].grossSalary);
    }
    fclose(file);
    printf("Payroll records saved in \"%s\"\n", FILENAME);
}
void searchEmployee(int searchID) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file! No payroll data found.\n");
        return;
    }
    Employee emp;
    int found = 0;
    while (fscanf(file, "%d,%49[^,],%f,%f,%f\n", 
                  &emp.empID, emp.name, 
                  &emp.basicSalary, &emp.allowances, &emp.grossSalary) != EOF) {
        if (emp.empID == searchID) {
            printf("\nEmployee: %s\n", emp.name);
            printf("Gross Salary: ₹%.2f\n", emp.grossSalary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee ID %d not found!\n", searchID);
    }
    fclose(file);
}
int main() {
   int numEmployees;
    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    getchar(); 
    Employee employees[numEmployees];
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("Emp ID: ");
        scanf("%d", &employees[i].empID);
        getchar();
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;
        printf("Basic Salary: ₹");
        scanf("%f", &employees[i].basicSalary);
        printf("Allowances: ₹");
        scanf("%f", &employees[i].allowances);
        calculateGrossSalary(&employees[i]);
    }
    savePayrollToFile(employees, numEmployees);
    int searchID;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);
    searchEmployee(searchID);

    return 0;
}
