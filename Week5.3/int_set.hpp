#include <array>
#include <string>
#include <ostream>

bool operator<( const std::array<char,3> & lhs, const std::array<char,3> & rhs){
        int som_lhs = 0;
        int som_rhs = 0;
        for(unsigned int i=0; i<3; i++){
            som_lhs += lhs[i];
            som_rhs += rhs[i]; 
        }
        return (som_lhs < som_rhs);
    }


template <typename T1, int max_size>
class setOfThings{
private:
    std::array<T1,max_size> set = {};
    unsigned int size = 0;

    int get_pos(T1 x){
        for(unsigned int i=0; i<size; i++){
            if(set[i]==x){
                return i;
            }
        }
        return -1;
    }


public:

    void add(T1 x){
        if(size < set.size()){
            if(!contains(x)){
                set[size] = x;
                size++;
            }
        }
    }

    void remove(T1 x){
        int pos = get_pos(x);
        if(pos < 0){
            return;
        }
        set[pos]=set[--size];
    }

    bool contains(T1 x){
        if(get_pos(x) > -1){
            return true;
        }
        return false;
    }

    friend std::ostream &operator<<(std::ostream& o, const setOfThings<T1, max_size> & s){
        for(unsigned int i=0;i<s.size;i++){
            o << s.set[i] << " ";
        }
        return o;
    }

    T1 max(){
        if(size>0){
            T1 highest_yet = set[0];
            for(unsigned int i=0; i<size; i++){
                if(highest_yet < set[i]){
                    highest_yet = set[i];
                }
            }
            return highest_yet;
        }
        exit(69);
    }
};