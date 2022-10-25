#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_

#include <iostream>
#include <fstream>

namespace sdds {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);

    public:
        Numbers();
        Numbers(const Numbers& num);
        Numbers(const char* filename);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();
        //sorting function
        Numbers& sort(bool ascending);
        //operator overloading
        Numbers& operator=(const Numbers& num);
        Numbers operator-()const;
        Numbers operator+()const;
        Numbers& operator+=(double num);
        //return the number of data present in the file
        int numberCount()const;
        //load data from the file
        bool load();
        //save the data in the file
        void save();
        //Display function
        //std::ostream& display(std::ostream& ostr) const;

        //helper function overloads
        friend ostream& operator<<(ostream& os, const Numbers& N);
        friend istream& operator>>(istream& is, Numbers& N);
    };


    ostream& operator<<(ostream& os, const Numbers& N)
    {
        return os << "test";
    }

    istream& operator>>(istream& istr, Numbers& N) {
        double localDouble;
        if (istr >> localDouble)
            N += localDouble;

        return istr;
    }

}



#endif // !SDDS_NUMBERS_H_

