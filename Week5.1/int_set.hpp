#include <array>
#include <ostream>


class int_set{
private:
    std::array<int,10> set = {};
    unsigned int size = 0;

    int get_pos(int x){
        for(unsigned int i=0; i<size; i++){
            if(set[i]==x){
                return i;
            }
        }
        return -1;
    }


public:

    void add(int x){
        if(size < set.size()){
            if(!contains(x)){
                set[size] = x;
                size++;
            }
        }
    }

    void remove(int x){
        int pos = get_pos(x);
        if(pos < 0){
            return;
        }
        set[pos]=set[--size];
    }

    bool contains(int x){
        if(get_pos(x) > -1){
            return true;
        }
        return false;
    }

    friend std::ostream &operator<<(std::ostream& o, const int_set & s){
        for(int i : s.set){
            o << i << " ";
        }
        return o;
    }
};