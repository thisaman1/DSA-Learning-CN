class dynamicArray {

    int *data;
    int capacity;
    int nextIndex;

    public:

    dynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    dynamicArray(dynamicArray const &d){                //copy constructor
        //deep copy
        this->data = new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }

    void operator=(dynamicArray const &d){               //copy assignment operator
        this->data = new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }


    void add(int element){
        if(nextIndex == capacity){
            int *newdata = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete []data;
            data = newdata;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int get(int i){
        if(i<nextIndex){
            return data[i];
        }
        else
            return -1;
    }

    void add(int i,int element){
        if(i<nextIndex){
            data[i] = element;
        }
        else if(i==nextIndex){
            add(element);
        }
        else
            return;
    }


};