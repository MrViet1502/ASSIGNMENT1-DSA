/*
 * Author: Võ Tiến
 * Date: 26.02.2023
 * FB: https://www.facebook.com/profile.php?id=100056605580171
 * FB nhóm: https://www.facebook.com/groups/211867931379013
 */

#include "ID_DSA_BTL1.hpp"
#include <vector>

void test_1()
{
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    // ! Thao tác xóa, pushback, print với List<>
    /*
     * label,1x1
     * 0,10
     */
    List<int> *row = dataset.getData()->get(0);
    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(1);
    OUTPUT << "push_back 1 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(2);
    OUTPUT << "push_back 2 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
}

void test_2()
{
    // ! pushfont
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_front(1);
    OUTPUT << "push_front 1 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_front(2);
    OUTPUT << "push_front 2 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
}

void test_3()
{
    // ! pushfont+back
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(1);
    OUTPUT << "push_back 1 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_front(2);
    OUTPUT << "push_front 2 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_front(2);
    OUTPUT << "push_front 2 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(1);
    OUTPUT << "push_back 1 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
}

void test_4()
{
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_front(2);
    OUTPUT << "push_front 2 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(1);
    OUTPUT << "push_back 1 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_front(2);
    OUTPUT << "push_front 2 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(1);
    OUTPUT << "push_back 1 : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
}

void test_5()
{
    // ! insert
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    row->insert(-1, 0);
    row->insert(1, 0);

    row->insert(0, 1);
    OUTPUT << "insert(0, 1) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(2, 0);

    row->insert(0, 2);
    OUTPUT << "insert(0, 2) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(2, 3);
    OUTPUT << "insert(2, 3) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(3, 4);
    OUTPUT << "insert(3, 4) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(1, 5);
    OUTPUT << "insert(1, 5) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(2, 6);
    OUTPUT << "insert(2, 6) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(5, 6);
    OUTPUT << "insert(5, 6) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->insert(10, 0);
}

void test_6()
{
    // ! remove
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(0);

    row->push_back(0);
    OUTPUT << "push_back(0) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(1);
    row->remove(0);
    OUTPUT << "remove(0) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(0);
    row->push_back(1);
    row->push_back(2);
    row->push_back(3);
    OUTPUT << "print : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(1);
    OUTPUT << "remove(1) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(0);
    OUTPUT << "remove(0) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(1);
    OUTPUT << "remove(1) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(0);
    OUTPUT << "remove(0) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(0);
    OUTPUT << "remove(0) : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
}

void test_7()
{
    // ! clear length
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(0);
    row->push_back(1);
    row->push_back(2);
    row->push_back(3);
    OUTPUT << "print : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    OUTPUT << "get(0) : " << row->get(0) << endl;
    OUTPUT << "get(1) : " << row->get(1) << endl;
    OUTPUT << "get(2) : " << row->get(2) << endl;
    OUTPUT << "get(3) : " << row->get(3) << endl;
}

void test_8()
{
    // ! reverse length, 0 1 2 >2 elements
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    row->reverse();

    row->push_back(0);
    row->reverse();
    OUTPUT << "reveser : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(1);
    row->reverse();
    OUTPUT << "reveser : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(2);
    row->reverse();
    OUTPUT << "reveser : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(3);
    row->reverse();
    OUTPUT << "reveser : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->push_back(4);
    row->reverse();
    OUTPUT << "reveser : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
}

void test_9()
{
    // ! subList 0 1 2 >2 >length
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    row->reverse();
    row->push_back(0);
    row->push_back(1);
    row->push_back(2);
    row->push_back(3);
    row->push_back(4);
    OUTPUT << "print : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    List<int> *temp = row->subList(0, 1);
    OUTPUT << "subList(0, 1) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;

    temp = row->subList(0, 2);
    OUTPUT << "subList(0, 2) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;

    temp = row->subList(0, 4);
    OUTPUT << "subList(0, 4) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;

    temp = row->subList(0, 5);
    OUTPUT << "subList(0, 5) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;

    temp = row->subList(2, 3);
    OUTPUT << "subList(2, 3) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;

    temp = row->subList(2, 2);
    OUTPUT << "subList(2, 2) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;

    temp = row->subList(5, 6);
    OUTPUT << "subList(5, 6) : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;
}

void test_10()
{
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    List<int> *row = dataset.getData()->get(0);

    row->clear();
    OUTPUT << "clear";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    row->reverse();

    row->push_back(0);
    row->push_back(1);
    row->push_back(2);
    row->push_back(3);
    row->push_back(4);
    OUTPUT << "print : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    row->remove(2);
    row->remove(3);
    row->remove(0);
    row->insert(0, 1);
    row->reverse();
    OUTPUT << "print : ";
    row->print();
    OUTPUT << "\nlenght " << row->length() << endl;

    List<int> *temp = row->subList(0, 6);
    temp->reverse();
    OUTPUT << "print temp : ";
    temp->print();
    OUTPUT << "\nlenght " << row->length() << endl;
    delete temp;
}

void test_11()
{
    // ! printHead start <0, end >length, getShape
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");

    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;

    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "printHead(1, 1)\n";
    dataset.printHead(1, 1);
    OUTPUT << endl;
    OUTPUT << "printHead(2, 2)\n";
    dataset.printHead(2, 2);
    OUTPUT << endl;
    OUTPUT << "printHead(2, 4)\n";
    dataset.printHead(2, 4);
    OUTPUT << endl;
    OUTPUT << "printHead(20, -1)\n";
    dataset.printHead(20, -1);
    OUTPUT << endl;
    OUTPUT << "printHead(-2, 10)\n";
    dataset.printHead(-2, 10);
    OUTPUT << endl;
    OUTPUT << "printHead(15, 15)\n";
    dataset.printHead(15, 15);
    OUTPUT << endl;
}

void test_12()
{
    // ! printTail
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");

    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;

    OUTPUT << "printTail(10, 10)\n";
    dataset.printTail(10, 10);
    OUTPUT << endl;
    OUTPUT << "printTail(1, 1)\n";
    dataset.printTail(1, 1);
    OUTPUT << endl;
    OUTPUT << "printTail(2, 2)\n";
    dataset.printTail(2, 2);
    OUTPUT << endl;
    OUTPUT << "printTail(2, 4)\n";
    dataset.printTail(2, 4);
    OUTPUT << endl;
    OUTPUT << "printTail(20, -1)\n";
    dataset.printTail(20, -1);
    OUTPUT << endl;
    OUTPUT << "printTail(-2, 10)\n";
    dataset.printTail(-2, 10);
    OUTPUT << endl;
    OUTPUT << "printTail(15, 15)\n";
    dataset.printTail(15, 15);
    OUTPUT << endl;
}

void test_13()
{
    // ! operator=, copy constructor, column, print
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    {
        Dataset temp1 = dataset;
        OUTPUT << "Dataset temp1 = dataset;\n";
        temp1.printHead(10, 10);
        OUTPUT << endl;
        OUTPUT << "columns: ";
        temp1.columns();
        OUTPUT << endl;

        Dataset temp2(dataset);
        OUTPUT << "Dataset temp2(dataset);\n";
        temp2.printHead(10, 10);
        OUTPUT << endl;
        OUTPUT << "columns: ";
        temp2.columns();
        OUTPUT << endl;

        temp1 = dataset;
        OUTPUT << "temp1 = dataset; \n";
        temp1.printHead(10, 10);
        OUTPUT << endl;
        OUTPUT << "columns: ";
        temp1.columns();
        OUTPUT << endl;
    }
}

void test_14()
{
    // ! drop row
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "dataset.drop(-1)\n";
    if (dataset.drop(-1))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,-1)\n";
    if (dataset.drop(0, -1))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,10)\n";
    if (dataset.drop(0, 10))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,10)\n";
    if (dataset.drop(0, 9))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,2)\n";
    if (dataset.drop(0, 2))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,2)\n";
    if (dataset.drop(0, 2))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,3)\n";
    if (dataset.drop(0, 3))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,1)\n";
    if (dataset.drop(0, 1))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";
}

void test_15()
{
    // ! drop column
    // ! print empty dataset
    // ! getShape after full dropping
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "dataset.drop(1,0,a)\n";
    if (dataset.drop(1, 0, "a"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(1,0,label)\n";
    if (dataset.drop(1, 0, "label"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(1,-2,1x2)\n";
    if (dataset.drop(1, -2, "1x2"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(1,-1,1x3)\n";
    if (dataset.drop(1, -1, "1x3"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(1,0,1x3)\n";
    if (dataset.drop(1, 0, "1x3"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(1,0,1x1)\n";
    if (dataset.drop(1, 0, "1x1"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    OUTPUT << "dataset.drop(1,0)\n";
    if (dataset.drop(1, 0))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
}

void test_16()
{
    // ! extract row
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    Dataset temp = dataset.extract();
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract() shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, 0);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,0) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, 1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(3, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(3,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(1, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(1,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(2, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(2,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(9, 9);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(9,9) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(1, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(1,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(4, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(4,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;
}

void test_17()
{
    // ! extract column
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    Dataset temp = dataset.extract();
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract() shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 0, 0);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,0,0) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 0, 1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,0,1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 3, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,3,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 1, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,1,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 2, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,1,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 2, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,2,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(0, -1, 1, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(0,-1,1,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;
}

void test_18()
{
    // ! extract
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    Dataset temp = dataset.extract();
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract() shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(1, 1, 0, 0);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(1,1,0,0) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(2, 3, 2, 3);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(2,3,2,3) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(2, -1, 2, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(2,-1,2,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(9, -1, 3, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(9,-1,3,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;

    temp = dataset.extract(7, -1, 3, -1);
    temp.getShape(nRows, nCols);
    OUTPUT << "temp dataset.extract(7,-1,2,-1) shape: " << nRows << "x" << nCols << endl;
    temp.printHead(10, 10);
    OUTPUT << endl;
}

void test_19()
{
    // ! split khốn nạn feature length >< label
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, 8, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    X_train.getShape(nRows, nCols);
    OUTPUT << "X_train shape: " << nRows << "x" << nCols << endl;
    X_train.printHead(10, 10);
    OUTPUT << endl;
    X_test.getShape(nRows, nCols);
    OUTPUT << "X_test shape: " << nRows << "x" << nCols << endl;
    X_test.printHead(10, 10);
    OUTPUT << endl;
    y_train.getShape(nRows, nCols);
    OUTPUT << "y_train shape: " << nRows << "x" << nCols << endl;
    y_train.printHead(10, 10);
    OUTPUT << endl;
    y_test.getShape(nRows, nCols);
    OUTPUT << "y_test shape: " << nRows << "x" << nCols << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;
}

void test_20()
{
    // ! split khốn nạn 2
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "dataset Shape: " << nRows << "x" << nCols << endl;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, 2, 1, -1);
    Dataset label = dataset.extract(0, 5, 0, 0);

    train_test_split(feature, label, 0.5, X_train, X_test, y_train, y_test);
    X_train.getShape(nRows, nCols);
    OUTPUT << "X_train shape: " << nRows << "x" << nCols << endl;
    X_test.getShape(nRows, nCols);
    OUTPUT << "X_test shape: " << nRows << "x" << nCols << endl;
    y_train.getShape(nRows, nCols);
    OUTPUT << "y_train shape: " << nRows << "x" << nCols << endl;
    y_test.getShape(nRows, nCols);
    OUTPUT << "y_test shape: " << nRows << "x" << nCols << endl;
}

void test_21()
{
    // ! testsize = 0
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "dataset Shape: " << nRows << "x" << nCols << endl;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, 2, 1, -1);
    Dataset label = dataset.extract(0, 5, 0, 0);

    train_test_split(feature, label, 0, X_train, X_test, y_train, y_test);
    X_train.getShape(nRows, nCols);
    OUTPUT << "X_train shape: " << nRows << "x" << nCols << endl;
    X_test.getShape(nRows, nCols);
    OUTPUT << "X_test shape: " << nRows << "x" << nCols << endl;
    y_train.getShape(nRows, nCols);
    OUTPUT << "y_train shape: " << nRows << "x" << nCols << endl;
    y_test.getShape(nRows, nCols);
    OUTPUT << "y_test shape: " << nRows << "x" << nCols << endl;
}

void test_22()
{
    // ! testsize = 1
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "dataset Shape: " << nRows << "x" << nCols << endl;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, 2, 1, -1);
    Dataset label = dataset.extract(0, 5, 0, 0);

    train_test_split(feature, label, 1, X_train, X_test, y_train, y_test);
    X_train.getShape(nRows, nCols);
    OUTPUT << "X_train shape: " << nRows << "x" << nCols << endl;
    X_test.getShape(nRows, nCols);
    OUTPUT << "X_test shape: " << nRows << "x" << nCols << endl;
    y_train.getShape(nRows, nCols);
    OUTPUT << "y_train shape: " << nRows << "x" << nCols << endl;
    y_test.getShape(nRows, nCols);
    OUTPUT << "y_test shape: " << nRows << "x" << nCols << endl;
}

void test_23()
{
    // ! testsize >1
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist2.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "dataset Shape: " << nRows << "x" << nCols << endl;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, 2, 1, -1);
    Dataset label = dataset.extract(0, 5, 0, 0);

    train_test_split(feature, label, 1.1, X_train, X_test, y_train, y_test);
    X_train.getShape(nRows, nCols);
    OUTPUT << "X_train shape: " << nRows << "x" << nCols << endl;
    X_test.getShape(nRows, nCols);
    OUTPUT << "X_test shape: " << nRows << "x" << nCols << endl;
    y_train.getShape(nRows, nCols);
    OUTPUT << "y_train shape: " << nRows << "x" << nCols << endl;
    y_test.getShape(nRows, nCols);
    OUTPUT << "y_test shape: " << nRows << "x" << nCols << endl;
}

void test_24()
{
    // ! predict k=1
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_25()
{
    // ! predict k>=2
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 2;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.4, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_26()
{
    // ! predict k > test length
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 8;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.5, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_27()
{
    // ! printTail nameCol > datalength
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist4.csv");

    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;

    OUTPUT << "printTail(10, 10)\n";
    dataset.printTail(10, 10);
    OUTPUT << endl;
    OUTPUT << "printTail(1, 1)\n";
    dataset.printTail(1, 1);
    OUTPUT << endl;
    OUTPUT << "printTail(2, 2)\n";
    dataset.printTail(2, 2);
    OUTPUT << endl;
    OUTPUT << "printTail(2, 4)\n";
    dataset.printTail(2, 4);
    OUTPUT << endl;
    OUTPUT << "printTail(20, -1)\n";
    dataset.printTail(20, -1);
    OUTPUT << endl;
    OUTPUT << "printTail(-2, 10)\n";
    dataset.printTail(-2, 10);
    OUTPUT << endl;
    OUTPUT << "printTail(15, 15)\n";
    dataset.printTail(15, 15);
    OUTPUT << endl;
}

void test_28()
{
    // ! printColumn sau khi copy empty dataset
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist1.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "dataset.drop(0,0)\n";
    if (dataset.drop(0, 0, "voTien"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";

    {
        Dataset temp1 = dataset;
        OUTPUT << "Dataset temp1 = dataset;\n";
        temp1.printHead(10, 10);
        OUTPUT << endl;
        OUTPUT << "columns: ";
        temp1.columns();
        OUTPUT << endl;
    }
}

void test_29()
{
    // ! drop column nameCol < data length
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist5.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "dataset.drop(1,0,'voTien')\n";
    if (dataset.drop(1, 0, "voTien"))
    {
        dataset.printHead(10, 10);
        OUTPUT << endl;
    }
    else
        OUTPUT << "FALSE\n";
}

void test_30()
{
    // ! self operator=
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist5.csv");
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "Self opeatore=" << endl;
    dataset = dataset;
    dataset.getShape(nRows, nCols);
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;
}

void test_31()
{
    // ! y_train < x_train
    // ! predict error
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, 8, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_32()
{
    // ! y_test < x_test
    // ! score error
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, 8, 0, 0);

    train_test_split(feature, label, 0.33, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_33()
{
    // ! y_train > x_train
    // ! predict error
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, 8, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_34()
{
    // ! y_test > x_test
    // ! score error
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, 8, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.33, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_35()
{
    // ! empty label
    // ! extract start < 0
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;

    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;

    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(-1, -1, -1, 0);

    train_test_split(feature, label, 0.33, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void test_36()
{
    // ! empty feature
    Dataset dataset;
    dataset.loadFromCSV("TestCase_1/input/mnist3.csv");
    int k = 1;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    OUTPUT << "K = " << k << endl;
    OUTPUT << "Shape: " << nRows << "x" << nCols << endl;
    OUTPUT << "columns: ";
    dataset.columns();
    OUTPUT << endl;
    OUTPUT << "printHead(10, 10)\n";
    dataset.printHead(10, 10);
    OUTPUT << endl;

    kNN knn(k);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(-1, -1, -1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.33, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    OUTPUT << "y_pred" << endl;
    y_pred.printHead(10, 10);
    OUTPUT << endl;
    OUTPUT << "y_test" << endl;
    y_test.printHead(10, 10);
    OUTPUT << endl;

    OUTPUT << "score = " << knn.score(y_test, y_pred) << endl;
}

void comparefile(int start, int end);
//* ./main task1; ./main task2; ./main task3;
//* ./main i j (với i với j là số từ test i -> j)
//* ./main i (i là test cần test)
int main(int argc, char *argv[])
{
    OUTPUT << "Start program assignments 1 DSA" << endl;

    string folder_expect = "TestCase_1/output/output";
    // string folder_expect = "TestCase_1/expect/expect";
    OUTPUT.open(folder_expect + "1.txt");
    test_1();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "2.txt");
    test_2();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "3.txt");
    test_3();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "4.txt");
    test_4();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "5.txt");
    test_5();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "6.txt");
    test_6();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "7.txt");
    test_7();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "8.txt");
    test_8();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "9.txt");
    test_9();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "10.txt");
    test_10();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "11.txt");
    test_11();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "12.txt");
    test_12();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "13.txt");
    test_13();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "14.txt");
    test_14();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "15.txt");
    test_15();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "16.txt");
    test_16();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "17.txt");
    test_17();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "18.txt");
    test_18();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "19.txt");
    test_19();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "20.txt");
    test_20();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "21.txt");
    test_21();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "22.txt");
    test_22();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "23.txt");
    test_23();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "24.txt");
    test_24();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "25.txt");
    test_25();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "26.txt");
    test_26();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "27.txt");
    test_27();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "28.txt");
    test_28();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "29.txt");
    test_29();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "30.txt");
    test_30();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "31.txt");
    test_31();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "32.txt");
    test_32();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "33.txt");
    test_33();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "34.txt");
    test_34();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "35.txt");
    test_35();
    OUTPUT.close();

    OUTPUT.open(folder_expect + "36.txt");
    test_36();
    OUTPUT.close();

    comparefile(1, 36);
}

void comparefile(int start, int end)
{
    vector<int> result;
    for (int i = start; i <= end; i++)
    {
        ifstream read_output("TestCase_1/output/output" + to_string(i) + ".txt");
        ifstream read_expect("TestCase_1/expect/expect" + to_string(i) + ".txt");
        if (read_output.fail() || read_expect.fail())
        {
            cout << "Error reading file" << end;
            return;
        }
        string s1, s2;
        while (read_output >> s1 && read_expect >> s2)
        {
            if (s1 != s2)
            {
                result.push_back(i);
                break;
            }
        }
        if (read_output >> s1 || read_expect >> s2)
        {
            if (result.size() == 0 || result.size() > 0 && result[result.size() - 1] != i)
                result.push_back(i);
        }
    }

    if (result.size() == 0)
    {
        cout << "Success: test " << start << " to " << end << endl;
    }
    else
    {
        cout << "percent success : " << (1 - result.size() * 1.0 / (end - start + 1)) * 100 << "%" << endl;
        cout << "Fail : test [";
        for (int i = 0; i < result.size() - 1; i++)
        {
            cout << result[i] << ", ";
        }
        cout << result[result.size() - 1] << "]\n";
        cout << "link check comparefile: https://www.diffchecker.com/text-compare/" << endl;
    }
}