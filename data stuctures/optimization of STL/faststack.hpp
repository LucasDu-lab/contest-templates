template<typename T>
class fastStack{
    private:
    vector<T>stk;
    public:
    fastStack(int sz){
        stk.resize(sz);
    }
    fastStack(){}
    void push(T val){
        stk.push_back(val);
    }
    void pop(){
        if(!stk.empty()) stk.pop_back();
        else throw std::runtime_error("Segmentation fault, stack is empty");
    }
    int size(){ return stk.size(); }
    T top(){
        if(!stk.empty()) return stk.back();
        else throw std::runtime_error("Segmentation fault, stack is empty");
    }
    bool empty(){ return stk.empty(); }
};