#include "./std_lib_facilities.h"


template<typename T> 
struct S
{           
    S(T vv) : val{vv} { };
    T& get();
    const T& get() const;
    T& operator=(const T& vv);
//    void set(T vv);

    private:
    T val;
};

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

/*template<typename T>
void S<T>::set(T vv)
{
    val = vv;   
}*/

template<typename T>
T& S<T>::operator=(const T& vv)
{
    val = vv;
    return val;
}

template<typename T>
istream& operator>>(istream& is, S<T>& vv)
{
    T v;
    cin >> v;
    if (!is) return is;
    vv = v;
    return is;
}

template<typename T>
void read_val(T& v)
{    
    cin >> v;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}";
    return os;
}

//template<typename Tx>
//ostream& operator<<(ostream& os, vector<T>& v)

int main()
{
    S<int> ints = 1;
    S<char> chars = 'a';
    S<double> doubles = 23.233;
    S<string> strings {"Ember"};
    S<vector<int>> vectors {vector<int>{1,2,3}};
   
    strings = "lehetséges";
    //doubles.set(22.7);

    cout << ints.get() << "\n";
    cout << chars.get() << "\n";
    cout << doubles.get() << "\n";
    cout << strings.get() << "\n";
/*    for(int i=0; i<vectors.get().size(); i++)
    {
        cout << vectors.get()[i] << ' ';
    }
    cout << "\n";*/
    cout << vectors.get() << "\n\n";

    read_val(ints);
    cout << ints.get() << "\n";
    read_val(chars);
    cout << chars.get() << "\n";
    read_val(doubles);
    cout << doubles.get() << "\n";
    read_val(strings);
    cout << strings.get() << "\n";
    read_val(vectors);
    cout << vectors.get() << "\n";

    return 0;
}
