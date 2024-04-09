/*
 * Author: Võ Tiến
 * Date: 26.02.2023
 * FB: https://www.facebook.com/profile.php?id=100056605580171
 * FB nhóm: https://www.facebook.com/groups/211867931379013
 */
/*
* cách dùng hàm main.cpp
* b1: mở folder BTL1 lên vscode
* b2: mở Terminal trên thanh công cụ mở new Terminal
* b3: chạy lệnh g++ -o main main_task3.cpp kNN.cpp nếu không gì hiện ra thì không bị lỗi code
* b4: chạy ./main KEYWORDS (./main task1, ./main task2)
* b5: nếu hiện Success: test 1 to 200 thì đã đúng hết

! KEYWORDS có thể là
* ./main task1 này chạy phần task1
* ./main 2 này chạy phần input2
* ./main 1 5 này sẽ chạy phần input1 -> input5
* ./main hiện tại cũng chạy hết task 1
* output là file của bạn, expect là đáp án
*/

#include "ID_DSA_BTL1.hpp"
#include <vector>
#define folder_input "TestCase_2/input/input"
#define folder_output "TestCase_2/output/output"
#define folder_expect "TestCase_2/expect/expect"

bool isNumber(string str);
void comparefile(int start, int end);

void run_task_3(string fileName)
{
    Dataset dataset;
    string csvFile;

    if (stoi(fileName) <= 800)
    {
        csvFile = folder_input + fileName + ".csv";
    }
    else
    {
        csvFile = "TestCase_2/input/input801-1000.csv";
    }
    if (!dataset.loadFromCSV(csvFile.c_str()))
    {
        OUTPUT << "fail File";
        return;
    }

    ifstream file(folder_input + fileName + ".txt");
    if (!file.is_open())
    {
        cout << "Error: " << folder_input + fileName + ".txt" << endl;
        return;
    }

    string s;
    int value, index, i = 1, number;
    int k = 5;
    double test_size = 0.0;
    while (file >> s)
    {
        if (s == "Dataset")
        {

            OUTPUT << "Line " << i << " "
                   << "Dataset " << endl;
            Dataset d(dataset);
            d.printHead(100, 100);
        }
        else if (s == "k")
        {
            string temp;
            file >> temp;
            file >> k;
        }
        else if (s == "test_size")
        {
            string temp;
            file >> temp;
            file >> test_size;
        }
        else if (s == "operator=")
        {

            OUTPUT << "Line " << i << " "
                   << "operator= " << endl;
            Dataset d = dataset;
            d.printHead(100, 100);
        }
        else if (s == "getShape")
        {
            int nRows = 0, nCols = 0;
            dataset.getShape(nRows, nCols);
            OUTPUT << "Line " << i << " "
                   << "getShape : " << nRows << " " << nCols << endl;
        }
        else if (s == "columns")
        {
            OUTPUT << "Line " << i << " "
                   << "columns : ";
            dataset.columns();
        }
        else if (s == "printHead")
        {
            int nRows = 0, nCols = 0;
            file >> nRows >> nCols;
            OUTPUT << "Line " << i << " "
                   << "printHead " << nRows << " " << nCols << endl;
            dataset.printHead(nRows, nCols);
        }
        else if (s == "printTail")
        {
            int nRows = 0, nCols = 0;
            file >> nRows >> nCols;
            OUTPUT << "Line " << i << " "
                   << "printTail " << nRows << " " << nCols << endl;
            dataset.printTail(nRows, nCols);
        }
        else if (s == "drop")
        {
            int axis = 0, index = 0;
            string columns = "";
            file >> axis >> index >> columns;
            OUTPUT << "Line " << i << " "
                   << "drop " << axis << " " << index << " " << columns << " : "
                   << (dataset.drop(axis, index, columns) ? "true" : "false") << endl;
        }
        else if (s == "extract")
        {
            int startRow, endRow, startCol, endCol;
            file >> startRow >> endRow >> startCol >> endCol;

            OUTPUT << "Line " << i << " "
                   << "extract " << startRow << " " << endRow << " " << startCol << " " << endCol << endl;
            Dataset d = dataset.extract(startRow, endRow, startCol, endCol);
            d.printHead(100, 100);
        }
        i++;
    }

    kNN knn(k);

    Dataset X_train, X_test, y_train, y_test;
    int nCol = 0;
    int nRow = 0;

    dataset.getShape(nRow, nCol);

    Dataset feature = dataset.extract(0, -1, 1, nCol);

    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, test_size, X_train, X_test, y_train, y_test);

    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);
    OUTPUT << "Line X_train : " << endl;
    X_train.printHead(100, 100);
    OUTPUT << "Line X_test : " << endl;
    X_test.printHead(100, 100);
    OUTPUT << "Line y_train : " << endl;
    y_train.printHead(100, 100);
    OUTPUT << "Line y_test : " << endl;
    y_test.printHead(100, 100);
    OUTPUT << "Line y_predict : " << endl;
    y_pred.printHead(100, 100);

    double accuracy = knn.score(y_test, y_pred);
    OUTPUT << "Accuracy: " << accuracy << endl;
}
void run_task_1(string fileName)
{
    ifstream file(folder_input + fileName + ".txt");
    if (!file.is_open())
    {
        cout << "Error: " << fileName << endl;
    }

    List<int> *list = new Image<int>();
    string s;
    int value, index, i = 1, number;
    while (file >> s)
    {
        if (s == "push_back")
        {
            file >> value;
            list->push_back(value);
            OUTPUT << "push_back " << value << endl;
        }
        else if (s == "push_front")
        {
            file >> value;
            list->push_front(value);
            OUTPUT << "push_front " << value << endl;
        }
        else if (s == "insert")
        {
            file >> index >> value;
            list->insert(index, value);
            OUTPUT << "insert " << index << " " << value << endl;
        }
        else if (s == "remove")
        {
            file >> index;
            list->remove(index);
            OUTPUT << "remove " << index << endl;
        }
        else if (s == "get")
        {
            file >> index;
            try
            {
                int temp = list->get(index);
                OUTPUT << "get " << index << " : " << temp << endl;
            }
            catch (const std::out_of_range &e)
            {
                OUTPUT << "get " << index << " : " << e.what() << endl;
            }
        }
        else if (s == "length")
        {
            OUTPUT << "length : " << list->length() << endl;
        }
        else if (s == "reverse")
        {
            list->reverse();
            OUTPUT << "reverse : ";
            list->print();
        }
        else if (s == "distanceEuclidean")
        {
            // List<int>* other = new Image<int>();
            // file >> number;
            // OUTPUT << "distanceEuclidean " << number << " ";
            // for(int j = 0; j < number; j++)
            // {
            //     file >> value;
            //     OUTPUT << value << " ";
            //     other->push_back(value);
            // }
            // // OUTPUT << ": " << list->distanceEuclidean(other) << endl;
            // delete other;
        }
        else if (s == "subList")
        {
            int start, end;
            file >> start >> end;
            List<int> *other = list->subList(start, end);
            if (other == NULL)
                OUTPUT << "subList " << start << " " << end << " : "
                       << "nullptr" << endl;
            else
            {
                OUTPUT << "subList " << start << " " << end << " : ";
                other->print();
                delete other;
            }
        }
        else if (s == "print")
        {
            OUTPUT << "print : ";
            list->print();
        }
        else if (s == "clear")
        {
            list->clear();
            OUTPUT << "clear" << endl;
        }
        i++;
    }
}
void run_task_2(string fileName)
{
    ifstream file(folder_input + fileName + ".txt");
    if (!file.is_open())
    {
        cout << "Error: " << folder_input + fileName + ".txt" << endl;
        return;
    }

    Dataset dataset;
    fileName = folder_input + fileName + ".csv";
    if (!dataset.loadFromCSV(fileName.c_str()))
    {
        OUTPUT << "fail File";
        return;
    }

    string s;
    int value, index, i = 1, number;
    while (file >> s)
    {
        if (s == "Dataset")
        {

            OUTPUT << "Line " << i << " "
                   << "Dataset " << endl;
            Dataset d(dataset);
            d.printHead(100, 100);
        }
        else if (s == "operator=")
        {

            OUTPUT << "Line " << i << " "
                   << "operator= " << endl;
            Dataset d = dataset;
            d.printHead(100, 100);
        }
        else if (s == "getShape")
        {
            int nRows = 0, nCols = 0;
            dataset.getShape(nRows, nCols);
            OUTPUT << "Line " << i << " "
                   << "getShape : " << nRows << " " << nCols << endl;
        }
        else if (s == "columns")
        {
            OUTPUT << "Line " << i << " "
                   << "columns : ";
            dataset.columns();
        }
        else if (s == "printHead")
        {
            int nRows = 0, nCols = 0;
            file >> nRows >> nCols;
            OUTPUT << "Line " << i << " "
                   << "printHead " << nRows << " " << nCols << endl;
            dataset.printHead(nRows, nCols);
        }
        else if (s == "printTail")
        {
            int nRows = 0, nCols = 0;
            file >> nRows >> nCols;
            OUTPUT << "Line " << i << " "
                   << "printTail " << nRows << " " << nCols << endl;
            dataset.printTail(nRows, nCols);
        }
        else if (s == "drop")
        {
            int axis = 0, index = 0;
            string columns = "";
            file >> axis >> index >> columns;
            OUTPUT << "Line " << i << " "
                   << "drop " << axis << " " << index << " " << columns << " : "
                   << (dataset.drop(axis, index, columns) ? "true" : "false") << endl;
        }
        else if (s == "extract")
        {
            int startRow, endRow, startCol, endCol;
            file >> startRow >> endRow >> startCol >> endCol;

            OUTPUT << "Line " << i << " "
                   << "extract " << startRow << " " << endRow << " " << startCol << " " << endCol << endl;
            Dataset d = dataset.extract(startRow, endRow, startCol, endCol);
            d.printHead(100, 100);
        }
        i++;
    }
}

//* ./main task1; ./main task2; ./main task3;
//* ./main i j (với i với j là số từ test i -> j)
//* ./main i (i là test cần test)
int main(int argc, char *argv[])
{
    cout << "Start program assignments 1 DSA" << endl;

    int START = 0, END = 0;
    int fullTask = 200;
    //* check all test cases

    if (argc == 1)
    {
        cout << "checking test : ";
        START = 1;
        END = 1000;
        for (int i = START; i <= END; i++)
        {
            cout << i << " ";
            OUTPUT.open(folder_output + to_string(i) + ".txt");
            if (i <= 200)
                run_task_1(to_string(i));
            else if (i <= 400)
                run_task_2(to_string(i));
            else
                run_task_3(to_string(i));

            OUTPUT.close();
        }
    }

    else if (argc == 2)
    {

        string stringTask = argv[1];
        if (isNumber(stringTask))
        {
            cout << "checking test : " << argv[1];
            START = stoi(stringTask);
            END = stoi(stringTask);
            OUTPUT.open(folder_output + stringTask + ".txt");

            if (stoi(stringTask) <= 200)
                run_task_1(stringTask);
            else if (stoi(stringTask) <= 400)
                run_task_2(stringTask);
            else
                run_task_3(stringTask);
            OUTPUT.close();
        }
        else if (stringTask == "me")
        {
            cout << "checking test : ";
            for (int i = 1; i <= 1000; i++)
            {
                cout << i << " ";
                OUTPUT.open(folder_expect + to_string(i) + ".txt");
                if (i <= 200)
                    run_task_1(to_string(i));
                else if (i <= 400)
                    run_task_2(to_string(i));
                else
                    run_task_3(to_string(i));
                OUTPUT.close();
            }
        }
        else if (stringTask.substr(0, 4) != "task" || stringTask[4] <= '0' || stringTask[4] > '3')
        {
            cout << "Please re-enter the correct command" << endl;
            cout << "./main task1\n./main task2\n./main task3OUTPUT\n./main number" << endl;
            return 0;
        }
        else
        {
            cout << "checking test : ";

            START = 1;
            END = 1000;
            for (int i = 1; i <= 1000; i++)
            {
                cout << i << " ";
                OUTPUT.open(folder_output + to_string(i) + ".txt");
                if (i <= 200)
                    run_task_1(to_string(i));
                else if (i <= 400)
                    run_task_2(to_string(i));
                else
                    run_task_3(to_string(i));
                OUTPUT.close();
            }
        }
    }
    else if (argc == 3 && isNumber(argv[1]) && isNumber(argv[2]))
    {
        cout << "checking test : ";
        START = stoi(argv[1]);
        END = stoi(argv[2]);
        for (int i = stoi(argv[1]); i <= stoi(argv[2]); i++)
        {
            cout << i << " ";
            OUTPUT.open(folder_output + to_string(i) + ".txt");
            if (i <= 200)
                run_task_1(to_string(i));
            else if (i <= 400)
                run_task_2(to_string(i));
            else
                run_task_3(to_string(i));
            OUTPUT.close();
        }
    }
    else
    {
        cout << "Please re-enter the correct command" << endl;
        cout << "./main task1\n./main task2\n./main task3OUTPUT\n./main number" << endl;
        return 0;
    }

    cout << "\nOK: run_task_3s without errors\n"
         << endl;
    comparefile(START, END);
    return 1;
}

bool isNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void comparefile(int start, int end)
{
    vector<int> result;
    for (int i = start; i <= end; i++)
    {
        ifstream read_output(folder_output + to_string(i) + ".txt");
        ifstream read_expect(folder_expect + to_string(i) + ".txt");
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