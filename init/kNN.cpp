#include "kNN.hpp"


void train_test_split(Dataset &X, Dataset &Y, double test_size,
                      Dataset &X_train, Dataset &X_test, Dataset &Y_train, Dataset &Y_test)
{
    if (X.getData()->length() != Y.getData()->length() || test_size >= 1 || test_size <= 0)
        return;

    double minDouble = 1.0e-15;
    int nRow = X.getData()->length();
    double rowS = nRow * (1 - test_size);

    if (abs(round(rowS) - rowS) < minDouble * nRow)
        rowS = round(rowS);

    X_train = X.extract(0, rowS - 1, 0, -1);
    Y_train = Y.extract(0, rowS - 1, 0, -1);

    X_test = X.extract(rowS, -1, 0, -1);
    Y_test = Y.extract(rowS, -1, 0, -1);
}
