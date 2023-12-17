#include <iostream>
#include <algorithm>
#include <limits.h>
#include <time.h>

// Data structure to store grades
struct Grade
{
    std::string studentName;
    std::string courseName;
    int grade;
};

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
        std::copy(sortedLists[i], sortedLists[i] + courseSize[i], mergedList + mergedIndex);
        mergedIndex += courseSize[i];
    }

    // Sort the merged list based on grades
    std::sort(mergedList, mergedList + mergedIndex, compareGrades);
}

// Function to generate a random grade between 50 and 100
int generateRandomGrade()
{
    return rand() % 51 + 50;
}

// Function to fill the grade list with random data
void fillGradeList(Grade gradeList[], const std::string &courseName, int numStudents)
{
    for (int i = 0; i < numStudents; ++i)
    {
        gradeList[i].studentName = "Student" + std::to_string(i + 1);
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
        dp[i] = INT_MAX;
        for (int j = 0; j < i; ++j)
        {
            dp[i] = std::min(dp[i], dp[j] + abs(i - j) * cost[i]);
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
    std::srand(time(0));

    Grade gradeLists[numCourses][maxStudentsPerCourse];

    int courseSize[numCourses] = {40,40,40}; 

    // Filling grades for each course
    for (int i = 0; i < numCourses; ++i)
    {
        fillGradeList(gradeLists[i], "Course" + std::to_string(i + 1), maxStudentsPerCourse);
    }

    // Sort each individual list of grades
    for (int i = 0; i < numCourses; ++i)
    {
        std::sort(gradeLists[i], gradeLists[i] + courseSize[i], compareGrades);
    }

    // Merge all lists
    const int totalStudents = 120; // Update accordingly
    Grade mergedList[totalStudents];
    mergeGradeLists(mergedList, gradeLists, numCourses, courseSize);

    // Display the merged list
    std::cout << "Merged List (Student Name, Course Name, Grade):\n";
    for (int i = 0; i < totalStudents; ++i)
    {
        std::cout << mergedList[i].studentName << ", " << mergedList[i].courseName << ", " << mergedList[i].grade << "\n";
    }

    // Implement the second part of the lab task - Minimum Cost Trip
    int cityCost[] = {2, 3, 1, 4}; // Replace with your own cost data
    int minCost = calculateMinimumCostTrip(cityCost, sizeof(cityCost) / sizeof(cityCost[0]));
    std::cout << "Minimum Cost to Travel: $" << minCost << "\n";

    return 0;
}
