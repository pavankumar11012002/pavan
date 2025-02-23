#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int rollNo;
    char name[MAX_NAME_LENGTH];
    int marks;
} Student;

// Comparison function for qsort (descending order of marks)
int compareMarks(const void *a, const void *b) {
    return ((Student *)b)->marks - ((Student *)a)->marks;
}

// Binary search function (assumes records are sorted by rollNo)
int binarySearch(Student students[], int numStudents, int searchRollNo) {
    int low = 0, high = numStudents - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].rollNo == searchRollNo) {
            return mid; // Found
        } else if (students[mid].rollNo < searchRollNo) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int numStudents;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    Student students[MAX_STUDENTS];

    printf("Enter student data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        // Consume newline left by scanf
        getchar(); // Important to prevent issues with fgets
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; //Remove trailing newline

        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Sort by marks (descending)
    qsort(students, numStudents, sizeof(Student), compareMarks);

    printf("\nSorted by Marks:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s (%d)", students[i].name, students[i].marks);
        if (i < numStudents -1) printf(", "); //Add comma unless it's the last element
    }
    printf("\n");

    // Display top 3 students
    int numToDisplay = (numStudents < 3) ? numStudents : 3; //Handle cases where there are less than 3 students
    printf("\nTop %d Students:\n", numToDisplay);
    for (int i = 0; i < numToDisplay; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }


    // Search by roll number
    int searchRollNo;
    printf("\nEnter roll number to search: ");
    scanf("%d", &searchRollNo);

    int index = binarySearch(students, numStudents, searchRollNo);
    if (index != -1) {
        printf("Found (%s, Marks: %d)\n", students[index].name, students[index].marks);
    } else {
        printf("Roll number not found.\n");
    }

    return 0;
}
