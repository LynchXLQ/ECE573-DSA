#include <random>
#include "sortingAlgorithm.h"
#include "timer.h"

using namespace std;

vector<int> generateRandom(const int num, const int start, const int end){
    random_device randomDevice;
    mt19937_64 r_eng(randomDevice());
    uniform_int_distribution<> distribution(start, end);  // Generate random numbers between 0 and 10000

    vector<int> randomNumber;
    randomNumber.reserve(num);
    for (int i = 0; i < num; i++) {
        randomNumber.push_back(distribution(r_eng));
    }
    return randomNumber;
}

void printVector(const vector<int> &vector){
    for (auto num: vector) {
        cout << num << " ";
    }
    cout << endl;
}



int main() {
    vector<int> testVec;
    vector<int> resVec;
    int num = 100000;
    testVec = generateRandom(num, 0, num);
    cout << "The test vector contain " << num << " elements." << endl;

//    printVector(testVec);

    Timer timer;
    SortingAlgorithm sa;

    cout << "\nBubble Sort" << endl;
//    printVector(testVec);
    timer.start();
    resVec = sa.bubbleSort(testVec);
    timer.stop();
//    printVector(resVec);
    cout << "Total time: " << timer.total() << " ms" << endl;

    cout << "Insertion Sort" << endl;
//    printVector(testVec);
    timer.start();
    resVec = sa.insertionSort(testVec);
    timer.stop();
//    printVector(resVec);
    cout << "Total time: " << timer.total() << " ms" << endl;

    cout << "Selection Sort" << endl;
//    printVector(testVec);
    timer.start();
    resVec = sa.selectionSort(testVec);
    timer.stop();
//    printVector(resVec);
    cout << "Total time: " << timer.total() << " ms" << endl;

    cout << "Merge Sort" << endl;
//    printVector(testVec);
    timer.start();
    resVec = sa.mergeSort(testVec);
    timer.stop();
//    printVector(resVec);
    cout << "Total time: " << timer.total() << " ms" << endl;

    cout << "Counting Sort" << endl;
//    printVector(testVec);
    timer.start();
    resVec = sa.countingSort(testVec);
    timer.stop();
//    printVector(resVec);
    cout << "Total time: " << timer.total() << " ms" << endl;

    return 0;
}
