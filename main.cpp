#include <iostream>
struct Box{
private:
    int length;
    int width;
    int height;
    double weight;
    int value;
public:
    Box(int length, int width, int height, double weight, int value){
        this->length = length;
        this->width = width;
        this->height = height;
        this->weight = weight;
        this->value = value;
    }
public :
    static int sumValue(Box array[], int size){
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += array[i].getValue();

        }
        return sum;
    }
public:
    static bool checkSumValue(Box array[],int size, int value){
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += array[i].getLength() + array[i].getHeight() + array[i].getWidth();
        }
        if(value > sum) return true;
        else return false;
    }
public:
    static int maxVolume(Box array[],int size, int maxV){
        int maxWeight = 0;
        for(int i = 0; i < size; i++){
            if(maxV > array[i].getLength() * array[i].getHeight() * array[i].getWidth())
                maxWeight += array[i].getWeight();
        }
        return maxWeight;
    }
public:
    static bool emptyBoxes(Box array[],int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(array[i + 1].getLength() < array[i].getLength() && array[i+1].getHeight() < array[i].getHeight() && array[i+1].getWidth() < array[i].getWidth()){
                    std::swap(array[j], array[j+1]);
                }
            }
        }
        
    }

    int getLength() const;

    int getValue() const;

    int getWidth() const;

    int getHeight() const;

    double getWeight() const;

};
int Box::getValue() const {
    return value;
}

int Box::getLength() const {
    return length;
}

int Box::getWidth() const {
    return width;
}

int Box::getHeight() const {
    return height;
}

double Box::getWeight() const {
    return weight;
}

int main() {
    Box box1(5, 4, 3, 6, 10);
    Box box2(3, 5, 2, 6, 9);
    Box box3(11, 4, 3, 10, 15);
    Box array[] = {box1, box2, box3};
    
    std::cout << "Total cost of all boxes is " << (Box::sumValue(array, 2)) << "\n";
    if(Box::checkSumValue(array, 3, 20))
        std::cout << "Sum of the length, width and height of all boxes doesn't exceed the value\n";
    else
        std::cout << "Sum of the length, width and height of all boxes exceed the value\n";
    std::cout << "Max weight of all boxes: " << Box::maxVolume(array, 3, 50) << "\n";
    Box::emptyBoxes(array, 3);

}


