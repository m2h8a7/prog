#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

enum Student_Specialization
{
    A_Spec,
    B_Spec,
    C_Spec
};

class Student
{
private:
    string name;
    int kor;
    string neptun_code;
    Student_Specialization spec;
    std::vector<int> marks;
public:
    Student() {}
    Student(string n, int k, string nc)
    {
        name = n;
        kor = k;
        neptun_code = nc;
    }
    Student(string n, int k, string nc, Student_Specialization s,
                std::vector<int> m)
    {
        name = n;
        kor = k;
        neptun_code = nc;
        spec = s;
        marks = m;
    }
    friend istream& operator>>(istream& in, Student &s);
    friend ostream& operator<<(ostream& out, const Student& s);
};

ostream& operator<<(ostream& out, const Student& s)
{
    out << s.name << " " << s.kor << " " << s.neptun_code << endl;
    switch(s.spec){
    case A_Spec:
        out << "A szakirany" << endl;
        break;
    case C_Spec:
        out << "C szakirany" << endl;
        break;
    case B_Spec:
        out << "B szakirany" << endl;
        break;
    }
    out << "Marks: ";
    for(int i = 0; i < s.marks.size(); ++i) {
        out << s.marks[i] << " ";
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, Student &s)
{
    string temp;
    getline(in,temp);
    //temp == Én 22 YTHSTN A 2 2 2 4 5 5 4 3
    stringstream ss;
    ss << temp;
    //ss == Én 22 YTHSTN A 2 2 2 4 5 5 4 3
    ss >> s.name;
    ss >> s.kor;
    ss >> s.neptun_code;
    char temp_spec;
    ss >> temp_spec;
    switch(temp_spec) {
    case 'A':
        s.spec = A_Spec;
        break;
    case 'B':
        s.spec = B_Spec;
        break;
    case 'C':
        s.spec = C_Spec;
        break;
    }
    int temp_mark;
    s.marks.clear();
    while(ss >> temp_mark) {
        s.marks.push_back(temp_mark);
    }
    return in;
}

template<typename T>
istream& operator>>(istream& in, std::vector<T>& v)
{
    /*
    //Adott a méret
    string temp;
    getline(in,temp);
    stringstream ss;
    ss << temp;
    int _size;
    ss >> _size;
    for(int i = 0; i < _size; ++i)
    {
        T temp;
        in >> temp;
        v.push_back(temp);
    }
    return in;*/
    T temp;
    in >> temp;
    while(in.good())
    {
        v.push_back(temp);
        in >> temp;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, std::vector<T>& v)
{
    out << v.size() << endl;
    for(int i = 0; i < v.size(); ++i)
    {
        out << v[i] << endl;
    }
    return out;
}

int main()
{
    /*Student MML("Én", 22, "YTHSTN");
    Student MML2;
    fstream fin("input.txt");
    fin >> MML2;
    cout << MML2;*/
    std::vector<Student> classR;
    fstream fin("input.txt");
    fin >> classR;
    cout << classR;
    return 0;
}
