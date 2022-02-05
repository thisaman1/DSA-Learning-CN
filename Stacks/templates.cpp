template<typename T>
class pair1{                //both properties of same type
    T x;
    T y;

    public:
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
    
    void setY(T y){
        this ->y = y;
    }
    T getY(){
        return y;
    }
};


template<typename T,typename V>
class pair2{                    //both properties are declared using diffent type 
                                //and both can be same or different data type according to user need
    T x;
    V y;

    public:
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
                                //for creating three different type of properties using templates we can't use template
                                //we will create a object in main of type pair2<pair2<int,char>,float> p5;
    void setY(V y){
        this->y = y;
    }
    V getY(){
        return y;
    }
};




