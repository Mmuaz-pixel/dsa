#include <iostream>
#include <algorithm>
#include <limits.h>
#include <time.h>

using namespace std; 

// Data structure to store grades
struct Grade
{
    string studentName;
    string courseName;
    int grade;
};
// Partition function for quicksort
int partition(Grade arr[], int low, int high)
{
    int pivot = arr[high].grade;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].grade >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(Grade arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array
        int pivot = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}


// Function to compare grades for sorting
bool compareGrades(const Grade &a, const Grade &b)
{
    return a.grade > b.grade; // Sorting in descending order
}

// Function to merge sorted grade lists
void mergeGradeLists(Grade mergedList[], Grade sortedLists[][40], int numCourses, int courseSize[])
{
    int mergedIndex = 0;

    // Merge sorted lists
    for (int i = 0; i < numCourses; ++i)
    {
        copy(sortedLists[i], sortedLists[i] + courseSize[i], mergedList + mergedIndex);
        mergedIndex += courseSize[i];
    }

    // Sort the merged list based on grades
    sort(mergedList, mergedList + mergedIndex, compareGrades); // using intro sort (default sorting algo)
}

// Function to generate a random grade between 50 and 100
int generateRandomGrade()
{
    return rand() % 51 + 50;
}

// Function to fill the grade list with random data
void fillGradeList(Grade gradeList[], const string &courseName, int numStudents)
{
    for (int i = 0; i < numStudents; ++i)
    {
        gradeList[i].studentName = "Student" + to_string(i + 1);
        gradeList[i].courseName = courseName;
        gradeList[i].grade = generateRandomGrade();
    }
}

// Function to calculate the minimum cost trip
int calculateMinimumCostTrip(int cost[], int n)
{
    int dp[n];
    dp[0] = 0;

    // Dynamic programming to calculate minimum cost
    for (int i = 1; i < n; ++i)
    {
        dp[i] = INT_MAX; // infinity 
        for (int j = 0; j < i; ++j)
        {
            dp[i] = min(dp[i], dp[j] + abs(i - j) * cost[i]); // finding shortest path
        }
    }

    // Minimum cost to reach the (N + 1)th city
    return dp[n - 1];
}

int main()
{
    // Sample data - Replace this with your own dataset
    const int numCourses = 3;
    const int maxStudentsPerCourse = 40;

    // Seed for random number generation
    srand(time(0));

    Grade gradeLists[numCourses][maxStudentsPerCourse];

    int courseSize[numCourses] = {40, 40, 40};

    // Filling grades for each course
    for (int i = 0; i < numCourses; ++i)
    {
        fillGradeList(gradeLists[i], "Course" + std::to_string(i + 1), maxStudentsPerCourse);
    }

    // Sort each individual list of grades
    for (int i = 0; i < numCourses; ++i)
    {
        quicksort(gradeLists[i], 0, courseSize[i]-1); // using quicksort for sorting 
    }

    // Merge all lists
    const int totalStudents = 120; // Update accordingly
    Grade mergedList[totalStudents];
    mergeGradeLists(mergedList, gradeLists, numCourses, courseSize);

    // Display the merged list
    cout << "Merged List (Student Name, Course Name, Grade):\n";
    for (int i = 0; i < totalStudents; ++i)
    {
        cout << mergedList[i].studentName << ", " << mergedList[i].courseName << ", " << mergedList[i].grade << "\n";
    }

    // Implement the second part of the lab task - Minimum Cost Trip
    int cityCost[] = {150, 300, 190, 210, 170};  // cost data
    int minCost = calculateMinimumCostTrip(cityCost, sizeof(cityCost) / sizeof(cityCost[0]));
    cout << "Minimum Cost to Travel: $" << minCost << "\n";

    return 0;
}
