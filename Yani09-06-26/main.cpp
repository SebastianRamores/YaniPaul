#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// ============================================================
// BUBBLE SORT
// Time Complexity:
// Best Case    : O(n) with optimization
// Average Case : O(n^2)
// Worst Case   : O(n^2)
// ============================================================

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped,
        // the array is already sorted.
        if (!swapped) {
            break;
        }
    }
}


// ============================================================
// MERGE FUNCTION
// Used by Merge Sort
// ============================================================

void merge(vector<int>& arr, int left, int middle, int right) {

    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge the two temporary arrays
    while (i < n1 && j < n2) {

        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left array
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements from right array
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}


// ============================================================
// MERGE SORT
// Time Complexity:
// Best Case    : O(n log n)
// Average Case : O(n log n)
// Worst Case   : O(n log n)
// ============================================================

void mergeSort(vector<int>& arr, int left, int right) {

    if (left < right) {

        int middle = left + (right - left) / 2;

        // Sort left half
        mergeSort(arr, left, middle);

        // Sort right half
        mergeSort(arr, middle + 1, right);

        // Merge the two halves
        merge(arr, left, middle, right);
    }
}


// ============================================================
// CHECK IF ARRAY IS SORTED
// ============================================================

bool isSorted(const vector<int>& arr) {

    for (size_t i = 1; i < arr.size(); i++) {

        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }

    return true;
}


// ============================================================
// CREATE SHUFFLED SEQUENTIAL DATASET
//
// Creates:
// 1, 2, 3, 4, ... size
//
// Then shuffles the numbers.
//
// Example:
// 1 2 3 4 5 6 7 8 9 10
//
// becomes something like:
// 7 2 10 1 5 9 3 8 6 4
// ============================================================

void createShuffledDataset(const string& filename, int size) {

    ofstream file(filename);

    if (!file) {
        cerr << "Error: Could not create " << filename << "\n";
        return;
    }

    vector<int> data;

    // Create sequential numbers
    for (int i = 1; i <= size; i++) {
        data.push_back(i);
    }

    // Random number generator
    random_device rd;
    mt19937 generator(rd());

    // Shuffle the numbers
    shuffle(data.begin(), data.end(), generator);

    // Write numbers to the file
    for (int i = 0; i < size; i++) {

        file << data[i];

        if (i < size - 1) {
            file << " ";
        }
    }

    file.close();
}


// ============================================================
// LOAD DATASET FROM FILE
//
// Uses ifstream as required by the laboratory:
//
// ifstream file("dataset.txt");
//
// while (file >> number) {
//     data.push_back(number);
// }
// ============================================================

vector<int> loadDataset(const string& filename) {

    vector<int> data;

    ifstream file(filename);

    if (!file) {
        cerr << "Error: Could not open " << filename << "\n";
        return data;
    }

    int number;

    while (file >> number) {
        data.push_back(number);
    }

    file.close();

    return data;
}


// ============================================================
// TEST BUBBLE SORT
// Runs the algorithm 5 times.
// Returns the execution times in seconds.
// ============================================================

vector<double> testBubbleSort(
    const string& filename,
    int numberOfRuns
) {

    vector<double> times;

    for (int run = 1; run <= numberOfRuns; run++) {

        // Load a fresh copy of the original dataset
        vector<int> data = loadDataset(filename);

        if (data.empty()) {
            cerr << "Dataset is empty.\n";
            return times;
        }

        // Start timer ONLY before sorting
        auto start = chrono::high_resolution_clock::now();

        bubbleSort(data);

        // Stop timer immediately after sorting
        auto end = chrono::high_resolution_clock::now();

        // Calculate elapsed time in seconds
        chrono::duration<double> elapsed = end - start;

        times.push_back(elapsed.count());

        // Verify sorting
        if (!isSorted(data)) {
            cerr << "ERROR: Bubble Sort failed!\n";
        }
    }

    return times;
}


// ============================================================
// TEST MERGE SORT
// Runs the algorithm 5 times.
// Returns the execution times in seconds.
// ============================================================

vector<double> testMergeSort(
    const string& filename,
    int numberOfRuns
) {

    vector<double> times;

    for (int run = 1; run <= numberOfRuns; run++) {

        // Load a fresh copy of the original dataset
        vector<int> data = loadDataset(filename);

        if (data.empty()) {
            cerr << "Dataset is empty.\n";
            return times;
        }

        // Start timer ONLY before sorting
        auto start = chrono::high_resolution_clock::now();

        mergeSort(data, 0, data.size() - 1);

        // Stop timer immediately after sorting
        auto end = chrono::high_resolution_clock::now();

        // Calculate elapsed time in seconds
        chrono::duration<double> elapsed = end - start;

        times.push_back(elapsed.count());

        // Verify sorting
        if (!isSorted(data)) {
            cerr << "ERROR: Merge Sort failed!\n";
        }
    }

    return times;
}


// ============================================================
// CALCULATE AVERAGE
// ============================================================

double calculateAverage(const vector<double>& times) {

    if (times.empty()) {
        return 0.0;
    }

    double total = 0.0;

    for (double time : times) {
        total += time;
    }

    return total / times.size();
}


// ============================================================
// PRINT RESULTS
//
// Displays BOTH:
// - Seconds (required by laboratory)
// - Milliseconds (easier to understand for very small times)
// ============================================================

void printResults(
    const string& algorithm,
    const string& dataset,
    int dataSize,
    const vector<double>& times
) {

    double average = calculateAverage(times);

    cout << "\n";
    cout << "-----------------------------------------------\n";
    cout << algorithm << " - " << dataset << "\n";
    cout << "Number of Elements: " << dataSize << "\n";
    cout << "-----------------------------------------------\n";

    for (size_t i = 0; i < times.size(); i++) {

        cout << "Run " << i + 1 << ": "
             << fixed << setprecision(9)
             << times[i] << " seconds\n";
    }

    cout << "Average: "
         << fixed << setprecision(9)
         << average << " seconds\n";
}


// ============================================================
// WRITE CSV HEADER
// ============================================================

void writeCSVHeader(ofstream& file) {

    file << "Dataset,Number of Elements,Algorithm,"
         << "Run 1,Run 2,Run 3,Run 4,Run 5,Average\n";
}


// ============================================================
// WRITE RESULTS TO CSV
//
// CSV values remain in SECONDS because the laboratory
// worksheet specifically asks for seconds.
// ============================================================

void writeCSVRow(
    ofstream& file,
    const string& dataset,
    int dataSize,
    const string& algorithm,
    const vector<double>& times
) {

    file << dataset << ",";
    file << dataSize << ",";
    file << algorithm << ",";

    for (double time : times) {

        file << fixed << setprecision(9)
             << time << ",";
    }

    file << fixed << setprecision(9)
         << calculateAverage(times) << "\n";
}


// ============================================================
// SHOW SMALL DATASET
//
// This lets us visually demonstrate:
//
// BEFORE:
// jumbled numbers
//
// AFTER:
// 1 2 3 4 5 ... 50
//
// We only display the small dataset because displaying
// 100,000 numbers would flood the terminal.
// ============================================================

void showSmallDataset() {

    vector<int> data = loadDataset("small.txt");

    cout << "\n===============================================\n";
    cout << "SMALL DATASET EXAMPLE\n";
    cout << "===============================================\n";

    cout << "\nJumbled input:\n";

    for (int number : data) {
        cout << number << " ";
    }

    cout << "\n\nAfter Bubble Sort / Merge Sort:\n";

    // Make a copy and sort it
    bubbleSort(data);

    for (int number : data) {
        cout << number << " ";
    }

    cout << "\n";
}


// ============================================================
// MAIN PROGRAM
// ============================================================

int main() {

    const int NUMBER_OF_RUNS = 5;

    // Dataset sizes
    const int SMALL_SIZE = 50;
    const int MEDIUM_SIZE = 10000;
    const int LARGE_SIZE = 100000;


    // ========================================================
    // PROGRAM HEADER
    // ========================================================

    cout << "===============================================\n";
    cout << "CSDC103 - LABORATORY EXERCISE #01\n";
    cout << "Bubble Sort vs Merge Sort\n";
    cout << "===============================================\n\n";


    // ========================================================
    // PART 2: GENERATE INPUT DATA
    // ========================================================

    cout << "Creating shuffled sequential datasets...\n\n";

    cout << "Small dataset:\n";
    cout << "Numbers 1 to 50, shuffled\n";

    cout << "Medium dataset:\n";
    cout << "Numbers 1 to 10,000, shuffled\n";

    cout << "Large dataset:\n";
    cout << "Numbers 1 to 100,000, shuffled\n\n";


    createShuffledDataset("small.txt", SMALL_SIZE);
    createShuffledDataset("medium.txt", MEDIUM_SIZE);
    createShuffledDataset("large.txt", LARGE_SIZE);


    cout << "Datasets created successfully.\n\n";

    cout << "small.txt  = " << SMALL_SIZE << " elements\n";
    cout << "medium.txt = " << MEDIUM_SIZE << " elements\n";
    cout << "large.txt  = " << LARGE_SIZE << " elements\n";


    // ========================================================
    // SHOW THE SMALL DATASET
    // ========================================================

    showSmallDataset();


    // ========================================================
    // CREATE CSV FILE
    // ========================================================

    ofstream csvFile("results.csv");

    if (!csvFile) {
        cerr << "Error: Could not create results.csv\n";
        return 1;
    }

    writeCSVHeader(csvFile);


    // ========================================================
    // PART 3A: SMALL DATASET
    // ========================================================

    cout << "\n\n===============================================\n";
    cout << "A. SMALL DATA SET\n";
    cout << "===============================================\n";

    vector<double> smallBubble =
        testBubbleSort("small.txt", NUMBER_OF_RUNS);

    vector<double> smallMerge =
        testMergeSort("small.txt", NUMBER_OF_RUNS);


    printResults(
        "Bubble Sort",
        "small.txt",
        SMALL_SIZE,
        smallBubble
    );

    printResults(
        "Merge Sort",
        "small.txt",
        SMALL_SIZE,
        smallMerge
    );


    writeCSVRow(
        csvFile,
        "Small",
        SMALL_SIZE,
        "Bubble Sort",
        smallBubble
    );

    writeCSVRow(
        csvFile,
        "Small",
        SMALL_SIZE,
        "Merge Sort",
        smallMerge
    );


    // ========================================================
    // PART 3B: MEDIUM DATASET
    // ========================================================

    cout << "\n\n===============================================\n";
    cout << "B. MEDIUM DATA SET\n";
    cout << "===============================================\n";

    vector<double> mediumBubble =
        testBubbleSort("medium.txt", NUMBER_OF_RUNS);

    vector<double> mediumMerge =
        testMergeSort("medium.txt", NUMBER_OF_RUNS);


    printResults(
        "Bubble Sort",
        "medium.txt",
        MEDIUM_SIZE,
        mediumBubble
    );

    printResults(
        "Merge Sort",
        "medium.txt",
        MEDIUM_SIZE,
        mediumMerge
    );


    writeCSVRow(
        csvFile,
        "Medium",
        MEDIUM_SIZE,
        "Bubble Sort",
        mediumBubble
    );

    writeCSVRow(
        csvFile,
        "Medium",
        MEDIUM_SIZE,
        "Merge Sort",
        mediumMerge
    );


    // ========================================================
    // PART 3C: LARGE DATASET
    // ========================================================

    cout << "\n\n===============================================\n";
    cout << "C. LARGE DATA SET\n";
    cout << "===============================================\n";

    cout << "\nWARNING:\n";
    cout << "Bubble Sort on 100,000 elements may take\n";
    cout << "considerably longer than Merge Sort.\n";


    vector<double> largeBubble =
        testBubbleSort("large.txt", NUMBER_OF_RUNS);

    vector<double> largeMerge =
        testMergeSort("large.txt", NUMBER_OF_RUNS);


    printResults(
        "Bubble Sort",
        "large.txt",
        LARGE_SIZE,
        largeBubble
    );

    printResults(
        "Merge Sort",
        "large.txt",
        LARGE_SIZE,
        largeMerge
    );


    writeCSVRow(
        csvFile,
        "Large",
        LARGE_SIZE,
        "Bubble Sort",
        largeBubble
    );

    writeCSVRow(
        csvFile,
        "Large",
        LARGE_SIZE,
        "Merge Sort",
        largeMerge
    );


    // ========================================================
    // FINISH
    // ========================================================

    csvFile.close();


    cout << "\n\n===============================================\n";
    cout << "EXPERIMENT COMPLETE\n";
    cout << "===============================================\n";

    cout << "\nResults have been saved to:\n";
    cout << "results.csv\n";

    cout << "\nDatasets created:\n";
    cout << "small.txt\n";
    cout << "medium.txt\n";
    cout << "large.txt\n";

    cout << "\nCSV times are recorded in SECONDS.\n";
    cout << "Terminal output also shows MILLISECONDS\n";
    cout << "to make very small times easier to understand.\n";

    cout << "\nYou can open results.csv in Excel or Google Sheets\n";
    cout << "to create your Step 8 graph.\n";


    return 0;
}