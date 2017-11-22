#include <iostream>
#include <cstdlib>

class Myclass{
    private:
        int* m_arr;
    public:
        int N;
        Myclass(){
            std::cout<<"Entered size of array:";
            std::cin >>N;
            m_arr = new int[N];
        }
        void initialize_array(){
            for(int i = 0;i < N; ++i){
               m_arr[i] = rand() % 50; 
            }
        }
        void print_values() {
            for(int i = 0;i < N; ++i) {
                std::cout << m_arr[i] << std::endl;
            }
        }
        ~Myclass(){
            std::cout<<"I am Myclass destructor "<< std::endl;
            delete[] m_arr;
        }
};

//class for smart ponter
template <class Type>
class Smart_pointer {
    private:
        Type* pointer;
    public: 
        Smart_pointer(Type* pM):pointer(pM){
            std::cout<<"I am Smart_pointer constructor"<< std::endl;
            };
        Type& operator*(){
            return *pointer;
        };
        Type* operator->(){
            return pointer;
        }
        ~Smart_pointer(){
            std::cout<<"I am Smart_pointer destructor " << std::endl;
            delete pointer;
        }
                
        
};
int main() { 
    
    Smart_pointer<Myclass> sp(new Myclass());
    sp->initialize_array();
    sp->print_values();
    
    return 0;
}






