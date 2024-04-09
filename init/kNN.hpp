
#include "main.hpp"

template<typename T>
class List {
public:
    virtual ~List() = default;
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(int index) = 0;
    virtual T& get(int index) const = 0;
    virtual int length() const = 0 ;
    virtual void clear() = 0;
    virtual void print() const = 0;
    virtual void reverse() = 0;
    virtual List<T>* CutList_StartToEnd(int start, int end) = 0;
    virtual void Print_List(int start, int end) const = 0; 
};

// Class moi

template<typename T>
class DataMnist : public List<T>
{
private:
    class Node{
    public:
        T pointer;
        Node* next;
    public:
        Node(T pointer, Node* next = nullptr) : pointer(pointer), next(next) {}
    };
private:
    Node* head;
    Node* tail;
    int size;
public:
    DataMnist(){
        head = tail = nullptr;
        size = 0;
    }
    ~DataMnist(){
        this->clear();
    }
    void push_back(T value) {
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void push_front(T value){   
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;  
    }
    void insert(int index, T value) {
        if (index < 0 || index > size) return;

        Node* newNode = new Node(value);
        if (index == 0) {
            if (head == nullptr) { // Danh sách rỗng
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        } else if (index == size) { // Chèn vào cuối danh sách
            newNode->next = nullptr; // Đảm bảo next của node mới là nullptr
            if (head == nullptr) { // Danh sách rỗng
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode; // Cập nhật tail để trỏ đến node mới
            }
        } else { // Chèn vào vị trí bất kỳ
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void remove(int index){
        if(index < 0 || index >= size) return;
        Node* p = head;
        Node* tmp = NULL;
        for ( int i = 0; i<index; i++)
        {
            tmp = p;
            p = p->next;
        }
        if( tmp == NULL) this->head = p->next;
        else if( p == this->tail) {
            this->tail = tmp;
            tmp->next = nullptr;
        }
        else tmp->next = p->next;
        delete p;
        this->size--;
    }

    T& get(int index) const{
        if(index < 0 || index >= this->size)  throw std::out_of_range("get(): Out of range");
        
        Node* current = head;
        for ( int i = 0; i<index; i++ )
        {
            current = current->next;
        } 
        return current->pointer;
    }

    int length() const{
        return size;
    }
    

    void clear(){
        while(head!= nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    void print() const{
        if(size == 0) return;//cout << "nullptr" << endl;
        Node* temp = head;
        for(int i = 0; i < this->size; i++)
        {
            if(i == this->size - 1) cout << temp->pointer;
            else cout << temp->pointer << " ";
            temp = temp->next;
        }
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            // Lưu trữ con trỏ đến node tiếp theo trước khi thay đổi next của current
            nextNode = current->next;
            // Đảo ngược con trỏ next của current để trỏ về prev
            current->next = prev;
            // Di chuyển con trỏ prev, current và nextNode lần lượt sang phải
            prev = current;
            current = nextNode;
        }
        tail = head;
        head = prev;
    }


    void Print_List(int start, int end) const{
        Node* temp = head;
        for (int i = 0; i < start && temp != nullptr; i++) {
            temp = temp->next;
        }
        for(int i = start; i < end && i < this->size; i++)
        {
            if(i == end - 1 || i == this->size - 1) cout << temp->pointer;
            else cout << temp->pointer << " ";
            temp = temp->next;
        }
    } 

    List<T>* CutList_StartToEnd(int start, int end){

        if(this->size <= start) return nullptr;
        List<T>* result = new DataMnist<T>();
        Node* current = this->head;
        for ( int i = 0; i<start && current != NULL; i++ )
        {
            current = current->next;
        }
        for ( int i = start; i < end && current != NULL; i++)
        {
            result->push_back(current->pointer);
            current = current->next;
        }
        return result;
    }


};

template class DataMnist<int>;
template class DataMnist<string>;

class Dataset {
private:
    List<List<int>*>* data;
    List<string>* nameCol;
    //You may need to define more
public:
    Dataset()
    {
        this->nameCol = new DataMnist<string>();
        this->data = new DataMnist<List<int>*>();
    }
    ~Dataset()
    {
        for (int i = 0; i < data->length(); i++)
        {
            data->get(i)->clear();
        }
        for ( int i = 0; i< data->length(); i++)
        {
            delete this->data->get(i);
        }
        delete data;
        delete nameCol;
    }
    

    Dataset(const Dataset &other)
    {
        // Sao chép dữ liệu từ other.data sang data
        
        this->data = new DataMnist<List<int> *>();
        // Kiểm tra xem other.data có rỗng hay không
        if (other.data->length() == 0) {
            // Nếu rỗng, cấp phát nameCol và trả về
            this->nameCol = new DataMnist<string>();
            return;
        }
        // Tìm col bằng cách lấy max(col, other.nameCol->length())
        int col = max(other.nameCol->length(), other.data->get(0)->length());

        // Duyệt qua từng dòng của other.data
        for (int i = 0; i < other.data->length(); i++) {
            // Dùng CutList_StartToEnd để sao chép dữ liệu vào data
            List<int> *newDataList = other.data->get(i)->CutList_StartToEnd(0, col);
            this->data->push_back(newDataList);
        }
        // Gán nameCol bằng nameCol của other
        this->nameCol = other.nameCol->CutList_StartToEnd(0, col);
    }

    Dataset &operator=(const Dataset &other)
    {
        // Kiểm tra xem địa chỉ của other có bằng this không
        if (this == &other)
            return *this;

        // Hủy bỏ các cấp phát trước đó của this
        this->~Dataset();

        // Kiểm tra xem other.data có rỗng không
        if (other.data->length() == 0) {
            // Cấp phát vùng nhớ mới cho data và nameCol
            this->data = new DataMnist<List<int>*>();
            this->nameCol = new DataMnist<string>();
            return *this;
        }
        int row, col;
        other.getShape(row, col); // Lấy số hàng và cột của other.data

        // Cấp phát vùng nhớ cho data
        this->data = new DataMnist<List<int>*>();

        // Sao chép dữ liệu từ other.data sang data
        for (int i = 0; i < row; i++) {
            List<int>* newRow = other.data->get(i)->CutList_StartToEnd(0, col);
            this->data->push_back(newRow);
        }
        // Sao chép nameCol từ other
        this->nameCol = other.nameCol->CutList_StartToEnd(0, col);
        return *this;
    }

    bool loadFromCSV(const char* fileName)
    {   
        ifstream file(fileName);
        if(file.is_open())
        {
            string str;
            int number;
            file >> str;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ',') str[i] = ' ';
            }
            stringstream ss(str);  
            while(ss >> str) nameCol->push_back(str);

            while(file >> str)
            {
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] == ',') str[i] = ' ';
                }
                stringstream ss(str);  
                List<int>* tmp = new DataMnist<int>();
                while(ss >> number) tmp->push_back(number);
                data->push_back(tmp);
            }
            return true;
        }
        return false;
    }
    void getShape(int& nRows, int& nCols) const
    {   
        nRows = data->length();
        nCols = data->length() ? data->get(0)->length() : 0;

    }

    void columns() const
    {
        nameCol->print();
    }
    void printHead(int nRows = 5, int nCols = 5) const
    {
        if(nRows <= 0 || nCols <= 0) return;

    // Lấy số lượng dòng và cột thực tế trong bảng dữ liệu
        int numRows = data->length();
        int numCols = nameCol->length();

        // Đảm bảo nRows và nCols không lớn hơn số lượng dòng và cột thực tế
        if (nRows > numRows) {
            nRows = numRows;
        }
        if (nCols > numCols) {
            nCols = numCols;
        }
        nameCol->Print_List(0, nCols);
        if (numRows != 0) cout << endl;
        for ( int i = 0; i < nRows; i++)
        {
            List<int>* row = data->get(i);
            row->Print_List(0 , nCols);
           if (i != nRows - 1){
             cout << endl;
           }
        }
    }
    void printTail(int nRows = 5, int nCols = 5) const {
        if (nRows <= 0 || nCols <= 0) return;

        // Lấy số lượng dòng và cột thực tế trong bảng dữ liệu
        int numRows = data->length();
        int numCols = nameCol->length();

        // Đảm bảo nRows và nCols không lớn hơn số lượng dòng và cột thực tế
        if (nRows > numRows) {
            nRows = numRows;
        }
        if (nCols > numCols) {
            nCols = numCols;
        }

        // In tên các cột
        nameCol->Print_List(numCols - nCols, numCols);
        if (numRows != 0) cout << endl;
        // In dữ liệu từng dòng
        for (int i = numRows - nRows; i < numRows; i++) {
            List<int>* row = data->get(i);
            row->Print_List(row->length() - nCols, row->length());
            if (i != numRows - 1){
             cout << endl;
           }
        }
    }

    bool drop(int axis = 0, int index = 0, std::string columns = "")
    {
        if( axis != 0 && axis != 1 ) return false;

        if ( axis == 0 )
        {
            if(index < 0 || index >= data->length()) return false;
            data->remove(index);
            return true;
        }
        else {
            int columnIndex = -1;
            for (int i = 0; i < nameCol->length(); ++i) {
                if (nameCol->get(i) == columns) {
                    columnIndex = i;
                    break;
                }
            }
            if (columnIndex == -1) return false; 
            // Xóa cột tại columnIndex
            for (int i = 0; i < data->length(); ++i) {
                List<int>* row = data->get(i);
                row->remove(columnIndex);
            }
            nameCol->remove(columnIndex);
            return true;
        }
    }

    Dataset extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const
    {
        Dataset value;
        if(endRow < -1 || endCol < -1) data->get(-100);
        if((endRow > -1 && startRow > endRow) || (endCol > -1 && startCol > endCol)) data->get(-100);
        int col = (this->data->length() > 0) ? this->data->get(0)->length() : 0;
    
        // Xác định giá trị cuối cùng của endRow và endCol nếu chúng được thiết lập là -1
        if (endCol == - 1 || endCol > this->nameCol->length()) endCol = this->nameCol->length() - 1;
        if (endRow == -1 || endRow > this->data->length()-1) endRow = this->data->length() - 1;
        if (startRow < 0 || startCol < 0 || startRow > endRow || startCol > endCol || startCol > this->nameCol->length() -1 )
        {
            return value;
        }
        // Đảm bảo giá trị endRow và endCol không vượt quá kích thước của nameCol và data
        endCol = min(endCol, col - 1);
        endRow = min(endRow, this->data->length() - 1);
        delete value.nameCol;
        // Sao chép dữ liệu từ nameCol và data của Dataset hiện tại sang Dataset mới
        value.nameCol = this->nameCol->CutList_StartToEnd(startCol, endCol+1);
        //value.nameCol = new DataMnist<string>(*this->nameCol->CutList_StartToEnd(startCol, endCol + 1));
        for (int i = startRow; i <= endRow; i++) {
            value.data->push_back(this->data->get(i)->CutList_StartToEnd(startCol, endCol+1));
        }

        return value;
    }


    // double distanceEuclidean(const List<int>* x, const List<int>* y) const {
    //     double distance = 0.0;

    //     int sizeA = x->length();
    //     int sizeB = y->length();

    //     int maxSize = max(sizeA, sizeB);

    //     // Sử dụng phương thức get(i) để truy cập phần tử ở vị trí i trong List
    //     for (int i = 0; i < maxSize; i++) {
    //         double tmp = 0.0;
            
    //         // Sử dụng phương thức get(i) để truy cập phần tử ở vị trí i trong List
    //         if (i < sizeA && i < sizeB) {
    //             tmp = x->get(i) - y->get(i);
    //         } else if (i < sizeA) {
    //             tmp = x->get(i);
    //         } else if (i < sizeB) {
    //             tmp = y->get(i);
    //         }
            
    //         distance += tmp * tmp;
    //     }
        
    //     return sqrt(distance);
    // }

    double distanceEuclidean(const List<int>* x, const List<int>* y) const {
        double distance = 0.0;
        int sizeA = x->length();
        int sizeB = y->length();

        int maxSize = std::max(sizeA, sizeB);

        // Khai báo và cấp phát mảng động cho các phần tử của List x và y
        int* xArr = new int[maxSize];
        int* yArr = new int[maxSize];

        // Sao chép dữ liệu từ List x và y vào mảng tương ứng
        for (int i = 0; i < maxSize; ++i) {
            xArr[i] = (i < sizeA) ? x->get(i) : 0; // 0 nếu index vượt quá phạm vi của List x
            yArr[i] = (i < sizeB) ? y->get(i) : 0; // 0 nếu index vượt quá phạm vi của List y
        }

        // Tính khoảng cách Euclidean bằng cách duyệt qua mảng và tính toán
        for (int i = 0; i < maxSize; ++i) {
            double tmp = xArr[i] - yArr[i];
            distance += tmp * tmp;
        }
        // Giải phóng bộ nhớ của mảng động
        delete[] xArr;
        delete[] yArr;

        return sqrt(distance);
    }


    List<List<int>*>* getData() const
    {
        return this->data;
    }

    Dataset predict(const Dataset &X_train, const Dataset &Y_train, const int k) const {
    // Khởi tạo một Dataset mới để lưu trữ kết quả dự đoán
        Dataset result;
        if(k > X_train.data->length()) data->get(-100);
        
        if (this->data->length() == 0 || X_train.data->length() == 0 || Y_train.data->length() == 0) return result;
        // Lấy tên cột đầu tiên của Y_train
        string firstColName = Y_train.nameCol->get(0);

        // Thêm tên cột đầu tiên vào result
        result.nameCol->push_back(firstColName);

        // Lấy số hàng của X_train và Y_train
        int numRowsXTrain = X_train.data->length();
        int numRowsXTest = this->data->length();

        // Lặp qua từng hàng trong X_test (this)
        for (int i = 0; i < numRowsXTest; ++i) {
            List<int> *rowXTest = this->data->get(i); // Lấy hàng hiện tại từ X_test

            // Khởi tạo mảng lưu trữ khoảng cách và nhãn tương ứng
            double distances[numRowsXTrain];
            int labels[numRowsXTrain];

            // Lặp qua từng hàng trong X_train
            for (int j = 0; j < numRowsXTrain; ++j) {
                List<int> *rowXTrain = X_train.data->get(j); // Lấy hàng hiện tại từ X_train

                // Tính khoảng cách Euclid giữa hàng hiện tại của X_test và hàng của X_train
                double distance = distanceEuclidean(rowXTest, rowXTrain);

                // Lấy nhãn từ Y_train
                int label = Y_train.data->get(j)->get(0); // Giả sử cột đầu tiên là nhãn

                // Lưu khoảng cách và nhãn vào mảng distances và labels
                distances[j] = distance;
                labels[j] = label;
            }

            // Sắp xếp mảng distances theo khoảng cách tăng dần (sử dụng Bubble Sort)
            for (int m = 0; m < numRowsXTrain - 1; ++m) {
                for (int n = 0; n < numRowsXTrain - m - 1; ++n) {
                    if (distances[n] > distances[n + 1]) {
                        swap(distances[n], distances[n + 1]);
                        swap(labels[n], labels[n + 1]);
                    }
                }
            }

            // Tạo mảng đếm tần suất xuất hiện của mỗi nhãn
            int freq[10] = {0}; // Giả sử có tối đa 10 nhãn

            // Lặp qua k hàng gần nhất (k hàng có khoảng cách nhỏ nhất)
            for (int m = 0; m < k; ++m) {
                int label = labels[m]; // Lấy nhãn của hàng m

                // Tăng tần suất xuất hiện của nhãn lên 1
                ++freq[label];
            }

            // Tìm nhãn có tần suất xuất hiện lớn nhất
            int maxFreqLabel = 0;
            int maxFreq = 0;
            for (int n = 0; n < 10; ++n) { // Giả sử có tối đa 10 nhãn
                if (freq[n] > maxFreq) {
                    maxFreq = freq[n];
                    maxFreqLabel = n;
                }
            }

            // Thêm nhãn có tần suất xuất hiện lớn nhất vào result
            List<int> *newRow = new DataMnist<int>();
            newRow->push_back(static_cast<int>(maxFreqLabel));

            result.data->push_back(newRow);
        }

        return result;
}
   
    
    double score(const Dataset& y_test) const
    {
        // Kiểm tra nếu y_test hoặc this rỗng thì trả về -1
        if (y_test.getData()->length() == 0 || this->data->length() == 0)
            return -1;

        // Kiểm tra nếu số lượng hàng của y_test khác với this thì trả về -1
        if (y_test.getData()->length() != this->data->length())
            return -1;

        int numCorrectPredictions = 0;

        // Lặp qua từng hàng của y_test và so sánh với nhãn dự đoán tương ứng trong this
        for (int i = 0; i < y_test.getData()->length(); ++i)
        {
            // Lấy nhãn thực sự từ y_test
            int trueLabel = y_test.getData()->get(i)->get(0);

            // Lấy nhãn dự đoán từ this
            int predictedLabel = this->data->get(i)->get(0);

            // Nếu nhãn thực sự trùng với nhãn dự đoán, tăng số lượng dự đoán đúng lên 1
            if (trueLabel == predictedLabel)
                numCorrectPredictions++;
        }

        // Tính độ chính xác dựa trên số ảnh dự đoán đúng và tổng số ảnh dự đoán
        double accuracy = static_cast<double>(numCorrectPredictions) / y_test.getData()->length();

        return accuracy;
    }

};

class kNN
{
private:
    int k;
    Dataset X_train;
    Dataset Y_train;
    // You may need to define more
public:
    kNN(int k = 5) : k(k){};
    void fit(const Dataset &X_train, const Dataset &y_train)
    {
        this->X_train = X_train;
        this->Y_train = y_train;
    }
    Dataset predict(const Dataset &X_test)
    {
        return X_test.predict(this->X_train, this->Y_train, this->k);
    }
    double score(const Dataset &y_test, const Dataset &y_pred)
    {
        return y_test.score(y_pred);
    }
};

void train_test_split(Dataset &X, Dataset &Y, double test_size,
                      Dataset &X_train, Dataset &X_test, Dataset &Y_train, Dataset &Y_test);

