// #include "kNN.hpp"

// void tc1(){
//     Dataset dataset;
//     dataset.loadFromCSV("mnist.csv");
//     dataset.printHead();
//     dataset.printTail();
//     int nRows, nCols;
//     dataset.getShape(nRows, nCols);
//     cout << "Shape: " << nRows << "x" << nCols << endl;

//     kNN knn;
//     Dataset X_train, X_test, y_train, y_test;
//     Dataset feature = dataset.extract(0, -1, 1, -1);
//     Dataset label = dataset.extract(0, -1, 0, 0);
//     train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);

//     knn.fit(X_train, y_train);
//     Dataset y_pred = knn.predict(X_test);
//     double accuracy = knn.score(y_test, y_pred);
//     cout << "Accuracy: " << accuracy << endl;
// }

// void tc2(){
//     Dataset dataset;
//     dataset.loadFromCSV("mnist.csv");
//     dataset.printHead(10, 10);
//     cout << endl;
//     dataset.printTail(10, 10);
//     cout << endl;
//     int nRows, nCols;
//     dataset.getShape(nRows, nCols);
//     cout << "Shape: " << nRows << "x" << nCols << endl;
// }

// int main() {
//     //tc1();
//     tc2();
//     return 0;
// }


#include "kNN.hpp"

void tc1()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    dataset.printHead();
    dataset.printTail();
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    cout << "Shape: " << nRows << "x" << nCols << endl;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);
    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);

    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);
    double accuracy = knn.score(y_test, y_pred);
    cout << "Accuracy: " << accuracy << endl;
}

void tc1002()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    List<int> *row = dataset.getData()->get(0);

    row->push_back(2);

    cout << row->length() << endl;
    row->print();
}

void tc1004()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    List<int> *row = dataset.getData()->get(0);

    row->push_back(0);
    row->push_back(2);

    cout << row->length() << endl;
    row->print();
}

void tc1005()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    List<int> *row = dataset.getData()->get(0);

    row->push_back(1);
    row->push_back(2);
    row->push_back(1);

    cout << row->length() << endl;
    row->print();
}

void tc1160()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    Dataset dataset_extract = dataset.extract(30, 20, 0, -1);
    Dataset dataset_extract2 = dataset_extract;
    dataset_extract2.getShape(nRows, nCols);
    cout << "Dataset extract shape: " << nRows << "x" << nCols << endl;
}
void tc1148()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    bool result = dataset.drop(1, 0, "labels");
    cout << "Drop(1, \"labels\") result: " << result << endl;
}

void tc1158()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    Dataset dataset_extract = dataset.extract(0, -2, 0, -1);
    Dataset dataset_extract2 = Dataset(dataset_extract);
    dataset_extract2.getShape(nRows, nCols);
    cout << "Dataset extract shape: " << nRows << "x" << nCols << endl;
}

void tc1114()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    dataset.printHead();
    dataset.printHead();
}

void tc1156()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    Dataset dataset_extract = dataset.extract(0, -1, 0, -1);
    dataset_extract.getShape(nRows, nCols);
    cout << "Dataset extract shape: " << nRows << "x" << nCols << endl;
}
void tc1157()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    Dataset dataset_extract = dataset.extract(0, 0, 0, -1);
    dataset_extract.getShape(nRows, nCols);
    cout << "Dataset extract shape: " << nRows << "x" << nCols << endl;
}

void tc1155()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    Dataset dataset_extract = dataset.extract();
    dataset_extract.getShape(nRows, nCols);
    cout << "Dataset extract shape: " << nRows << "x" << nCols << endl;
}

void tc1173()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");

    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.3, X_train, X_test, y_train, y_test);

    X_train.getShape(nRows, nCols);
    cout << "X_train shape: " << nRows << "x" << nCols << endl;
    X_test.getShape(nRows, nCols);
    cout << "X_test shape: " << nRows << "x" << nCols << endl;
    y_train.getShape(nRows, nCols);
    cout << "y_train shape: " << nRows << "x" << nCols << endl;
    y_test.getShape(nRows, nCols);
    cout << "y_test shape: " << nRows << "x" << nCols << endl;
}

void tc1144()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    dataset.getShape(nRows, nCols);
    // cout << nRows << ' ' << nCols << endl;
    bool result = dataset.drop(0, nRows);
    cout << "Drop(0, nRows) result: " << result << endl;
}
void tc1001()
{
Dataset dataset;
dataset.loadFromCSV("mnist.csv");
List<int> *row = dataset.getData()->get(0);

row->push_back(1);
cout << row->length();
}
void tc1003()
{
Dataset dataset;
dataset.loadFromCSV("mnist.csv");
List<int> *row = dataset.getData()->get(0);

row->push_back(1);
row->push_back(0);

cout << row->length();
}

void tc1145()
{
    int nRows, nCols;
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    Dataset dataset2 = Dataset(dataset);
    bool result = dataset2.drop(0, 4);
    cout << "Drop(0, 4) result: " << result << endl;
}
int main()
{
    //  tc1();
    // tc1004();
    // tc1005();
    // // tc1160();
    // tc1148();
    //  tc1114();
    // tc1155();
    // tc1156();
    // tc1157();
    // tc1144();
    
     //tc1173();
    // tc1160();
    // tc1158();
    tc1145();
    return 0;
}